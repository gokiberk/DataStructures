/**
*Title: Algorithm Efficiency and Sorting
*Author: Gokberk Keskinkilic
*ID 21801666
*Section: 1
*Assignment: 1
*Description: implementing functions
*/

#include "Sorting.h" //#include "Sorting.h"
using namespace std;

void insertionSort( int* arr, const int size, int& compCount, int& moveCount){
    for ( int unsorted = 1; unsorted < size; unsorted++){
        int nextItem = arr[unsorted];
        int loc = unsorted;

        for( ; (loc > 0) && (arr[loc-1] > nextItem); loc--){
            arr[loc] = arr[loc-1];
            moveCount++;
        }
        arr[loc] = nextItem;
        compCount++;
    }
}

// mergesort functions

void mergeSort( int* arr, const int first, const int last, int& compCount, int& moveCount){
    if (first != last) {
        int mid = ( first + last) / 2;
        
        mergeSort( arr, first, mid, compCount, moveCount);
        mergeSort( arr, mid + 1, last, compCount, moveCount);
        
        merge( arr, first, mid, last, compCount, moveCount);
    }
}

void merge( int* arr, int first, int mid, int last, int& compCount, int& moveCount){
    const int MAX_SIZE = 30000; // max is designated as 30000 for this assignment
    int temp[MAX_SIZE];
    
    int first1 = first;
    int first2 = mid + 1;
    
    int last1 = mid;
    int last2 = last;
    
    int index = first1;

    for( ; (first1 <= last1) && (first2 <= last2); ++index) {
        if (arr[first1] < arr[first2]) {
            temp[index] = arr[first1];
            first1++;
        }
        else{
            temp[index] = arr[first2];
            first2++;
        }
        compCount++;
        moveCount++;
    }
    // finish off the first subarray, if necessary
    while ( first1 <= last1){
        temp[index] = arr[first1];
        ++first1;
        ++index;
        moveCount++;
    }
    // finish off the second subarray, if necessary
    while ( first2 <= last2){
        temp[index] = arr[first2];
        ++first2;
        ++index;
        moveCount++;
    }
    // copy the result back into the original array
    for (index = first; index <= last; ++index){
        arr[index] = temp[index];
        moveCount++;
    }
}

// quicksort functions

void quickSort( int* arr, const int first, const int last, int& compCount, int& moveCount){
    int pivot;
    
    if ( first < last){
        partition( arr, first, last, pivot, compCount, moveCount);

        quickSort( arr, first, pivot - 1, compCount, moveCount);
        quickSort( arr, pivot + 1, last, compCount, moveCount);
    }
}

void partition( int* arr, int first, int last, int& pivotIndex, int& compCount, int& moveCount){
    int pivot = arr[first];
    moveCount++;
    
    int lastS1 = first;
    int firstUnknown = first + 1; // index of first item in unknown
       
    // move one item at a time until unknown region is empty
    while ( firstUnknown <= last) {
        // Invariant: theArray[first+1..lastS1] < pivot
        //            theArray[lastS1+1..firstUnknown-1] >= pivot
        
        // move item from unknown to proper region
        if (arr[firstUnknown] < pivot) {      // belongs to S1
            ++lastS1;
            swap(arr[firstUnknown], arr[lastS1]);
            moveCount+=3;
        }
        firstUnknown++;
        compCount++;
    }
    // place pivot in proper position and mark its location
    swap( arr[first], arr[lastS1]);
    moveCount+=3;
    pivotIndex = lastS1;
}

