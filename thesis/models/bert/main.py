from model import SentimentClassifier
import torch

def read_data_from_file(file_name):
    sentences = []
    labels = []
    with open(file_name, 'r', encoding='utf-8') as file:
        for line in file:
            parts = line.strip().split('\t')
            label = int(parts[0])
            sentence = parts[1]
            labels.append(label)
            sentences.append(sentence)
    return sentences, labels

# Example usage:
# Assuming train_sentences, train_labels, dev_sentences, dev_labels, test_sentences, and test_labels are predefined lists

train_sentences, train_labels = read_data_from_file('data/train.txt')
dev_sentences, dev_labels = read_data_from_file('data/dev.txt')
test_sentences, test_labels = read_data_from_file('data/test.txt')

classifier = SentimentClassifier()
classifier.train(train_sentences, train_labels, dev_sentences, dev_labels, epochs=3)
test_accuracy = classifier.evaluate(test_sentences, test_labels)
print(f"Test Accuracy: {test_accuracy}")

model_save_path = 'bert_base.pth'
torch.save(classifier.model.state_dict(), model_save_path)
