#include <stdio.h>

int main()
{
    int x = 1, y = 4;
    int *p;
    int *q = &x;
    {
        int x = 3;
        p = &x;
    }
    printf("%d", *p);
    p = q;
    q = &y;
    *q += 1;
    printf("%d", y);
    printf("%d", *p);
}