In una classima rete multistrto l'output $$O(t)$$ al tempo $$t$$ dipende solo 
dall'input corrente $$I(t)$$. Quindi non può apprendere dipendenze temporali.  

**Come apprendere una sequenza?**

- trasformare il tempo in spazio: presentiamo come input alcuni elementi della
  sequenza $$S$$ in una "finestra temporate" $$W^T(t)$$ che si sposta sopra 
  $$S: W^T(t) = S(t:t+T)$$

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
