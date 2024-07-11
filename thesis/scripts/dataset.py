import treebank
import copy

def append_to(lst, index, tree):
    tree.set_sentiment(-1)
    for i in range(len(lst)):
        if i == index:
            tree.set_sentiment(1)
            lst[i].append(copy.deepcopy(tree))
            tree.set_sentiment(-1)
        else:
            lst[i].append(tree)
        
def multiclass(tree):
    append_to(mc, tree.sentiment, tree)

def binary(tree):
    if tree.sentiment < 2:
        tree.set_sentiment(-1)
        bc.append(tree)
    elif tree.sentiment > 2:
        tree.set_sentiment(1)
        bc.append(tree)

def regression(tree):
    sentiment = tree.sentiment
    sentiment = (sentiment - 2) / 2
    tree.set_sentiment(sentiment)

# datasets = [
#          'dev.sentiment', 'dev.syntax', 'dev.merged',
#          'test.sentiment', 'test.syntax', 'test.merged',
#          'train.sentiment', 'train.syntax', 'train.merged',
#         ]

datasets = [ 'test.sentiment' ]

# datasets = [
#         'subtree_dev.sentiment',
#         'subtree_test.sentiment',
#         'subtree_train.sentiment',
#         ]

for dataset in datasets:
    tb = treebank.Treebank.from_file(f'{dataset}')
    # mc = [
    #     treebank.Treebank(),
    #     treebank.Treebank(),
    #     treebank.Treebank(),
    #     treebank.Treebank(),
    #     treebank.Treebank(),
    # ]
    # tb_mod = copy.deepcopy(tb)
    # tb_mod.map(multiclass)
    # for i, t in enumerate(mc):
    #     with open(f'datasets/multiclass_{dataset}_{i}.txt', 'w') as f:
    #         f.write(t.to_string())

    # bc = treebank.Treebank()
    # tb_mod = copy.deepcopy(tb)
    # tb_mod.map(binary)
    # with open(f'datasets/binary_{dataset}.txt', 'w') as f:
    #     f.write(bc.to_string())

    # tb_mod = copy.deepcopy(tb)
    # tb_mod.map(regression)
    # with open(f'datasets/regression_{dataset}.txt', 'w') as f:
    #     f.write(tb_mod.to_string())

    st = treebank.Treebank()
    tb_mod = copy.deepcopy(tb)
    tb_mod.map(lambda x: st.merge(x.subtrees()))
    with open(f'datasets/subtree_{dataset}.txt', 'w') as f:
        f.write(st.to_string())
    del tb
    print(f'Finished processing {dataset}')
