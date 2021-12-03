//
//  main.cpp
//  CS201HW2
//
//  Created by Gökberk Keskinkılıç on 10.04.2021.
//

#include <iostream>
#include <algorithm>
#include <ctime>
#include <math.h>
#include <iomanip>

using namespace std;

/**
 algorithm 1
 */
int linearSearch( int* arr, int size, int key){
    for ( int i = 0; i < size; i++){
        // found it :)
        if ( arr[i] == key )
            return i;
    }
    return -1;
}

/**
 algorithm 2
 */
int linearSearchRecursive( int* arr, int low, int size, int key){
    if ( low > size )
        return -1;
    // found it :)
    if ( arr[low] == key)
        return low;
    else
        return linearSearchRecursive( arr, low + 1, size, key);
    
}

/**
 algorithm 3
 */
int binarySearch( int* arr, int low, int high, int key){
    if( low > high)
        return -1;
    int mid = ( low + high ) / 2;
    
    // found it :)
    if ( arr[mid] == key)
        return mid;
    
    if( arr[mid] > key )
        return binarySearch( arr, low, mid - 1, key);
    
    return binarySearch( arr, mid + 1, high, key);
}

/**
 algorithm 4
 */
int jumpSearch(int* arr, int size, int key){
    int step = sqrt(size);
 
    int prev = 0;
    while ( arr[min(step, size) - 1] < key){
        prev = step;
        step += sqrt(size);
        if (prev >= size)
            return -1;
    }
    for ( int i = prev; arr[i] < key; i++){
        if ( i == min(step, size))
            return -1;
    }
    // found it :)
    if (arr[prev] == size)
        return prev;
 
    return -1;
}

