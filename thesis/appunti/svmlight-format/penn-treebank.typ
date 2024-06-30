= The `Sentiment Penn Treebank` format <sentiment-penn-treebank>

Follows what I got of the `Sentiment Penn Treebank`'s format.
/ \<line> ::= "("\<target>\<blank>\<set-of-trees>")"
/ \<set-of-trees> ::= \<node> | "("\<sentiment>\<blank>\<node>\<blank>\<set-of-trees>")"
/ \<node> ::= "("\<sentiment>\<blank>\<word>")" | "("\<sentiment>\<blank>\<set-of-trees>")"
/ \<target> ::= \<sentiment>
/ \<sentiment> ::= "0" | "1" | "2" | "3" | "4", where 0 is the most negative and 4 is the most positive, therefore 2 is neutral;
/ \<word> ::= a word from the sentence, for example "hello".
/ \<blanket> ::= " " (i.e. one space)
