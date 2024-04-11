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
