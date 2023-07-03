#include <stdio.h>

struct part
{
    int partN;
    char partname[25];
};
typedef struct part Part;
Part a;
Part b[10];
Part *ptr;

int main()
{
    printf("Enter part number: ");
    scanf("%d", &a.partN);
    printf("Enter part name: ");
    scanf("%s", a.partname);
    b[3] = a;
    ptr = b;
    printf("Name: %s, number: %d\n", b[3].partname, b[3].partN);
    printf("Name ptr: %s, number ptr: %d\n", (ptr + 3)->partname, (ptr + 3)->partN);
}