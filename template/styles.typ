// font: "Linux Libertine",
// font: "Galvji",
// font: "Avenir"
// font: "Helvetica",
// font: "PT Sans Mono",
// font: "Arial Hebrew Scholar",
#let comfy(doc) = {
	set text(
		rgb("#333333"),
		size: 13pt,
		font: "Verdana",
	)
	set page(
		fill: rgb("#E5E5E5"),
	)

	doc
}

#let plain(doc) = {
	set text(
		size: 11pt,
		font: "Helvetica",
	)

	doc
}

#let compact(doc) = {
	set text(
		size: 8pt,
		font: "Helvetica",
	)
	set page(
		columns: 2,
	)

	doc
}

#let print(doc) = {
	set text(
		size: 12pt,
		font: "New Computer Modern",
	)

	doc
}
