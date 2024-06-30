#import "../../template/conf.typ" : *

#show: doc => plain(doc)
#show: doc => main(
		title: [ Note su un sito di ricette ],
		author: ("Carlo Rosso",),
		doc
)

= Introduzione

Non avendo passato il progetto di tecnologie web alla prima consegna, dobbiamo
ricominciare il progetto da capo. Abbiamo deciso di fare un sito di ricette.

#include "pagine.typ"

#include "database.typ"

#include "backend.typ"
