CC=gcc
CFLAGS=-O2 -Wall -ggdb -fPIC
LD=gcc
LDFLAGS=-O2 -ggdb -fPIC

all: memcheck tracer

memcheck: memcheck.o

tracer: tracer.o

clean:
	rm -f *.o

.PHONY: all clean
