import re

result = ''
filename = 'dev'

with open(f'../datasets/{filename}.sentiment.txt') as f:
    train = f.readlines()
    for line in train:
        match = re.match(r'\((\d+) (.*)\)', line)
        if match:
            sentiment = match.group(1)
            tree = match.group(2)
            tree = tree.replace(') (', ')(')
            result += f'{sentiment} |BT| (ROOT {tree})|ET|\n'

with open(f'../datasets/{filename}.txt', 'w') as f:
    f.write(result)
