#include <stdio.h>

int check(int *A, int dimA, int *B, int dimB);

int main()
{
    int a[] = {1, -3, 2};
    int b[] = {1, 9, 8, 3, 8, 6, 2, 7, 9};
    int dimA = 3, dimB = 9;
    int c = check(a, dimA, b, dimB);
    if (c)
    {
        puts("Found");
    }
    else
    {
        puts("fuck off");
    }
}

int check(int *A, int dimA, int *B, int dimB)
{
    if (dimA <= 0)
    {
        return 1;
    }
    if (dimB <= 0)
    {
        return 0;
    }
    if (*A == *B || *A == -*B)
    {
        return check(A + 1, dimA - 1, B + 1, dimB - 1);
    }
    else
    {
        return check(A, dimA, B + 1, dimB - 1);
    }
}