void swap( int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

// radixsort functions

void radixSort( int* arr, const int size){
    int max = findMaxDigit( arr, size);
    radixSort( arr, size, max);
}

void radixSort( int* arr, int n, int digit){
    for (int j = 0; j < digit ; j++) {
        int arrayStorage[10][n]; // 2D Array to store elements
        int countArray[10] = {0};
        for (int i = 0; i < n; i++){
            // place the digit to its place
            int k  = ((int)(arr[i]/pow(10, j)))%10; //last digit
            int pos = countArray[((int)(arr[i] / pow(10, j)))%10]; //increment the number
            arrayStorage[k][pos] = arr[i]; // add the element to there
            countArray[(int)(arr[i]/pow(10, j))%10] = pos+1; //increment the number in position
        }
        // place to array
        int curPos = 0;
        for (int i = 0; i < 10; i++) {
            //write to array
            int cur = 0;
            while(cur < countArray[i]){
                arr[curPos++] = arrayStorage[i][cur];
                cur++;
            }
        }
    }
}

int findDigit( int num){
    int d = 0;
    if ( num > 0){
        while( int(num != 0)){
            num = num / 10;
            d++;
        }
        return d;
    }
    else
        return 1; // in case it is negative
}

int findMaxDigit( int* arr, int size){
    int maxD = findDigit(arr[0]);
        for ( int i = 0; i < size; i++) {
            if ( maxD < findDigit(arr[i]) )
                maxD = findDigit(arr[i]);
        }
    return maxD;
}

// general helper functions

void printArray( int* arr, int size){
    if (arr != NULL) {
        for ( int i = 0; i < size-1; i++){
            cout << setw(findDigit(size)) << arr[i] << ", ";
        }
        cout << setw(findDigit(size)) << arr[size-1] << endl;
        } else {
            cout << "[]" << endl;
        }
}

void randomArr( int* arr, int size){
    for( int i = 0; i < size; i++){
        //srand((unsigned)time(NULL));
        arr[i] = rand() % (size * 10);
    }
}

string performanceResult( int* arr, int size, int algoType){
    int comp = 0;
    int move = 0;
    string result = "";
    clock_t start; //elapsing time
    clock_t startQ; //for quick sort's array assign
    double duration = 0;
    double durationQ = 0; //for quick sort's array assign
    const int RUN_COUNT = 10; //to get an average time for sorting algorithms
    
    if ( algoType == 1){ //case of insertion sort
        static bool printed = false;
        if(!printed){
            cout << "----------------------------------------------------------------" << endl;
            cout << "Part a – Time Analysis of Insertion Sort" << endl;
            cout << "Array Size" << setw(15) << "Time Elapsed" << setw(20) << "compCount" << setw(19) << "moveCount" << setw(10) << endl;
            printed = true;
        }
        start = clock();
        for ( int j = 0; j < RUN_COUNT; j ++){
            insertionSort(arr, size, move, comp);
        }
        duration = 1000 * double( clock() - start ) / CLOCKS_PER_SEC;
        cout << setw(5) << size << setw(17) << setprecision(6) << duration/RUN_COUNT << " ms" << setw(20) << comp/RUN_COUNT << setw(16) << move/RUN_COUNT << endl;
    }
    else if ( algoType == 2){ //case of merge sort
        static bool printed = false;
        if(!printed){
            cout << "----------------------------------------------------------------" << endl;
            cout << "Part b – Time Analysis of Merge Sort" << endl;
            cout << "Array Size" << setw(15) << "Time Elapsed" << setw(20) << "compCount" << setw(19) << "moveCount" << setw(10) << endl;
            printed = true;
        }
        start = clock();
        for ( int j = 0; j < RUN_COUNT; j ++){
            mergeSort(arr, 0, size - 1, move, comp);
        }
        duration = 1000 * double( clock() - start ) / CLOCKS_PER_SEC;
        cout << setw(5) << size << setw(17) << setprecision(6) << duration/RUN_COUNT << " ms" << setw(20) << comp/RUN_COUNT << setw(16) << move/RUN_COUNT << endl;
    }
    else if ( algoType == 3){ //case of quick sort
        static bool printed = false;
        if(!printed){
            cout << "----------------------------------------------------------------" << endl;
            cout << "Part c – Time Analysis of Quick Sort" << endl;
            cout << "Array Size" << setw(15) << "Time Elapsed" << setw(20) << "compCount" << setw(19) << "moveCount" << setw(10) << endl;
            printed = true;
        }
        start = clock();
        for ( int j = 0; j < RUN_COUNT; j ++){
            int unsorted[size];
            startQ = clock();
            for( int i = 0; i < size; i++){
                unsorted[i] = arr[i];
            }
            durationQ = 1000 * double( clock() - startQ ) / CLOCKS_PER_SEC;
            quickSort(unsorted, 0, size - 1, move, comp); //now arr is sorted
        }
        duration = 1000 * double( clock() - start ) / CLOCKS_PER_SEC;
        cout << setw(5) << size << setw(17) << setprecision(6) << duration/RUN_COUNT - durationQ/RUN_COUNT << " ms" << setw(20) << comp/RUN_COUNT << setw(16) << move/RUN_COUNT << endl;
    }
    else if ( algoType == 4){ //case of radix sort
        static bool printed = false;
        if(!printed){
            cout << "----------------------------------------------------------------" << endl;
            cout << "Part d – Time Analysis of Radix Sort" << endl;
            cout << "Array Size" << "      " << "Time Elapsed" << setw(18) << endl;
            printed = true;
        }
        start = clock();
        for ( int j = 0; j < RUN_COUNT; j ++)
            radixSort(arr, size);
        duration = 1000 * double( clock() - start ) / CLOCKS_PER_SEC;
        cout << setw(5) << size << setw(17) << setprecision(6) << duration/RUN_COUNT << setw(4 )<< " ms" << setw(20) << endl;
    }
    else // invalid algorithm
        cout << "Invalid algorithm type...";
    
    return result;
}

void getResult(int sortType){
    //alloc memory
    int *arr0 = new int[2000];
    int *arr1 = new int[6000];
    int *arr2 = new int[10000];
    int *arr3 = new int[14000];
    int *arr4 = new int[18000];
    int *arr5 = new int[22000];
    int *arr6 = new int[26000];
    int *arr7 = new int[30000];
    
    //fill the array with random numbers
    randomArr( arr0, 2000);
    randomArr( arr1, 6000);
    randomArr( arr2, 10000);
    randomArr( arr3, 14000);
    randomArr( arr4, 18000);
    randomArr( arr5, 22000);
    randomArr( arr6, 26000);
    randomArr( arr7, 30000);
    
    //print our performance
    performanceResult(arr0, 2000, sortType);
    performanceResult(arr1, 6000, sortType);
    performanceResult(arr2, 10000, sortType);
    performanceResult(arr3, 14000, sortType);
    performanceResult(arr4, 18000, sortType);
    performanceResult(arr5, 22000, sortType);
    performanceResult(arr6, 26000, sortType);
    performanceResult(arr7, 30000, sortType);
    cout << "----------------------------------------------------------------" << endl;

    // deallocate the memory
    delete [] arr0;
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    delete [] arr4;
    delete [] arr5;
    delete [] arr6;
    delete [] arr7;
}

void performanceAnalysis(){
    int sortType[4] = {1, 2, 3, 4};
    int sortTypeSize = 4;
        for (int i = 0; i < sortTypeSize; i++) {
            getResult(sortType[i]);
        }
}
