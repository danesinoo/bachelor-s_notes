#import "../../template/conf.typ" : *

= Pagine Web

Di seguito l'elenco delle pagine web del sito:

/ Home: Liste delle ricette, con ricerca per nome
    - nome
    - immagine
    - tempo di preparazione
    - difficoltà
    - link alla pagina della ricetta

/ Ricetta: Pagina di una ricetta, con:
    - ingredienti
    - procedimento
    - tempo di preparazione
    - difficoltà
    - copiare giallo zafferano

/ Aggiungi ricetta: Form per aggiugere una ricetta
    - nome
    - immagine
    - ingredienti
    - procedimento
    - tempo di preparazione
    - difficoltà
    - link alla pagina della ricetta

/ Modifica ricetta: Form per modificare una ricetta, con i campi come sopra

/ Pagina di login: Form per il login
    - username
    - password
    - link alla pagina di registrazione

/ Pagina di registrazione: Form per la registrazione
    - username
    - password
    - link alla pagina di login

/ Pagina di profilo: Pagina con le informazioni dell'utente

/ Pagina delle proprie ricette: Lista delle ricette dell'utente loggato

/ Pagine di errore:
    - 400
    - 402
    - 404
    - ...

/ About us: Pagina con le informazioni sul sito

/ Contatti: Pagina con le informazioni di contatto

/ Pagina di test: accedendo a questa pagina sono eseguiti tutti gli unit e gli
integration test e sul sito viene visualizzato il risultato

== Reindirizzamento

- Se l'utente non è loggato e cerca di accedere a una pagina che richiede il 
  login:
  + Viene salvato in localStorage l'URL a cui voleva accedere, oppure l'URL di partenza
  + Viene reindirizzato alla pagina di login
  + Dopo il login viene reindirizzato all'URL salvato

- Idem per la registrazione

- Se il campo nel localStorage è vuoto, viene reindirizzato alla home

- Si può pensare di usare questa tecnica anche per gestire altri
  reindirizzamenti
