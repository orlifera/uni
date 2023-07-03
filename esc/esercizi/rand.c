#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int a, r, b;
    r = rand();
    printf("Enter a number to guess the one decided by CPU(-1 to stop): ");
    scanf("%d", &a);
    while (a != -1)
    {
        if (a < r)
        {
            printf("your number is less grater than R, try again.\n");
        }
        else if (a > r)
        {
            printf("your number is grater than R. try again\n");
        }
        else
        {
            printf("GG, you got it. The number was: %d", r);
        }
        printf("Enter a number to guess the one decided by CPU(-1 to stop): ");
        scanf("%d", &a);
    }
}