import re

def extract_labels_and_words(data):
    pattern = re.compile(r'\((\d+) ([^\(\)]+)\)')
    matches = pattern.findall(data)
    return [(int(label), word.lower()) for label, word in matches]

def remove_duplicates(pairs):
    seen = set()
    unique_pairs = []
    for label, word in pairs:
        if word not in seen:
            unique_pairs.append((label, word))
            seen.add(word)
    return unique_pairs

def process_datasets(input_files, output_file):
    all_pairs = []
    for input_file in input_files:
        with open(input_file, 'r') as infile:
            data = infile.readlines()
        for line in data:
            pairs = extract_labels_and_words(line.strip())
            all_pairs.extend(pairs)
    
    unique_pairs = remove_duplicates(all_pairs)
    
    with open(output_file, 'w') as outfile:
        for label, word in unique_pairs:
            outfile.write(f"{label}\t{word}\n")

input_files = ['datasets/rotten/dev.sentiment.txt',
               'datasets/rotten/test.sentiment.txt',
               'datasets/rotten/train.sentiment.txt'] 

output_file = 'datasets/rotten/vocabulary.txt'  # Replace with the desired output file path
process_datasets(input_files, output_file)
