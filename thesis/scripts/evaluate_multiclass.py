import os
import re

def has_number(s):
    return any(char.isdigit() for char in s)

def foldl(func, acc, xs):
    for x in xs:
        acc = func(acc, x)
    return acc


def split_models(acc, entry):
    print(entry)
    if 'subtree' in entry:
        acc[0].append(entry)
    elif 'merged' in entry:
        acc[1].append(entry)
    elif 'sentiment' in entry:
        acc[2].append(entry)
    else:
        acc[3].append(entry)
    return acc

def softmax(x):
    largest = max(x)
    return x.index(largest)



if __name__ == "__main__":
    directory = 'models/kernels/predictions'
    entries = os.listdir(directory)
    entries = [entry for entry in entries if entry.startswith('multiclass') and has_number(entry)]

    label_entries = list(filter(lambda x: 'label' in x, entries))
    root_entries = list(filter(lambda x: 'root' in x, entries))

    models_predictions = [[], [], [], [], [], [], [], []]
    foldl(split_models, models_predictions[:4], label_entries)
    foldl(split_models, models_predictions[4:], root_entries)
    models_predictions = list(map(lambda x: sorted(x), models_predictions))
    for m in models_predictions:
        predictions = [[], [], [], [], []]
        for i, p in enumerate(m):
            with open(f'{directory}/{p}') as f:
                predictions[i] = list(map(lambda line: float(line),
                                          f.readlines()))
        prediction = list(map(softmax, zip(*predictions)))

        base_file_name = re.sub(r'_\d+', '', m[0])
        base_file_name = re.sub(r'multiclass_', '', base_file_name)
        with open(f'{directory}/{base_file_name}', 'w') as f:
            f.write('\n'.join(map(str, prediction)))



