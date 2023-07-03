#include <stdio.h>
#include <stdlib.h>

void inorder(int *A, int dim);

int main()
{
    int dim;
    printf("enter dim: ");
    scanf("%d", &dim);
    int A[dim];
    printf("Enter array's elements");
    for (int i = 0; i < dim; i++)
    {
        scanf("%d", &A[i]);
    }

    inorder(A, dim);
}

void inorder(int *A, int dim)
{
    int temp = 0;
    for (int i = 0; i < dim; i++)
    {
    }
}