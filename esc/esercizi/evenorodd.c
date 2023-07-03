#include <stdio.h>
#include <stdlib.h>

int EvenOrOdd(int x);

int main()
{
    int x;
    scanf("%d", &x);
    int check = EvenOrOdd(x);
    if (check == 1)
    {
        printf("Number is Even\n");
    }
    else
    {
        printf("Number is Odd\n");
    }
}

int EvenOrOdd(int x)
{
    if (x % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}