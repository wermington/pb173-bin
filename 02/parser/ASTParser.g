/* vim: cin
 *
 * tree walker
 *
 * Copyright (c) 2008 Jiri Slaby <jirislaby@gmail.com>
 *
 * Licensed under GPLv2.
 */

tree grammar ASTParser;
options {
	tokenVocab = Parser;
	language = C;
	ASTLabelType = pANTLR3_BASE_TREE;
}

translationUnit
	: ^(STATEMENT '+' i1=IDENTIFIER i2=IDENTIFIER) { puts($i1.text->chars); }
	;
