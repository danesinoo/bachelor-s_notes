import torch
from transformers import BertTokenizer, BertModel


class BERTEmbedder:
    def __init__(self, model_path):
        self.tokenizer = BertTokenizer.from_pretrained('bert-base-uncased')
        self.model = BertModel.from_pretrained('bert-base-uncased')
        state_dict = torch.load(model_path)

        filtered_state_dict = {k: v for k, v in state_dict.items() if not k.startswith("classifier")}

        self.model.load_state_dict(filtered_state_dict, strict=False)
        self.model.eval()  # Set the model to evaluation mode
        print(f"Model loaded from {model_path}")
    
    def get_embedding(self, word):
        inputs = self.tokenizer(word, return_tensors='pt')
        with torch.no_grad():
            outputs = self.model(**inputs)
        # Get the hidden state of the last layer (shape: [1, sequence_length, hidden_size])
        last_hidden_state = outputs.last_hidden_state
        # We are interested in the hidden state of the word itself
        # Since the input might be split into multiple tokens, we'll take the mean of those token embeddings
        word_embedding = last_hidden_state.mean(dim=1).squeeze().numpy()
        return word_embedding
    
    def load_model(self, model_path):
        """Load the fine-tuned model."""

# Example usage
model_path = 'models/bert/vocabulary_bert.pth'
embedder = BERTEmbedder(model_path)
word = "jokes"
embedding = embedder.get_embedding(word)
print(embedding)

