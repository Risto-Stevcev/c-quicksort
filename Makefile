CC = gcc

CFLAGS  = -std=c99 -g -Wall $(shell pkg-config --cflags cunit)

LDFLAGS = $(shell pkg-config --libs cunit)

.PHONY:
default: main

.PHONY:
test: testquicksort

testquicksort: quicksort.h quicksort.o

main: quicksort.h quicksort.o

quicksort.o: quicksort.h

.PHONY:
all: clean default test

.PHONY:
clean:
	rm -f *.o *.*~ main testquicksort
