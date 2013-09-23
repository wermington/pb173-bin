/*
 * an example grammar for ANTLR v3
 */

grammar Parser;
options {
	language = C;
}

translationUnit
        : helloWorld EOF { puts("I'm done"); }
	;

helloWorld
	: AHOJ SVETE
	| SVETE AHOJ
        ;

AHOJ
	: 'Ahoj'
	;

SVETE
	: 'Svete'
	;

WHITESPACE
        :  (' '|'\r'|'\t'|'\u000C'|'\n') {$channel=HIDDEN;}
        ;
