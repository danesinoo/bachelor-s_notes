= The `svmlight-tk` format <svmlight-tk>

Follows the syntax of the `svmlight` format:
/ \<line> ::= \<target>\<blanket>\<set-of-trees>
/ \<target> ::= +1 | -1 | 0 | \<float>
/ \<blanket> ::= " " (i.e. one space)
/ \<set-of-trees> ::= \<begin-tree>\<blank>\<tree>\<blank>..\<begin-tree>\<blank>\<tree>\<blank>\<end-tree>
/ \<begin-tree> ::= "|BT|"
/ \<end-tree> ::= "|ET|"
/ \<tree> ::= \<full-tree> | \<blank>
/ \<full-tree> ::= (\<root>\<blank>\<full-tree>..\<full-tree>) | (\<root>\<blank>\<leaf>)
/ \<root> ::= \<string>
/ \<leaf> ::= \<string>

---

/ \<line> ::= \<target>" |BT|"\<full-tree>" |ET|"
/ \<target> ::= \<sentiment>
/ \<full-tree> ::= (\<root>" "\<full-tree>..\<full-tree>) | (\<root>" "\<word>)
/ \<sentiment> ::= "0" | "1" | "2" | "3" | "4" 
/ \<word> ::= a word from the sentence
