def count_labels(filename):
    """
    Reads a file and counts the number of examples for each label (0 to 4).
    
    Args:
        filename (str): The name of the file to read.
    
    Returns:
        dict: A dictionary with labels as keys and counts as values.
    """
    label_counts = {0: 0, 1: 0, 2: 0, 3: 0, 4: 0}
    
    with open(filename, 'r') as file:
        for line in file:
            line = line.strip()
            if line:
                label = int(line.split('|')[0])
                if label in label_counts:
                    label_counts[label] += 1

    return label_counts

train = count_labels('datasets/train.sentiment.txt')
dev = count_labels('datasets/dev.sentiment.txt')
test = count_labels('datasets/test.sentiment.txt')

def print_counts(count):
    return ', '.join(list(map(lambda x: f'{x[1]}', count.items())))


res = print_counts(train)
res += '\n' + print_counts(dev)
res += '\n' + print_counts(test)

print(res)

with open('label-distribution.txt', 'w') as file:
    file.write(res)
