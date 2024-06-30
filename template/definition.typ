#let def_counter = counter("_definition")

#let def(body, name: none) = block[
	#def_counter.step()
	*Definition #context def_counter.display(). #name*
	#linebreak()
	#emph(pad(1em, body))
]

#let theorem_counter = counter("_theorem")

#let theorem(body, name: none) = block[
	#theorem_counter.step()
	*Theorem #context theorem_counter.display(). #name*
	#linebreak()
	#emph(pad(1em, body))
]

#let proof_counter = counter("_proof")

#let proof(body, name: none) = block[
	#proof_counter.step()
	*Proof #context proof_counter.display(). #name*
	#linebreak()
	#emph(pad(1em, body)) #h(1em) $square.stroked.big$
]

#let nota_bene_counter = counter("_nota_bene")

#let nb(body, name: none) = context block(
		fill: blue.lighten(50%),
		inset: 16pt,
		radius: 8pt,
)[
	#nota_bene_counter.step()
	*NB #context nota_bene_counter.display(). #name*
	#body
]
