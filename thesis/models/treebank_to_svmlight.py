import re

result = ''

with open('datasets/test.txt') as f:
    train = f.readlines()
    for line in train:
        match = re.match(r'\((\d+) (.*)\)', line)
        if match:
            sentiment = match.group(1)
            tree = match.group(2)
            tree = tree.replace(') (', ')(')
            result += f'{sentiment} |BT| (* {tree})|ET|\n'

with open('datasets/test_svm.txt', 'w') as f:
    f.write(result)


