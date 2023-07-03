#include <stdio.h>
#include <stdlib.h>

void molt(int *A, int dim, int *somma);

int main()
{
    int dim = 6;
    int *somma;
    int a[dim];
    for (int i = 0; i < dim; i++)
    {
        a[i] = i;
    }
    molt(a, dim, somma);
}

void molt(int *A, int dim, int *somma)
{
    int i = 0, j = dim - 1;
    while (i <= j)
    {
        *somma += A[i] * A[j];
        i++;
        j++;
    }
    for (int k = 0; k < dim; k++)
    {
        printf("%d", *somma);
    }
}