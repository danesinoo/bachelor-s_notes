import torch
from torch.utils.data import DataLoader, TensorDataset
from transformers import BertTokenizer, BertForSequenceClassification, AdamW
from sklearn.metrics import accuracy_score
import time

class SentimentClassifier:
    def __init__(self, model_name='bert-base-uncased', num_labels=5, lr=2e-5, batch_size=16):
        self.tokenizer = BertTokenizer.from_pretrained(model_name)
        self.model = BertForSequenceClassification.from_pretrained(model_name, num_labels=num_labels)
        self.optimizer = AdamW(self.model.parameters(), lr=lr)
        self.batch_size = batch_size
    
    def preprocess_data(self, sentences, labels):
        inputs = self.tokenizer(sentences, return_tensors='pt', max_length=512, truncation=True, padding=True)
        labels = torch.tensor(labels)
        dataset = TensorDataset(inputs['input_ids'], inputs['attention_mask'], labels)
        return dataset

    def train(self, train_sentences, train_labels, dev_sentences, dev_labels, epochs=3):
        train_dataset = self.preprocess_data(train_sentences, train_labels)
        dev_dataset = self.preprocess_data(dev_sentences, dev_labels)
        
        train_dataloader = DataLoader(train_dataset, batch_size=self.batch_size, shuffle=True)
        dev_dataloader = DataLoader(dev_dataset, batch_size=self.batch_size)

        for epoch in range(epochs):
            start_time = time.time()  # Start time measurement
            
            self.model.train()
            total_loss = 0
            for batch in train_dataloader:
                b_input_ids, b_attention_mask, b_labels = batch
                self.model.zero_grad()
                outputs = self.model(b_input_ids, attention_mask=b_attention_mask, labels=b_labels)
                loss = outputs.loss
                total_loss += loss.item()
                loss.backward()
                self.optimizer.step()
            avg_train_loss = total_loss / len(train_dataloader)
            print(f"Epoch {epoch + 1}, Loss: {avg_train_loss}")

            # Evaluation on dev set
            avg_dev_accuracy = self.evaluate(dev_sentences, dev_labels)
            print(f"Epoch {epoch + 1}, Dev Accuracy: {avg_dev_accuracy}")

            end_time = time.time()  # End time measurement
            print(f"Epoch {epoch + 1} training time: {end_time - start_time:.2f} seconds")

    def evaluate(self, sentences, labels):
        dataset = self.preprocess_data(sentences, labels)
        dataloader = DataLoader(dataset, batch_size=self.batch_size)
        
        self.model.eval()
        accuracy = 0
        for batch in dataloader:
            b_input_ids, b_attention_mask, b_labels = batch
            with torch.no_grad():
                outputs = self.model(b_input_ids, attention_mask=b_attention_mask)
            logits = outputs.logits
            preds = torch.argmax(logits, dim=1)
            accuracy += accuracy_score(b_labels.numpy(), preds.numpy())
        avg_accuracy = accuracy / len(dataloader)
        return avg_accuracy
    
    def save_model(self, path):
        """Save the fine-tuned model."""
        torch.save(self.model.state_dict(), path)
        print(f"Model saved to {path}")
    
    def load_model(self, path):
        """Load the fine-tuned model."""
        self.model.load_state_dict(torch.load(path))
        self.model.eval()  # Set the model to evaluation mode
        print(f"Model loaded from {path}")

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
train_sentences, train_labels = read_data_from_file('../../datasets/rotten/train_vocabulary.txt')
dev_sentences, dev_labels = read_data_from_file('../../datasets/rotten/dev_vocabulary.txt')
test_sentences, test_labels = read_data_from_file('../../datasets/rotten/test_vocabulary.txt')

classifier = SentimentClassifier(num_labels=5)  # Adjust num_labels based on your specific case
classifier.train(train_sentences, train_labels, dev_sentences, dev_labels, epochs=3)
test_accuracy = classifier.evaluate(test_sentences, test_labels)
print(f"Test Accuracy: {test_accuracy}")

# Save the model
classifier.save_model('vocabulary_bert.pth')
