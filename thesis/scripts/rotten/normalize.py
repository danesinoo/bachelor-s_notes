import re

result = ''

with open('datasets/train_svm.txt') as f:
    for line in f:
        match = re.match(r'(\d) (.*)', line)
        if match:
            target = match.group(1)
            target = float(int(target) - 2) / 2
            if target > 0:
                target = f'+{target}'

            tree = match.group(2)
            result += f'{target} {tree}\n'
        else:
            print('Error:', line)

with open('datasets/train_svm_normalized.txt', 'w') as f:
    f.write(result)
