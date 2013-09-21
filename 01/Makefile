CC=gcc
CFLAGS=-O2 -Wall
LDFLAGS=-O2

ifneq ($(LOADER_LINK),)
CFLAGS += -DLOADER_LINK=1
endif

all: loader x.bin

loader: loader.o $(LOADER_LINK)

x.bin: x.o
	objcopy -j .text.my -O binary x.o x.bin
