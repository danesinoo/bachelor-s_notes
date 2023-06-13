# Forma normale di Chomsky

Un linguaggio è in forma normale di Chomsky se tutte le regole del linguaggio
sono di una delle seguenti forme:
	- A → BC|DE (A, B, C, D, E sono non terminali)
	- A → a|z (A è un non terminale, a e z sono un terminale)

# Automi a pila (push down automata)

Input: stringa di caratteri dell'alfabeto
Memoria: stati
Funzione di transizione: dato lo stato corrente ed un simbolo di input,
stabilisce quali possono essere gli stati successivi.

![Alt text](img/automi_a_pila "img:automi_a_pila")

Una pila è una struttura dati (o dispositivo di memoria) di tipo LIFO
(first-in-first-out). Ha due operazioni permesse: push e pop.
La pila è una memoria infinita.


Un linguaggio si dice Turing-riconoscibile se qualche Macchina di Turing lo
accetta.

Un linguaggio si dice Turing-decidibile o decidibile se qualche Macchina di
Turing lo decide.

Un decisore è una TM che accetta l'input o lo rifiuta, non entra in loop.
Se un decisore riconosce qualche linguaggio, si dice che quella TM decide quel 
linguaggio.

Un linguaggio è decidibile se e solo se è sia Turing-riconoscibile che
co-Turing-riconoscibile.
