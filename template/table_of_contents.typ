#let table_of_contents(
	name: "Table of Contents"
) = {
	show outline.entry.where(
		level: 1
	): it => {
		v(2em, weak: true)
		strong(it)
	}

	show outline.entry: it => {
		smallcaps(it)
	}

    set page(
        columns: 1,
    )

	outline(
		fill: box(width: 95%, repeat([#h(0.5em).])),
		indent: auto,
		title: name,
	)
}
