#let titlepage(
	title, 
	authors, 
	date,
) = {
	set align(center)
	set page(
		header: none, 
		footer: none, 
		numbering: none
	)

	set text(
		size: 27pt, 
		weight: "bold"
	)

	v(4cm)
	title
	linebreak()
	v(1em)

	set text(
		size: 18pt, 
		weight: "bold"
	)

	date.display("[day]/[month]/[year]")

	set text(
		size: 12pt, 
		weight: "regular"
	)

	linebreak()
	v(2em)

	for author in authors {
		author
	}
}
