#include "counting_sort.h"

void counting_sort(int A[], int dim)
{
    int max = 0;
    for (int i = 0; i < dim; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    int dimensioneF = max + 1;
    int F[dimensioneF];
    for (int k = 0; k < dimensioneF; k++)
    {
        F[k] = 0;
    }

    for (int j = 0; j < dim; j++)
    {
        F[A[j]] += 1;
    }
    int c = 0;
    for (int l = 0; l < dimensioneF; l++)
    {

        for (int i = 0; i < F[l]; i++)
        {
            A[c] = l;
            c += 1;
        }
    }
}