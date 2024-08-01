import torch
import torch.nn as nn
import torch.nn.functional as F
from transformers import BertModel, BertTokenizer, AdamW
from torch.utils.data import DataLoader, Dataset
import numpy as np

class CustomDataset(Dataset):
    def __init__(self, texts, labels, tokenizer, max_len):
        self.texts = texts
        self.labels = labels
        self.tokenizer = tokenizer
        self.max_len = max_len

    def __len__(self):
        return len(self.texts)

    def __getitem__(self, idx):
        text = self.texts[idx]
        label = self.labels[idx]
        encoding = self.tokenizer.encode_plus(
            text,
            add_special_tokens=True,
            max_length=self.max_len,
            return_token_type_ids=False,
            padding='max_length',
            return_attention_mask=True,
            return_tensors='pt',
        )
        return {
            'text': text,
            'input_ids': encoding['input_ids'].flatten(),
            'attention_mask': encoding['attention_mask'].flatten(),
            'label': torch.tensor(label, dtype=torch.long)
        }

class SpanInformationCollectingLayer(nn.Module):
    def __init__(self, hidden_dim):
        super(SpanInformationCollectingLayer, self).__init__()
        self.hidden_dim = hidden_dim
        self.W = nn.Linear(hidden_dim * 4, hidden_dim)

    def forward(self, h):
        N = h.size(1)  # sequence length
        span_representations = []
        for i in range(N):
            for j in range(i, N):
                hi = h[:, i, :]
                hj = h[:, j, :]
                h_ij = torch.cat([hi, hj, hi - hj, hi * hj], dim=-1)
                span_representations.append(self.W(h_ij))
        span_representations = torch.stack(span_representations, dim=1)
        return F.tanh(span_representations)

class InterpretationLayer(nn.Module):
    def __init__(self, hidden_dim):
        super(InterpretationLayer, self).__init__()
        self.hidden_dim = hidden_dim
        self.h_hat = nn.Parameter(torch.randn(hidden_dim))
        self.softmax = nn.Softmax(dim=1)

    def forward(self, spans):
        alpha_ij = torch.matmul(spans, self.h_hat)
        alpha_ij = self.softmax(alpha_ij)
        h_tilde = torch.sum(alpha_ij.unsqueeze(-1) * spans, dim=1)
        return h_tilde

class CustomModel(nn.Module):
    def __init__(self, base_model_path, hidden_dim, num_classes):
        super(CustomModel, self).__init__()
        self.bert = BertModel.from_pretrained(base_model_path)
        
        # Freeze BERT parameters
        for param in self.bert.parameters():
            param.requires_grad = False
        
        self.sic_layer = SpanInformationCollectingLayer(hidden_dim)
        self.interpretation_layer = InterpretationLayer(hidden_dim)
        self.output_layer = nn.Linear(hidden_dim, num_classes)

    def forward(self, input_ids, attention_mask):
        with torch.no_grad():  # Ensure BERT is not fine-tuned
            outputs = self.bert(input_ids=input_ids, attention_mask=attention_mask)
        sequence_output = outputs.last_hidden_state
        spans = self.sic_layer(sequence_output)
        h_tilde = self.interpretation_layer(spans)
        logits = self.output_layer(h_tilde)
        return F.log_softmax(logits, dim=1)

    def save_model(self, path):
        state_dict = {
            'sic_layer': self.sic_layer.state_dict(),
            'interpretation_layer': self.interpretation_layer.state_dict(),
            'output_layer': self.output_layer.state_dict()
        }
        torch.save(state_dict, path)

    def load_model(self, path):
        state_dict = torch.load(path)
        self.sic_layer.load_state_dict(state_dict['sic_layer'])
        self.interpretation_layer.load_state_dict(state_dict['interpretation_layer'])
        self.output_layer.load_state_dict(state_dict['output_layer'])

