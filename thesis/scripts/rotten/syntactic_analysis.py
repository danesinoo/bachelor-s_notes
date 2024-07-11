import re
import functools
import nltk

class Tree:
    children = []
    sentiment = None
    value = None

    def __init__(self, sentiment, children, value = None):
        self.sentiment = sentiment
        self.children = children
        self.value = value

    def __str__(self):
        if not self.children:
            return f'({self.sentiment} {self.value})'
        else:
            children_str = ' '.join(str(child) for child in self.children)
            return f'({self.sentiment} {children_str})'

    def parse_tree(self, s):
        match = re.match(r'\((\d) (.*)\)', s)
        if match:
            sentiment = match.group(1)
            if (not self.subtree(match.group(2))):
                return Tree(sentiment, [], match.group(2))
            else:
                children = self.parse_tree_forest(match.group(2))
                return Tree(sentiment, children)
        else:
            raise ValueError('Invalid tree format')

    def subtree(self, s):
        """
        Return a list of tuple [(begin, end), ...] for each subtree,
        where begin is the index of the first character of the subtree,
        and end is the index of the last character of the subtree
        """
        stack = []
        subtrees = []
        begin = 0

        for i, char in enumerate(s):
            if char == '(':
                if not stack:
                    begin = i
                stack.append(char)
            elif char == ')':
                stack.pop()
                if not stack:
                    subtrees.append((begin, i+1))

        return subtrees

    def parse_tree_forest(self, s):
        children = []
        for begin, end in self.subtree(s):
            child_str = s[begin:end]
            child = self.parse_tree(child_str)
            children.append(child)
        return children

    def tokenize(self):
        if self.value:
            return [self.value]
        else:
            return functools.reduce(lambda x, y: x + y, [child.tokenize() for
                                                         child in
                                                         self.children])

    def iter_leaf(self, fn):
        if not self.children:
            fn(self)
        else:
            for child in self.children:
                child.iter_leaf(fn)

    def pos_tag(self):
        pos_tagged = nltk.pos_tag(self.tokenize())

        def assign_pos_tag(leaf):
            leaf.value = pos_tagged.pop(0)

        self.iter_leaf(assign_pos_tag)
        return self

    def tagged_tree_to_string(self):
        if not self.children and self.value:
            return f'({self.sentiment}-{self.value[1]} {self.value[0]})', []
        else:
            children_str = ''
            sub_tree = []
            for child in self.children:
                child_str, sub_trees = child.tagged_tree_to_string()
                children_str += child_str
                sub_tree.extend(sub_trees)
            tree_str = f'({self.sentiment} {children_str})'
            sub_tree.append(f'{self.sentiment} |BT| (* {children_str})|ET|')
            return tree_str, sub_tree

result = ''

with open('dev.txt', 'r') as file:
    dataset = file.readlines()
    for line in dataset:
        tree_parser = Tree(None, [])
        parsed_tree = tree_parser.parse_tree(line)
        parsed_tree.tokenize()
        parsed_tree.pos_tag()
        _, sub_trees = parsed_tree.tagged_tree_to_string()
        result += '\n'.join(sub_trees) + '\n'

with open('dev.svmlight.txt', 'w') as file:
    file.write(result)
