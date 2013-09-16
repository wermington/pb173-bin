CC=gcc
CFLAGS=-O2 -Wall

all: loader x.bin

x.bin: x.o
	objcopy -j .text.my -O binary x.o x.bin
