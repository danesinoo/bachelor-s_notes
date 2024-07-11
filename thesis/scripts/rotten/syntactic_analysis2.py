import nltk
from nltk.parse.corenlp import CoreNLPParser
from nltk import Tree

# Set up the parser (ensure Stanford CoreNLP server is running)
parser = CoreNLPParser(url='http://localhost:9000')

tree_input = """(3 (2 (2 The) (2 Rock)) (4 (3 (2 is) (4 (2 destined) (2 (2 (2 (2 (2 to) (2 (2 be) (2 (2 the) (2 (2 21st) (2 (2 (2 Century) (2 's)) (2 (3 new) (2 (2 ``) (2 Conan)))))))) (2 '')) (2 and)) (3 (2 that) (3 (2 he) (3 (2 's) (3 (2 going) (3 (2 to) (4 (3 (2 make) (3 (3 (2 a) (3 splash)) (2 (2 even) (3 greater)))) (2 (2 than) (2 (2 (2 (2 (1 (2 Arnold) (2 Schwarzenegger)) (2 ,)) (2 (2 Jean-Claud) (2 (2 Van) (2 Damme)))) (2 or)) (2 (2 Steven) (2 Segal))))))))))))) (2 .)))"""

def extract_words_and_labels(tree):
    if next_is_leaf(tree):
        return [(tree.label(), tree[0])]
    else:
        res = []
        for subtree in tree:
            res.extend(extract_words_and_labels(subtree))
        return res

def next_is_leaf(tree):
    for subtree in tree:
        if isinstance(subtree, str):
            return True
    return False

# Function to combine syntactic structure with sentiment labels
def combine_trees(syntax_tree, words_and_labels):
    if next_is_leaf(syntax_tree):
        index = next((i for i, element in enumerate(words_and_labels) if element[1] == syntax_tree[0]), -1)

        if index == -1:
            return syntax_tree

        sentiment_label, _ = words_and_labels.pop(index)
        return Tree(sentiment_label + '-' + syntax_tree.label(), [syntax_tree[0]])

    else:
        return Tree(syntax_tree.label(), [combine_trees(subtree, words_and_labels) for
                                          subtree in syntax_tree])

def tree_to_string(tree):
    if next_is_leaf(tree):
        return f'({tree.label()} {tree[0]})'
    else:
        return f'({tree.label()} ' + ''.join([tree_to_string(subtree) for subtree in tree]) + ')'

def penn_to_svmlight(line):
    words_and_labels = extract_words_and_labels(Tree.fromstring(line))
    sentence = ' '.join([word for _, word in words_and_labels])

    # Parse the sentence
    parse_tree = next(parser.raw_parse(sentence))

    # Combine the syntactic parse tree with the sentiment labels
    combined_tree = combine_trees(parse_tree, words_and_labels)

    target = line[1]

    return f'{target} |BT| {tree_to_string(combined_tree)}|ET|'

result = ''

with open('dev.txt', 'r') as file:
    dataset = file.readlines()
    for line in dataset:
        result += penn_to_svmlight(line) + '\n'

with open('dev.svmlight.txt', 'w') as file:
    file.write(result)


