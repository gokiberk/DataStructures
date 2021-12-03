CC=g++

CFLAGS=-c -Wall

all: hw1

hw1: main.o Sorting.o
	$(CC) main.o Sorting.o -o runthis


main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp



Sorting.o: Sorting.cpp
	$(CC) $(CFLAGS) Sorting.cpp


clean:
	rm *o runthis