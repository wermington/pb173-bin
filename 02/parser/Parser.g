/*
 * an example grammar for ANTLR v3
 */

grammar Parser;
options {
	output = AST;
	language = C;
	ASTLabelType = pANTLR3_BASE_TREE;
}

tokens {
	STATEMENT;
}

/* The grammar starts here */

translationUnit
        : statement* EOF!
        ;

statement
	: i1=IDENTIFIER '+' i2=IDENTIFIER -> ^(STATEMENT '+' $i1 $i2)
	;

TYPE
	: 'int'
	| 'string'
	;

IDENTIFIER
	:	NonDigit (NonDigit|Digit)*
	;

fragment
NonDigit
	:	'_'
	|	'a'..'z'
	|	'A'..'Z'
	;

fragment
Digit
	:	'0'..'9'
	;

WHITESPACE
	:  (' '|'\r'|'\t'|'\u000C'|'\n') {$channel=HIDDEN;}
	;

COMMENT
	:   '/*' ( options {greedy=false;} : . )* '*/' {$channel=HIDDEN;}
	;
