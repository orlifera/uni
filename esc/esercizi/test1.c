#include <stdio.h>

int main()
{
    int a, b = 2, *p, *q, **pp, **qq;
    q = &a;
    p = q;
    **pp = 7;
    printf("%d", a);
    q = &b;
    **pp = 3;
    printf("%d", a);
}