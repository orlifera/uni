#include <stdio.h>

void remove_triple(int *A, int *dim);

int main()
{
    int dim = 6;
    int A[] = {2, 1, 1, 1, 1, 2, 6, 5};
    for (int i = 0; i < dim; i++)
    {
        printf("%d", A[i]);
    }
    remove_triple(A, &dim);
    printf("\n");
    for (int i = 0; i < dim; i++)
    {
        printf("%d", A[i]);
    }
}

void remove_triple(int *A, int *dim)
{
    for (int i = 1; i < *dim - 1; i++)
    {
        if (A[i] == A[i - 1] && A[i] == A[i + 1])
        {
            for (int j = i; j < *dim; j++)
            {
                A[j] = A[j + 1];
            }
            i -= 1;
            *dim -= 1;
        }
    }
}