# Code - User Case Title

A brief description of the use case

**main actor**:  
**secondary actor**:  
**preconditions**: le condizioni in cui si deve trovare il sistema affinché si
possa accedere alla funzionalità  
**post-conditions**: le condizioni in cui si trova il sistema dopo aver
usufruito della funzionalità  
**main scenario**:  
**alternative scenario**:  

## Layer[ed] Architecture

Dall'alto verso il basso. Vuol dire che il database layer è il più importante e
si comincia da qui a progettare l'architettura.

- Presentation Layer | Controller
- Business Layer: rappresenta la realtà, lavora e la modifica | Service
- Persistance Layer: | Repòsitory
- Database Layer: molto importante, che forma ha la persistenza

### Presentation

1. Validazione dei dati (dal punto di vista sintattico)

### Business

1. Validazione dei dati (dal punto di vista semantico/funzionale)

Separation of concerns: è ben chiaro e diviso il ruolo di ciascun layer. 

<!--
NB le scorciatoie: vanno sempre ben spiegate!
-->

## Implementation View: Architettura Esagonale/Port Adapter


