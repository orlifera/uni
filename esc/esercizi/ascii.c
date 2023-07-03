#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sub(int a);

int main()
{

    int c = 128;
    int a;

    printf("Enter an integer: ");
    scanf("%d", &a);
    if (a < 0 && a > 128)
    {
        if (a < 1)
        {
            a += c;
        }
        else if (a > 127)
        {
            a -= c;
        }
    }
    printf("%c\n", (char)a);
}
