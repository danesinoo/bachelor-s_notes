import random

def split_dataset(input_file, train_file, dev_file, test_file, train_ratio=0.7, dev_ratio=0.1, test_ratio=0.2):
    # Read the data from the input file
    with open(input_file, 'r') as infile:
        lines = infile.readlines()
    
    # Shuffle the lines randomly
    random.shuffle(lines)
    
    # Calculate the split indices
    total_lines = len(lines)
    train_end = int(total_lines * train_ratio)
    dev_end = train_end + int(total_lines * dev_ratio)
    
    # Split the data
    train_lines = lines[:train_end]
    dev_lines = lines[train_end:dev_end]
    test_lines = lines[dev_end:]
    
    # Write the split data to the respective files
    with open(train_file, 'w') as train_outfile:
        train_outfile.writelines(train_lines)
    
    with open(dev_file, 'w') as dev_outfile:
        dev_outfile.writelines(dev_lines)
    
    with open(test_file, 'w') as test_outfile:
        test_outfile.writelines(test_lines)

# Example usage
input_file = 'datasets/rotten/vocabulary.txt'  # Replace with the desired output file path
train_file = 'datasets/rotten/train_vocabulary.txt'   # Replace with the desired train file path
dev_file = 'datasets/rotten/dev_vocabulary.txt'       # Replace with the desired dev file path
test_file = 'datasets/rotten/test_vocabulary.txt'     # Replace with the desired test file path

split_dataset(input_file, train_file, dev_file, test_file)

