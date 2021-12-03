CC=g++

CFLAGS=-c -Wall

all: hw2

hw2: main.o NgramTree.o
	$(CC) main.o NgramTree.o -o runthis


main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp



NgramTree.o: NgramTree.cpp
	$(CC) $(CFLAGS) NgramTree.cpp


clean:
	rm *o runthis
