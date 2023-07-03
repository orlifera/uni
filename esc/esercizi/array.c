#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void array(int *A, int dim);

int main()
{
    int dim = 0;
    printf("Enter a dimension for the array: ");
    scanf("%d", &dim);
    int A[dim];
    for (int i = 0; i < dim; i++)
    {
        printf("Enter a number in the array: ");
        scanf("%d", &A[i]);
    }

    array(A, dim);
}

void array(int *A, int dim)
{
    int i = 0;
    int sum = A[i + 1] + A[i + 2];
    if (i < dim)
    {
        if (A[i] == sum)
        {
            printf("%d\n", A[i]);
        }
        i++;
        array(&A[i], dim - 1);
    }
}