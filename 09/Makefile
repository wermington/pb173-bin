CC=gcc
CFLAGS=-O2 -Wall -ggdb -fPIC
LD=gcc
LDFLAGS=-O2 -ggdb -fPIC

all: cov prof prof_pg

cov.o: cov.c
	$(CC) $(CFLAGS) --coverage -c -o $@ $<

cov: cov.o
	$(CC) $(LDFLAGS) --coverage -o $@ $<

prof_pg.o: prof.c
	$(CC) $(CFLAGS) -c -pg -o $@ $<

prof_pg: prof_pg.o
	$(CC) $(LDFLAGS) -pg -o $@ $<

prof: prof.o

clean:
	rm -f *.o cov prof prof_pg *.gcno

.PHONY: all
