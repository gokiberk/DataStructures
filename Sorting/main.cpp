/**
*Title: Algorithm Efficiency and Sorting
*Author: Gokberk Keskinkilic
*Description: this is the main method
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "Sorting.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    cout << "Hello, Welcome to Sorting Assignment\n\n";
    
    int size = 16;
    int comp = 0;
    int move = 0;
    
    int arr1[16] = {7,3,6,12,13,4,1,9,15,0,11,14,2,8,10,5};
    int arr2[16] = {7,3,6,12,13,4,1,9,15,0,11,14,2,8,10,5};
    int arr3[16] = {7,3,6,12,13,4,1,9,15,0,11,14,2,8,10,5};
    int arr4[16] = {7,3,6,12,13,4,1,9,15,0,11,14,2,8,10,5};
    
    cout << setw(24) << "Original array: ";
    printArray(arr1, size);
    cout << endl;
    
    insertionSort( arr1, size, comp, move);
    cout << setw(24) << "After insertion sort: ";
    printArray(arr1, size);
    cout << setw(24) << "Move: " << setw(3) << move << "\n" << setw(24) << "Comp: " << setw(3) << comp << endl << endl;
    
    mergeSort( arr2, 0, size - 1, comp, move);
    cout << setw(24) << "After merge sort: ";
    printArray(arr2, size);
    cout << setw(24) << "Move: " << setw(4) << move << "\n" << setw(24) << "Comp: " << setw(4) << comp << endl << endl;
    
    quickSort( arr3, 0, size - 1, comp, move);
    cout << setw(24) << "After quick sort: ";
    printArray(arr3, size);
    cout << setw(24) << "Move: " << setw(4) << move << "\n" << setw(24) << "Comp: " << setw(4) << comp << endl << endl;
    
    radixSort( arr4, size);
    cout << setw(24) << "After radix sort: ";
    printArray(arr4, size);
    
    performanceAnalysis();
    
    
    return 0;
}
