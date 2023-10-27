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

## Layered Architecture

- Presentation Layer | Controller
- Business Layer: rappresenta la realtà, lavora e la modifica | Service
- Persistance Layer: | Repòsitory
- Database Layer: molto importante, che forma ha la persistenza

### Presentation

1. Validazione dei dati (dal punto di vista sintattico)

### Business

1. Validazione dei dati (dal punto di vista semantico/funzionale)

Separation of concerns: è ben chiaro e diviso il ruolo di ciascun layer. 
