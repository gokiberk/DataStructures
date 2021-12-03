CC=g++

CFLAGS=-c -Wall

all: ngram

ngram: main.o NgramTree.o
	$(CC) main.o NgramTree.o -o ngram


main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp



NgramTree.o: NgramTree.cpp
	$(CC) $(CFLAGS) NgramTree.cpp


clean:
	rm *o ngram
