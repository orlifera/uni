#include <stdio.h>
#include "array.h"

void copia_array(int A[], int B[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        B[i] = A[i];
    }
}

void stampaArray(int A[], int dim)
{
    printf("{");
    for (int i = 0; i < dim; i++)
    {
        printf(" %d ", A[i]);
    }
    printf("}\n");
}