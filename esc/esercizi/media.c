#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    float a, t, media;
    int b = 1;
    printf("Enter a positive number, -1 to stop: ");
    scanf("%f", &a);
    while (a >= 0)
    {
        t += a;
        printf("t = %.2f\n", t);
        media = t / b;
        printf("Al giro %d, la media è: %f\n", b, media);
        b++;
        printf("Enter a positive number, -1 to stop: ");
        scanf("%f", &a);
    }
}