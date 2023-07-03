#include "quicksort.h"

void quickSort(int A[], int Ord[], int low, int high)
{
    if (high == 0)
    {
        return;
    }
    int dim_A = high + 1;
    int pivot = A[dim_A / 2];
    int numero_minori = 0;
    int numero_maggiori = 0;

    for (int i = low; i < high; i++)
    {
        if (A[i] < pivot)
        {
            numero_minori += 1;
        }
    }

    Ord[numero_minori] = pivot;

    int minori[numero_minori];
    int index = 0;
    for (int i = low; i < high; i++)
    {

        if (A[i] < pivot)
        {
            minori[index] = A[i];
            index += 1;
        }
    }

    for (int i = low; i < high; i++)
    {
        if (A[i] > pivot)
        {
            numero_maggiori += 1;
        }
    }
    int maggiori[numero_maggiori];
    index = 0;
    for (int i = low; i < high; i++)
    {

        if (A[i] > pivot)
        {
            maggiori[index] = A[i];
            index += 1;
        }
    }

    quickSort(minori, Ord, low, numero_minori - 1);
    quickSort(maggiori, Ord, low, numero_maggiori - 1);
}