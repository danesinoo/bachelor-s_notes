import pandas as pd

# Caricamento dei file
# original_snippets = pd.read_csv('original_rt_snippets.txt', header=None, names=['snippet'])
dictionary = pd.read_csv('dictionary.txt', sep='|', header=None, names=['phrase', 'phrase_id'], skiprows=1)
sentiment_labels = pd.read_csv('sentiment_labels.txt', sep='|', header=None, names=['phrase_id', 'sentiment'], skiprows=1)
dataset_sentences = pd.read_csv('datasetSentences.txt', sep='\t', header=None, names=['sentence_id', 'sentence'], skiprows=1)
dataset_split = pd.read_csv('datasetSplit.txt', sep=',', header=None, names=['sentence_id', 'set_label'], skiprows=1)

dictionary['phrase_id'] = dictionary['phrase_id'].astype(int)
sentiment_labels['phrase_id'] = sentiment_labels['phrase_id'].astype(int)
sentiment_labels['sentiment'] = sentiment_labels['sentiment'].astype(float)

# Merge dei dati
merged_data = pd.merge(dataset_sentences, dataset_split, on='sentence_id')
merged_data = pd.merge(merged_data, dictionary, left_on='sentence', right_on='phrase')
merged_data = pd.merge(merged_data, sentiment_labels, on='phrase_id')

import seaborn as sns
import matplotlib.pyplot as plt

# Mappatura dei sentimenti nei 5 intervalli
def map_sentiment(value):
    if 0 <= value <= 0.2:
        return 'very negative'
    elif 0.2 < value <= 0.4:
        return 'negative'
    elif 0.4 < value <= 0.6:
        return 'neutral'
    elif 0.6 < value <= 0.8:
        return 'positive'
    else:
        return 'very positive'

merged_data['sentiment_label'] = merged_data['sentiment'].apply(map_sentiment)

# Conta delle etichette di sentiment
sentiment_counts = merged_data['sentiment_label'].value_counts()

# Visualizza la distribuzione delle classi
sns.barplot(x=sentiment_counts.index, y=sentiment_counts.values)
plt.xlabel('Sentiment')
plt.ylabel('Count')
plt.title('Distribuzione delle etichette di sentiment')
plt.show()

merged_data['text_length'] = merged_data['sentence'].apply(len)

# Istogramma della lunghezza dei testi
sns.histplot(merged_data['text_length'], bins=50)
plt.xlabel('Lunghezza del Testo')
plt.ylabel('Frequenza')
plt.title('Distribuzione della Lunghezza dei Testi')
plt.show()
 
from collections import Counter
import re
 
# Estrai tutte le parole dai testi
all_words = ' '.join(merged_data['sentence']).lower()
all_words = re.findall(r'\b\w+\b', all_words)

# Conta le parole più frequenti
word_counts = Counter(all_words)
most_common_words = word_counts.most_common(20)

# Visualizza le parole più frequenti
words, counts = zip(*most_common_words)
sns.barplot(x=counts, y=words)
plt.xlabel('Count')
plt.title('Parole più frequenti')
plt.show()

from wordcloud import WordCloud

# Crea word cloud per ogni sentiment
for sentiment in merged_data['sentiment_label'].unique():
    sentiment_texts = merged_data[merged_data['sentiment_label'] == sentiment]['sentence'].values
    wordcloud = WordCloud(width=800, height=400, background_color='white').generate(' '.join(sentiment_texts))
    
    plt.figure(figsize=(10, 5))
    plt.imshow(wordcloud, interpolation='bilinear')
    plt.title(f'Word Cloud per il sentiment: {sentiment}')
    plt.axis('off')
    plt.show()

# Distribuzione delle etichette di sentiment
print(sentiment_counts)

# Lunghezza media e mediana dei testi
mean_length = merged_data['text_length'].mean()
median_length = merged_data['text_length'].median()
print(f'Lunghezza media dei testi: {mean_length}')
print(f'Lunghezza mediana dei testi: {median_length}')

# Parole più frequenti
print(most_common_words)

import re

# Funzione di preprocessing per rimuovere punteggiatura e altre entità non utili
def preprocess(text):
    text = text.lower()
    words = re.findall(r'\b\w+\b', text)  # Trova tutte le parole
    return words

# Applicare la funzione di preprocessing a tutte le frasi
merged_data['words'] = merged_data['sentence'].apply(preprocess)

# Calcolare il numero totale di parole
total_words = merged_data['words'].apply(len).sum()

# Raccogliere tutte le parole uniche in un insieme
unique_words = set()
merged_data['words'].apply(unique_words.update)

# Calcolare il numero totale di parole uniche
total_unique_words = len(unique_words)

print(f'\nIl numero totale di parole nel dataset è: {total_words}')
print(f'\nIl numero totale di parole diverse nel dataset è: {total_unique_words}')
