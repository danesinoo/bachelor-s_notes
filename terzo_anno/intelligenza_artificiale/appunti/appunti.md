In una classima rete multistrto l'output $O(t)$ al tempo $t$ dipende solo 
dall'input corrente $I(t)$. Quindi non può apprendere dipendenze temporali.  

**Come apprendere una sequenza?**

- trasformare il tempo in spazio: presentiamo come input alcuni elementi della
  sequenza $S$ in una "finestra temporate" $W^T(t)$ che si sposta sopra 
  $S: W^T(t) = S(t:t+T)$

Problemi:
1. i neuroni di input vengono replicati per ogni elemento rappresentato nella
   finestra
2. visibilità limitata dalla dimensione della finestra

per esempio, NetTalk:
- sono date in input 7 lettere per volta
- ci sono 80 unità nascoste
- l'input viene elaborato per individuare il fonema corrispondente alla lettera
  centrale

## Reti riccorenti

Un'altra soluzione è quella di utilizzare reti ricorrenti, che forniscono un
input ricorrente proveniente dallo stesso strato o da strati superiori.  
Diventa una specie di memoria a breve termine di stati precedenti della rete.
Viene passato in input una qualche informazione sullo stato precedente della
rete.  
Si vuole aumentare la memoria della rete nel tempo, in modo che possa ricordare
il maggior numero di informazioni possibili.

### Backpropagation

Le reti __parzialmente ricorrenti__ si possono addestrare con l'algoritmo
back-propagation, perchè la struttura temporale è in biiezione con una struttura
spaziale.

### Rete di Elman (SRN)

- le connessioni ricorrenti sono al livello dei neuroni nascosti
- aumentano la dimensione dell'input
- i neuroni ricorrenti sono inizializzati a 0 e aggiornati ad ogni passo
- i neuroni ricorrenti si chiamano "neuroni di contesto"
- i neuroni di contesto sono una copia dei neuroni nascosti al passo precedente
- i neuroni nascosti avranno per errore la media degli errori dei neuroni di
  contesto e dei neuroni nascosti medesimi, per ciascun passo temporale

### Self-supervised learning

- training set: sequenza di lettere
- compito: prevedere la lettera successiva (oppure la parola)
- si chiama self-supervised learning perché l'input e l'output hanno la stessa
  struttura

Cose fike, una rete così addestrata scopre categorie lessicali:
- le attivazioni delle unità nascoste corrispondenti ad ogni parola sono state
  analizzate usando clustering gerarchico
- la rete raggruppa le parole in base al loro utilizzo, ovvero al contesto
  circostante, scoprendo diverse categorie lessicali
- al modello sono fornite solo frasi di senso compiuto (senza alcuna conoscenza
  semantica)

<!-- n-400 mismatch negativity -->
<!--
Moro qualcosa. Anche pigliando persone che non conoscono una lingua, se esse
sono state sottoposte ad ascoltare such a language for a little bit, esse
mostrano che il loro cervello è in grado di riconoscere se una frase è corretta
o meno.
-->

### Long-Short Term Memory (LSTM) networks

- unità LSTM (gate) mantiene l'informazione per un periodo di tempo maggiore
- serie di porte (gates) che definiscono il flusso di informazione, ovvero
  decidono se 
    - output gate: se trasmettere l'informazione
    - input gate: se memorizzare l'informazione
    - forget gate: se dimenticare l'informazione
- ogni gate ha un insieme di pesi sinaptici

Predico la parola successiva in base alla parola precedente predetta e così
viene generato il testo.

### Deep RNN

- prime reti con capacità notevoli di generare del testo
- training set: vari corpus linguistici di larga scala (es. Wikipedia, New York
  Times, Machine learning papers)
- apprendimento per singolo simbolo (carattere, lettera)
- ha bisogno di uno stato iniziale (seed, prompt), dopo il quale la rete procede
  in modo autonomo tirando fuori i caratteri succesivi più probabili

Problema:

- la memorizzazione previa carattere richiede moltissima memoria

### Word embeddings

- codificare le singole parole con vettori numerici di lunghezza fissa
- i vettori vicini (simili) hanno significato simile
- algoritmi di embedding ad hoc per effettuare la trasformazione
- alcuni di questi algoritmi sono basati su reti neurali:
    - Word2Vec
    - GloVe
    - FastText

In questo modo, effettuando la trasformazione:
```
vec("Madrid") - vec("Spagna") + vec("Italia") = vec("Roma")
vec("Fratello") - vec("Uomo") + vec("Donna") = vec("Sorella")
```

La rappresentazione della parola codifica il significato della parola stessa per
implicazione. Di per sé il modello memorizza le parole sul loro contesto. Per
cui ciascuna parola è rappresentata dai contesti in cui appare.  
Rispetto ad una parola, il contesto sono l'insieme delle parole che la
accompagnano (ovvero la precedono e la seguono).

### Trasformers

- self attention mechanism: ogni token è collegato a tutti gli altri, in modo
  più o meno marcato (ha come dei pesi sinaptici), per cui tornando alla
  rappresentazione precedente, due parole hanno un peso maggiore se compaiono in
  contesti simili.
- prende in input una sequenza di elementi, chiamati token
- restituisce in output una sequenza di elementi

- ecoder: costruisce una rappresentazione interna della sequenza utilizzando
  come contesto per ogni token tutti gli altri token
  - BERT
  - addestramento: una parola viene mascherata e il modello deve prevederla
    (BERT)

- decoder: genera una sequenza di tokens utilizzando solo i tokens precedenti (a
  sinistra) come contesto per condizionare la generazione.
  - GPT
  - addestramento: il modello deve prevedere il token successivo
  - causal language modelling: n dipende solo da n-1 (e non da n+1)

Un encoder tendenzialmente è migliore per la comprensione del testo. Un decoder
è migliore per la generazione del testo.

### Large language models

- basati su trasformers (tutti)
- addestrati su enormi quantità di testo
- più blocchi di encoder e/o decoder (aumentano moltissimo i parametri)
- più aumenta la dimensione del modello, più aumenta la capacità di
  generalizzazione
- pre-addestramento: addestramento su un task generico (es. prevedere la parola
  successiva, ...)
- fine-tuning: addestramento su un task specifico
- allineamento (reinforment learning from human feedback): addestramento
  supervisionato con feedback umano, per aggiungere il politically correct

## GPT

- ad ogni passo che viene generato un token
- il modello è addestrato calcola la probabilità del token successivo
- non sempre scegliere il token più probabile è la scelta migliore
