#import("conf.typ") : *

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

@hello

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

= Hello world

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

#nb()[
Questa è teorema è vero.
]

== Wowo <wowo>

#lorem(50)

+ hello
+ world
+ wowo

#lorem(500)

= Hello world

== Wowo <wowo>
== Wowo <wowo>
== Wowo <wowo>
== Wowo <wowo>

#lorem(50)

+ hello
+ world
+ wowo

#lorem(500)

= Hello world

== Wowo <wowo>

#lorem(50)

+ hello
+ world
+ wowo

#lorem(500)
