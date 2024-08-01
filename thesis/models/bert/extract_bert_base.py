import torch
from transformers import BertModel, BertForSequenceClassification

# Load the saved model
model_path = 'bert_base_softmax.pth'

model = BertForSequenceClassification.from_pretrained('bert-base-uncased', num_labels=5)
model.load_state_dict(torch.load(model_path))

# Access the BERT model inside the BertForSequenceClassification model
bert_model = model.bert

# Remove the classifier head
del model.classifier

# Save the BERT model without the classifier head
output_model_path = 'bert-base.pth'
bert_model.save_pretrained(output_model_path)
