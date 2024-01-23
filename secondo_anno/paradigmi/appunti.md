base di programmazione funzionale?

# clustering/batch

## back-pressure

Ciascun nodo indica a quello precedente quanti dati riuscirà a calcolare, in
questo modo il nodo precedente ha modo di calcolare quanti dati lui riuscirà a
elaborare e passerà l'informazione al nodo precedente, così a catena. Scopo:
aumentare la sincronizzazione.

- map
- flatmap: un solo elemento in input potrebbe generare più elementi in output,
  gli elementi in output sono unificati nella medesima stream (contrario di
  filter)
- filter: scarta qualche elemento in input
- skip: salta i primi n elementi
- zip: unifica stream diverse e ne restituisce una sola ~ stream di tuple,
  quando si ferma il primo stream, la funzione termina
- debounce: emette un elemento solo se è passato un lasso di tempo dall'utimo
  elemento della sorgente
- window: partiziona lo stream sorgente: parallelizza

## parallelismo

## concorrenza

	collaborativo | il codice coscenziosamente ritorna il controllo allo scheduler

	event driven | evento e codice che elabora l'evento, simile agli endpoint

	real time | thread, lock, latenza e esecuzione controllata nel tempo

	preventive | thread, lock

## classes repo

default = [[https://hg.sr.ht/~michelemauro/pdp2022-pub]]
