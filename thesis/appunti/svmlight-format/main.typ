#import "../../../template/conf.typ" : *

#show: doc => main(
		title: [ Note sul formato `svmlight-tk` ],
		author: ("Carlo Rosso",),
		doc
)
#show: doc => compact(doc)

= Introduction

As stated in tmy intership plan, I need to convert the "Sentiment Penn Treebank"
into the `svmlight-tk` format. The next step consists in training models based
on the kernel methods using the just cited treebank. 

In this document I will:
- describe the `svmlight-tk` format @svmlight-tk;
- describe the format of "Sentiment Penn Treebank" @sentiment-penn-treebank;
- describe the conversion process @conversion-process.

#include "./svmlight.typ"
#include "./penn-treebank.typ"
#include "./conversion-process.typ"
