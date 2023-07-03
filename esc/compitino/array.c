#include <stdio.h>
#include <stdlib.h>

void check(int *A, int dim, int x, int *i, int *j);

int main()
{
    int *i = 0, *j = 0;
    int dim = 5;
    int A[dim];
    for (int i = 0; i < dim; i++)
    {
        A[i] = i;
    }
    // printf("%d%d", check(A, dim, 3, i, j));
}

void check(int *A, int dim, int x, int *i, int *j)
{
    for (*i = 0; *i < dim; *i += 1)
    {
        for (*j = 0; *j < dim; *j += 1)
        {
            if ((*i != *j) && A[*i] + A[*j] == x)
            {
                return;
            }
            else
            {
                *i = -1;
                *j = -1;
            }
        }
    }
}
