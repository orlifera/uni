#include <stdio.h>
#include <stdlib.h>

typedef struct part
{
    unsigned int partNumber;
    char partName[25];
} Part;

int main()
{
    Part a;
    Part b[10];
    Part *ptr;

    printf("Inserire un valore e un nome\n");
    scanf("%u%24s", &a.partNumber, a.partName);

    b[3] = a;
    ptr = b;
    printf("%u\n%s\n", (ptr + 3)->partNumber, (ptr + 3)->partName);
}