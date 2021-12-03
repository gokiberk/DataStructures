/**
*Title: Algorithm Efficiency and Sorting
*Author: Gokberk Keskinkilic
*/

#ifndef Sorting_h
#define Sorting_h

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <cmath>
#include <time.h>
using namespace std;

//main sorting functions with asked prototypes
void insertionSort( int* arr, const int size, int& compCount, int& moveCount);
void mergeSort( int* arr, const int first, const int last, int& compCount, int& moveCount);
void quickSort( int* arr, const int first, const int last, int& compCount, int& moveCount);
void radixSort( int* arr, const int size);
    
//helper functions

//helpers for merge sort
void merge( int* arr, int first, int mid, int last, int& compCount, int& moveCount);

//helpers for quick sort
void partition( int* arr, int first, int last, int& pivotIndex, int& compCount, int& moveCount);
void swap( int& a, int& b);

//helpers for radix sort
void radixSort( int* arr, int n, int digit);
int findDigit( int num);
int findMaxDigit( int* arr, int size);

//general helpers
void printArray( int* arr, int size);
void randomArr( int* arr, int size);
void getResult( int sortType);
void performanceAnalysis();

#endif /* Sorting_h */
