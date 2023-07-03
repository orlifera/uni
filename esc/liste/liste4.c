#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct lista
{
    char nome[20];
    struct lista *nextPtr;
};
typedef struct lista Lista;

void concatenate(Lista *L1, Lista *L2);

int main()
{
    Lista *l1;
    Lista *l2;
    l1 = malloc(sizeof(Lista));
    l2 = malloc(sizeof(Lista));

    strcpy(l1->nome, "Virgilio");
    strcpy(l2->nome, "Anita");

    concatenate(l1, l2);

    while (l1 != NULL)
    {
        printf("%s", l1->nome);
        l1 = l1->nextPtr;
    }
}

void concatenate(Lista *L1, Lista *L2)
{
    if (L1->nextPtr == NULL)
    {
        L1->nextPtr = L2;
    }
    else
    {
        while (L1->nextPtr != NULL)
        {
            L1 = L1->nextPtr;
        }
        L1->nextPtr = L2;
    }
}