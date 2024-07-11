import re
from nltk import Tree

def next_is_leaf(tree):
    for subtree in tree:
        if isinstance(subtree, str):
            return True
    return False

def clean_tree(tree):
    if next_is_leaf(tree):
        match = re.match(r"(\d)-(.*)", tree.label())
        if match:
            tree.set_label(match.group(2))
    else:
        for subtree in tree:
            clean_tree(subtree)

def tree_to_string(tree):
    if next_is_leaf(tree):
        return f'({tree.label()} {tree[0]})'
    else:
        return f'({tree.label()} ' + ''.join([tree_to_string(subtree) for subtree in tree]) + ')'

result = []
filename = "dev"

with open(f'../datasets/{filename}.svmlight.txt') as f:
    for line in f:
        line.strip()

        # Extract the synctactic structure
        match = re.match(r"(\d) \|BT\| (.*)\|ET\|", line)
        if match:
            sentiment = int(match.group(1))
            tree = Tree.fromstring(match.group(2))
            clean_tree(tree)
        else:
            raise ValueError(f'Invalid line: {line}')

        result.append(f'{sentiment} |BT| {tree_to_string(tree)}|ET|')

with open(f'../datasets/{filename}.syntactic.txt', 'w') as f:
    f.write('\n'.join(result))
