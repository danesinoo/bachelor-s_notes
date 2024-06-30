#import("conf.typ") : *

#show: doc => comfy(doc)
#show: doc => main(
		title: [ Il Titolo ],
		author: ("Carlo Rosso",),
		doc
)


= Hello world <hello>

$ mat(1, 2; 3, 4) $

#proof()[
$1 = 1$

Infatti $1 = 1$
]


#def()[
We the people.
]
== Wowo <wowo>

#nb()[
Questa è una nota importante.
]

#lorem(50)

+ hello
+ world
+ wowo

= Hello world <nb-verace>

#proof()[
$1 = 1$

Infatti $1 = 1$
]

#def()[
We the people.
]
== Wowo <wowo>

#theorem(name: "hello")[
$1 = 1$
]

#nb(name: "nb-verace")[
Questa teorema è vero.
]

@nb-verace

== Wowo <wowo>

#lorem(50)

+ hello
+ world
+ wowo

#lorem(500)

= Hello world

== Wowo <wowo>
== Wowo 
== Wowo
== Wowo

#lorem(50)

+ hello
+ world
+ wowo

#lorem(500)

= Hello world

== Wowo

#lorem(50)

+ hello
+ world
+ wowo

#lorem(500)