class NLPTrainer:
    def __init__(self, model, tokenizer, max_len, device):
        self.model = model
        self.tokenizer = tokenizer
        self.max_len = max_len
        self.device = device
        self.model.to(self.device)

    def train(self, train_data, val_data, epochs, batch_size, learning_rate):
        train_dataset = CustomDataset(
            texts=train_data['texts'],
            labels=train_data['labels'],
            tokenizer=self.tokenizer,
            max_len=self.max_len
        )
        val_dataset = CustomDataset(
            texts=val_data['texts'],
            labels=val_data['labels'],
            tokenizer=self.tokenizer,
            max_len=self.max_len
        )
        train_loader = DataLoader(train_dataset, batch_size=batch_size, shuffle=True)
        val_loader = DataLoader(val_dataset, batch_size=batch_size, shuffle=False)

        optimizer = AdamW(filter(lambda p: p.requires_grad, self.model.parameters()), lr=learning_rate)

        for epoch in range(epochs):
            self.model.train()
            total_loss, total_correct = 0, 0
            for batch in train_loader:
                input_ids = batch['input_ids'].to(self.device)
                attention_mask = batch['attention_mask'].to(self.device)
                labels = batch['label'].to(self.device)

                optimizer.zero_grad()
                outputs = self.model(input_ids=input_ids, attention_mask=attention_mask)
                loss = F.nll_loss(outputs, labels)
                total_loss += loss.item()
                total_correct += (outputs.argmax(dim=1) == labels).sum().item()

                loss.backward()
                optimizer.step()

            avg_loss = total_loss / len(train_loader)
            avg_acc = total_correct / len(train_dataset)
            val_loss, val_acc = self.evaluate(val_loader)

            print(f'Epoch {epoch + 1}/{epochs}, Train Loss: {avg_loss:.4f}, Train Acc: {avg_acc:.4f}, Val Loss: {val_loss:.4f}, Val Acc: {val_acc:.4f}')

    def evaluate(self, data_loader):
        self.model.eval()
        total_loss, total_correct = 0, 0
        with torch.no_grad():
            for batch in data_loader:
                input_ids = batch['input_ids'].to(self.device)
                attention_mask = batch['attention_mask'].to(self.device)
                labels = batch['label'].to(self.device)

                outputs = self.model(input_ids=input_ids, attention_mask=attention_mask)
                loss = F.nll_loss(outputs, labels)
                total_loss += loss.item()
                total_correct += (outputs.argmax(dim=1) == labels).sum().item()

        avg_loss = total_loss / len(data_loader)
        avg_acc = total_correct / len(data_loader.dataset)
        return avg_loss, avg_acc

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

# Example usage
if __name__ == "__main__":
    base_model_path = 'bert-base.pth'
    hidden_dim = 768  # Usually the hidden size of BERT
    num_classes = 5  # Number of classes for classification
    max_len = 128
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

    tokenizer = BertTokenizer.from_pretrained('bert-base-uncased')
    model = CustomModel(base_model_path, hidden_dim, num_classes)

    # train_sentences, train_labels = read_data_from_file('data/train.txt')
    # val_sentences, val_labels = read_data_from_file('data/dev.txt')

    # train_data = {'texts': train_sentences, 'labels': train_labels}
    # val_data = {'texts': val_sentences, 'labels': val_labels}
    # 
    # trainer.train(train_data, val_data, epochs=3, batch_size=8, learning_rate=2e-5)
    # 
    # # Save the additional layers
    # model.save_model('self-explain-bert.pth')

    model.load_model('self-explain-bert.pth')
    trainer = NLPTrainer(model, tokenizer, max_len, device)

    test_sentences, test_labels = read_data_from_file('data/test.txt')
    test_data = {'texts': test_sentences, 'labels': test_labels}

    test_dataset = CustomDataset(
        texts=test_data['texts'],
        labels=test_data['labels'],
        tokenizer=tokenizer,
        max_len=max_len
    )

    test_loader = DataLoader(test_dataset, batch_size=8, shuffle=False)
    test_loss, test_acc = trainer.evaluate(test_loader)
    print(f'Test Loss: {test_loss:.4f}, Test Acc: {test_acc:.4f}')
