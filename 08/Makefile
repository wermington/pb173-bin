CC=gcc
CFLAGS=-O2 -Wall -ggdb -fPIC
LD=gcc
LDFLAGS=-O2 -ggdb -fPIC

all: cov debug memcheck tracer prof prof_pg

cov.o: cov.c
	$(CC) $(CFLAGS) --coverage -c -o $@ $<

cov: cov.o
	$(CC) $(LDFLAGS) --coverage -o $@ $<

debug: debug.o

memcheck: memcheck.o

prof_pg.o: prof.c
	$(CC) $(CFLAGS) -c -pg -o $@ $<

prof_pg: prof_pg.o
	$(CC) $(LDFLAGS) -pg -o $@ $<

prof: prof.o

tracer: tracer.o

.PHONY: all
