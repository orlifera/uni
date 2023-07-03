#include <stdio.h>

void copy(char *s1, char *s2);
void concatena(char *s1, char *s2, char *s3);
int main()
{
    char s1[100] = "strunz";
    char s2[100] = "bruh";
    char s3[100];
    // copy(s1, s2);
    // printf("%s", s1);
    concatena(s1, s2, s3);
    printf("%s", s3);
}

void copy(char *s1, char *s2)
{
    *s1 = *s2;
    if (*s2 != '\0')
    {
        copy(s1 + 1, s2 + 1);
    }
}

void concatena(char *s1, char *s2, char *s3)
{
    if (*s1 != '\0')
    {
        *s3 = *s1;
        concatena(s1 + 1, s2, s3 + 1);
    }
    if (*s2 != '\0' && *s3 != '\0')
    {
        *s3 = *s2;
        concatena(s1, s2 + 1, s3 + 1);
    }
}