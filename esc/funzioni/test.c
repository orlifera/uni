#include <stdio.h>

int main()
{
    int a, b = 2, *p, *q, **qq, **pp;
    q = &a;
    pp = &p;
    p = q;
    **pp = 7;
    printf("%d\n", a);
}