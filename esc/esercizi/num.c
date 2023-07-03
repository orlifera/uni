#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max(int *m, int dim);
int sum(int *m, int dim);
float radice(int *m, int dim);
int med(int *m, int dim);

int main()
{
    int dim = 5;
    int A[dim];
    float rad;
    int media;
    int somma;

    printf("Enter an integer: ");
    for (int i = 0; i < dim; i++)
    {
        scanf("%d", &A[i]);
    }

    rad = radice(A, dim);
    int massimo = max(A, dim);
    media = med(A, dim);
    printf("Sqrt of array's elements is: %.2f\n", rad);
    printf("Max between array's elements is: %d\n", massimo);
    printf("Avg between array's elements is: %d\n", media);
}

int sum(int *m, int dim)
{
    int s = 0;

    for (int i = 0; i < dim; i++)
    {
        s += m[i];
    }
    return s;
}

float radice(int *m, int dim)
{
    int a = sum(m, dim);
    float rad = sqrt(a);
    return rad;
}

int med(int *m, int dim)
{
    int s = sum(m, dim);
    int media = s / dim;
    return media;
}

int max(int *m, int dim)
{
    int massimo = 0;
    for (int i = 0; i < dim; i++)
    {
        if (m[i] < m[i + 1] && m[i + 1] < dim)
        {
            massimo = m[i + 1];
        }
        else
        {
            massimo = m[i];
        }
    }
    return massimo;
}