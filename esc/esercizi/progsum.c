#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a;
    int sum = 0;
    int k = 1;
    printf("Enter a number: ");
    scanf("%d", &a);
    while (a > 0)
    {
        sum += a;
        printf("sum at round %d is %d\n", k, sum);

        printf("Enter a number(-1 to stop): ");
        scanf("%d", &a);
        k++;
    }
}