int main(int argc, const char * argv[]) {
    cout << "Welcome to Homework 2!\n";

    int** arrays = new int*[10]; //creating ten dynamic int array
    const int N[10] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000}; //declaring its sizes
    const int RUN_COUNT = 100000;
    
    //allocating space for each array wrt their size
    for ( int i = 0; i < 10; i ++)
        arrays[i] = new int[N[i]];
    //filling those arrays with random numbers
    for ( int i = 0; i < 10; i ++){
        for ( int j = 0; j < N[i]; j++){
            arrays[i][j] = rand() % 10000; }}
    //sorting arrays that were filled above
    for ( int i = 0; i < 10; i ++)
        sort( arrays[i], arrays[i] + N[i] );
    
    double duration;
    cout << endl;
    cout << "CAUTION!" << " All the above runtimes are average for when it is ran for " << RUN_COUNT << " times." << endl;
    for( int i = 0; i < 10; i++){
        cout << "---------------------------------------TIME for " << N[i] << " ITEMS--------------------------" << endl;
//        BEGINNING
        cout << "Case A___---___CLOSE TO BEGINNING___---___" << endl;
        clock_t startTime1 = clock();
        for ( int j = 0; j < RUN_COUNT; j ++)
            linearSearch( arrays[i], N[i], arrays[i][0]);
        duration = 1000 * double( clock() - startTime1 ) / CLOCKS_PER_SEC;
        cout << "Algorithm 1: linearSearch(iterative) " << setw(10)<< duration/RUN_COUNT << " milliseconds." << endl;
        
        clock_t startTime2 = clock();
        for ( int j = 0; j < RUN_COUNT; j ++)
            linearSearchRecursive( arrays[i], 0, N[i] - 1, arrays[i][0]);
        duration = 1000 * double( clock() - startTime2 ) / CLOCKS_PER_SEC;
        cout << "Algorithm 2: linearSearch(recursive) " << setw(10)<< duration/RUN_COUNT << " milliseconds." << endl;
        
        clock_t startTime3 = clock();
        for ( int j = 0; j < RUN_COUNT; j ++)
            binarySearch( arrays[i], 0, N[i] - 1, arrays[i][0]);
        duration = 1000 * double( clock() - startTime3 ) / CLOCKS_PER_SEC;
        cout << "Algorithm 3: binarySearch " << setw(21)<< duration/RUN_COUNT << " milliseconds." << endl;
        
        clock_t startTime31 = clock();
        for ( int j = 0; j < RUN_COUNT; j ++)
            jumpSearch( arrays[i], N[i] - 1, arrays[i][0]);
        duration = 1000 * double( clock() - startTime31 ) / CLOCKS_PER_SEC;
        cout << "Algorithm 4: jumpSearch " << setw(23)<< duration/RUN_COUNT << " milliseconds." << endl << endl;
        
    //    MIDDLE
        cout << "Case B____----___AROUND  MIDDLE___----____" << endl;
        clock_t startTime4 = clock();
        for ( int j = 0; j < RUN_COUNT; j ++)
            linearSearch( arrays[i], N[i], arrays[i][N[i]/2]);
        duration = 1000 * double( clock() - startTime4 ) / CLOCKS_PER_SEC;
        cout << "Algorithm 1: linearSearch(iterative) " << setw(10)<< duration/RUN_COUNT << " milliseconds." << endl;
        
        clock_t startTime5 = clock();
        for ( int j = 0; j < RUN_COUNT; j ++)
            linearSearchRecursive( arrays[i], 0, N[i] - 1, arrays[i][N[i]/2]);
        duration = 1000 * double( clock() - startTime5 ) / CLOCKS_PER_SEC;
        cout << "Algorithm 2: linearSearch(recursive) " << setw(10)<< duration/RUN_COUNT << " milliseconds." << endl;
        
        clock_t startTime6 = clock();
        for ( int j = 0; j < RUN_COUNT; j ++)
            binarySearch( arrays[i], 0, N[i] - 1, arrays[i][N[i]/2]);
        duration = 1000 * double( clock() - startTime6 ) / CLOCKS_PER_SEC;
        cout << "Algorithm 3: binarySearch " << setw(21)<< duration/RUN_COUNT << " milliseconds." << endl ;
        
        clock_t startTime61 = clock();
        for ( int j = 0; j < RUN_COUNT; j ++)
            jumpSearch( arrays[i], N[i] - 1, arrays[i][N[i]/2]);
        duration = 1000 * double( clock() - startTime61 ) / CLOCKS_PER_SEC;
        cout << "Algorithm 4: jumpSearch " << setw(23)<< duration/RUN_COUNT << " milliseconds." << endl << endl;
        
    //    END
        cout << "Case C____----___CLOSE  TO  END___----____" << endl;
        clock_t startTime7 = clock();
        for ( int j = 0; j < RUN_COUNT; j ++)
            linearSearch( arrays[i], N[i], arrays[i][N[i]-30]);
        duration = 1000 * double( clock() - startTime7 ) / CLOCKS_PER_SEC;
        cout << "Algorithm 1: linearSearch(iterative) " << setw(10)<< duration/RUN_COUNT << " milliseconds." << endl;
        
        clock_t startTime8 = clock();
        for ( int j = 0; j < RUN_COUNT; j ++)
            linearSearchRecursive( arrays[i], 0, N[i] - 1, arrays[i][N[i]-30]);
        duration = 1000 * double( clock() - startTime8 ) / CLOCKS_PER_SEC;
        cout << "Algorithm 2: linearSearch(recursive) " << setw(10)<< duration/RUN_COUNT << " milliseconds." << endl;
        
        clock_t startTime9 = clock();
        for ( int j = 0; j < RUN_COUNT; j ++)
            binarySearch( arrays[i], 0, N[i] - 1, arrays[i][N[i]-30]);
        duration = 1000 * double( clock() - startTime9 ) / CLOCKS_PER_SEC;
        cout << "Algorithm 3: binarySearch " << setw(21)<< duration/RUN_COUNT << " milliseconds." << endl;
        
        clock_t startTime91 = clock();
        for ( int j = 0; j < RUN_COUNT; j ++)
            jumpSearch( arrays[i], N[i] - 1, arrays[i][N[i]-30]);
        duration = 1000 * double( clock() - startTime91 ) / CLOCKS_PER_SEC;
        cout << "Algorithm 4: jumpSearch " << setw(23)<< duration/RUN_COUNT << " milliseconds." << endl << endl;

    //    not exist in array
        cout << "Case D____----___NOT   CONTAINS___----____" << endl;
        clock_t startTime10 = clock();
        for ( int j = 0; j < RUN_COUNT; j ++)
            linearSearch( arrays[i], N[i], 100821);
        duration = 1000 * double( clock() - startTime10 ) / CLOCKS_PER_SEC;
        cout << "Algorithm 1: linearSearch(iterative) " << setw(10)<< duration/RUN_COUNT << " milliseconds." << endl;
        
        clock_t startTime11 = clock();
        for ( int j = 0; j < RUN_COUNT; j ++)
            linearSearchRecursive( arrays[i], 0, N[i] - 1, 100821);
        duration = 1000 * double( clock() - startTime11 ) / CLOCKS_PER_SEC;
        cout << "Algorithm 2: linearSearch(recursive) " << setw(10)<< duration/RUN_COUNT << " milliseconds." << endl;
        
        clock_t startTime12 = clock();
        for ( int j = 0; j < RUN_COUNT; j ++)
            binarySearch( arrays[i], 0, N[i] - 1, 100821);
        duration = 1000 * double( clock() - startTime12 ) / CLOCKS_PER_SEC;
        cout << "Algorithm 3: binarySearch " << setw(21)<< duration/RUN_COUNT << " milliseconds." << endl;
        
        clock_t startTime121 = clock();
        for ( int j = 0; j < RUN_COUNT; j ++)
            jumpSearch( arrays[i], N[i] - 1, 100821);
        duration = 1000 * double( clock() - startTime121 ) / CLOCKS_PER_SEC;
        cout << "Algorithm 4: jumpSearch " << setw(23)<< duration/RUN_COUNT << " milliseconds." << endl << endl;

    }

    return 0;
}
