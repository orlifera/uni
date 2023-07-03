#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int fatt = 1;
    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        fatt *= i;
    }
    printf("%d\n", fatt);
}