CC=gcc
CFLAGS=-O2 -Wall -g -fPIC
LD=gcc
LDFLAGS=-O2 -g -fPIC
VSCRIPT=-Wl,--version-script=vers.x

define build-ver
	$(LD) $(LDFLAGS) $(if $(shell test $(1) -gt 1 && echo y),$(VSCRIPT),) \
		-shared -o libvers.so vers$(1).o
	$(CC) $(CFLAGS) -DLIB_VER=$(1) -c -o x.o x.c
	$(LD) $(LDFLAGS) -o x$(1) x.o -L. -lvers
endef

all: vers1.o vers2.o vers3.o FORCE
	$(call build-ver,1)
	$(call build-ver,2)
	$(call build-ver,3)

.PHONY: FORCE
