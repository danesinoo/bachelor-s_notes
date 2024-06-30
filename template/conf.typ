#import "titlepage.typ" : titlepage
#import "table_of_contents.typ" : table_of_contents
#import "definition.typ" : *
#import "styles.typ" : *

#let document_settings(doc) = {
	set heading(
	   	numbering: "1.1",
	   	bookmarked: true,
	)
	
	set page(
	   	paper: "a4",
		margin: (
	   		top: 3cm,
	   		bottom: 4cm,
	   		left: 3.2cm,
	   		right: 3.2cm
	   	),
	   	header: context {
			let sections = query(
				selector(heading.where(level: 1)).before(here()),
			)
			if sections.len() < 2 {
				align(right, smallcaps(document.title))
			} else {
				smallcaps(document.title) + h(1fr) + emph(sections.last().body)
			}
		},
	)
	
	show par: set block(spacing: 1.5em)
	show heading: it => {
		set block(above: 1.4em, below: 1em)
		smallcaps(it)
	}
	show link: set text(blue)
	show ref: set text(blue)

	doc
}

#let content_settings(doc) = {
	set page(
		numbering: "1 / 1",
	)
	
	set par(
	   	leading: 1em,
	   	first-line-indent: 1em,
	   	justify: true,
	)

	set enum(
		indent: 2em,
		numbering: "1.",
	)

	set list(
		indent: 1em,
	)

	set math.mat(
		delim: "[",
	)

	set math.vec(
		delim: "[",
	)

	context counter(page).update(1)

	doc
}

#let main(
	title: none,
	author: none,
	doc,
) = {
	show: body => document_settings(body)

	set document(
		title: title,
		author: author,
		date: datetime.today(),
	)

	titlepage(
		title,
		author,
		datetime.today(),
	)

	table_of_contents()

	show: body => content_settings(body)

	doc
}
