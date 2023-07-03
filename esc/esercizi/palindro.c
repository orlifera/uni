#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int palindromo(char *s, int l);

int main()
{
    char a[25];

    printf("Enter a string (max 25 char): ");
    scanf("%25s", a);
    int l = strlen(a);
    int pal = palindromo(a, l);

    if (pal == 1)
    {
        printf("%25s", a);
    }
    else
    {
        printf("String is not palindrome\n");
    }
}

int palindromo(char *s, int l)
{
    int flag = 1;
    int i = 0;
    int j = l - 1;
    while (i != l / 2 && flag != 0)
    {
        if (s[i] != s[j])
        {
            flag = 0;
        }
        i++;
        j--;
    }
    return flag;
}