import treebank

def merge_datasets(db):
    merged = treebank.Treebank()
    for i, (x, y) in enumerate(zip(db[0], db[1])):
        merged.append(treebank.Pattern(x.sentiment, x.trees + y.trees))
        print(f'Merged {i + 1}/{len(db[0])} patterns', end='\r')

    return merged

datasets = ['dev', 'test', 'train']

for dataset in datasets:
    tb_sentiment = treebank.Treebank.from_file(f'{dataset}.sentiment')
    tb_syntax = treebank.Treebank.from_file(f'{dataset}.syntax')

    print(f'Merging {dataset} datasets...')

    tb = merge_datasets([tb_sentiment, tb_syntax])

    with open(f'datasets/{dataset}_merged.txt', 'w') as f:
        f.write(tb.to_string())
