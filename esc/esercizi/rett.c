#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char choice();
void rettangolo(int b, int h, char s);

int main()
{
    int b, h;
    char s;

    printf("Enter h and b of a rectangule: ");
    scanf("%d%d", &h, &b);
    // s = choice();
    rettangolo(b, h, s);
}
/*
char choice()
{
    char *s;
    printf("Choose between one of these chars to draw the rectangule:\n1. *\n2. #\n3. +\n ");
    int c;
    scanf("%d", &c);
    if (c == 1)
    {
        strcpy(s, "*");
        return *s;
    }
    else if (c == 2)
    {
        strcpy(s, "#");
        return *s;
    }
    else
    {
        strcpy(s, "+");
        return *s;
    }
}
*/

void rettangolo(int b, int h, char s)
{
    for (int i = 0; i < b; i++)
    {
        printf("*");
    }
    printf("\n");
    for (int i = 0; i < h - 2; i++)
    {
        printf("*");
        for (int j = 0; j < b - 2; j++)
        {
            printf(" ");
        }
        printf("*\n");
    }
    for (int i = 0; i < b; i++)
    {
        printf("*");
    }
    printf("\n");
}