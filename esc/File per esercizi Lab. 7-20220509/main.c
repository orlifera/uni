#include <stdio.h>
#include <time.h>
#include "counting_sort.h"
#include "quicksort.h"
#include "merge_sort.h"
#include "array.h"

#define SIZE_A 7
#define SIZE_X 25000

int main()
{
    int A[SIZE_A] = {4, 3, 6, 1, 9, 7, 4};
    int B[SIZE_A];
    int Ord[SIZE_A];

    stampaArray(A, SIZE_A);
    /*
    copia_array(A, B, SIZE_A);
    counting_sort(B, SIZE_A);
    stampaArray(B, SIZE_A);
    
    copia_array(A, B, SIZE_A);
    mergeSort(B, 0, SIZE_A-1);
    stampaArray(B, SIZE_A);
    */
    quickSort(A, Ord, 0, SIZE_A - 1);
    stampaArray(A, SIZE_A);
}
