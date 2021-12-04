CC=g++

CFLAGS=-c -Wall

all: sort

sort: main.o Sorting.o
	$(CC) main.o Sorting.o -o sort


main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp



Sorting.o: Sorting.cpp
	$(CC) $(CFLAGS) Sorting.cpp


clean:
	rm *o sort
