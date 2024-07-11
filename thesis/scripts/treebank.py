from nltk import Tree
import re
import copy

def next_is_leaf(tree):
    for subtree in tree:
        if isinstance(subtree, str):
            return True
    return False

def tree_to_string(tree):
    if next_is_leaf(tree):
        return f'({tree.label()} {tree[0]})'
    else:
        return f'({tree.label()} ' + ''.join([tree_to_string(subtree) for subtree in tree]) + ')'

class Pattern:
    def __init__(self, sentiment, trees):
        self.sentiment = sentiment
        self.trees = trees

    def to_string(self):
        trees = ' |BT| '.join([tree_to_string(tree) for tree in self.trees])
        return f'{self.sentiment} |BT| {trees}|ET|'

    @staticmethod
    def from_string(string):
        match = re.match(r"(\d) \|BT\| (.*)\|ET\|", string)
        if match:
            sentiment = int(match.group(1))
            trees = [Tree.fromstring(tree) for tree in match.group(2).split(' |BT| ')]
            return Pattern(sentiment, trees)
        else:
            raise ValueError(f'Invalid string: {string}')

    def set_sentiment(self, sentiment):
        self.sentiment = sentiment

    def sentiment(self):
        return self.sentiment

    def is_leaf(self):
        for subtree in self.trees[0]:
            if isinstance(subtree, str):
                return True
        return False

    def subtrees(self):
        tb = Treebank()
        if self.is_leaf():
            return tb
        for tree in self.trees[0]:
            nt = Pattern(tree.label(), [copy.deepcopy(tree)])
            tb.merge(nt.subtrees())
        tb.append(self)
        return tb

class Treebank:
    def __init__(self):
        self.Trees = []

    @staticmethod
    def from_file(name):
        tb = Treebank()
        with open(f'datasets/{name}.txt') as f:
            for line in f:
                tb.append(Pattern.from_string(line))
        print(f'Loaded {len(tb)} patterns from {name}.txt')
        return tb

    def to_string(self):
        result = []
        for pattern in self.Trees:
            result.append(pattern.to_string())
        return '\n'.join(result)

    def map(self, function):
        for tree in self.Trees:
            function(tree)

    def append(self, tree):
        self.Trees.append(tree)

    def extend(self, trees: list[Pattern]):
        self.Trees.extend(trees)

    def merge(self, aux):
        self.Trees.extend(aux.Trees)

    def __getitem__(self, index):
        return self.Trees[index]

    def __len__(self):
        return len(self.Trees)
