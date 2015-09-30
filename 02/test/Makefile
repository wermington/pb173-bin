CC=gcc
LD=gcc
CFLAGS=-O2 -Wall
LDFLAGS=-O2 -L../ -lantlr3c
ANTLR=java -jar ../antlr-3.5.2-complete.jar

all: parser

parser: ParserLexer.o ParserParser.o main.o
	$(LD) -o $@ $^ $(LDFLAGS)

main.o: main.c ParserLexer.o ParserParser.o

%Lexer.c %Parser.c: %.g
	$(ANTLR) $^

%.c: %.g
	$(ANTLR) $^

clean:
	rm -f ParserLexer.* ParserParser.* *.o *.tokens

.PHONY: clean
