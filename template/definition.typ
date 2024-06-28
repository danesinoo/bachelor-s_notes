#let def_counter = counter("_definition")

#let def(body, name: none) = block[
	#def_counter.step()
	*Definition #context def_counter.display(). #name*
	#linebreak()
	#emph(body)
]

#let theorem_counter = counter("_theorem")

#let theorem(body, name: none) = block[
	#theorem_counter.step()
	*Theorem #context theorem_counter.display(). #name*
	#linebreak()
	#emph(body)
]

#let proof_counter = counter("_proof")

#let proof(body, name: none) = block[
	#proof_counter.step()
	*Proof #context proof_counter.display(). #name*
	#linebreak()
	#emph(body) #h(1em) $square.stroked.big$
]

#let nota_bene_counter = counter("_nota_bene")

#let nb(body, name: none) = block[
	#nota_bene_counter.step()
	#block(
		fill: aqua,
		inset: 8pt,
		radius: 8pt,
	)[
		*NB #context nota_bene_counter.display(). #name*
		#linebreak()
		#body
	]
]
