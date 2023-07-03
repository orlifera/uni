#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 10

typedef struct El
{
    int s;
    struct El *nextptr;
} Elemento;
typedef Elemento *ListaDiInteri;

int MinEven(ListaDiInteri LDI);

int main()
{
    ListaDiInteri *ldi;
    Elemento VAL[DIM];
    ldi = malloc(sizeof(ListaDiInteri));

    printf("Inserire 5 valori interi.\n");

    MinEven(ldi);
}

int MinEven(ListaDiInteri LDI)
{
    ListaDiInteri ris;
    ris = FirstEven(LDI);
    if (ris != NULL)
    {
        LDI = ris->nextptr;
        while (LDI != NULL)
        {
            if (((LDI->s) % 2 == 0) && LDI->s < ris->s)
            {
                LDI = LDI->nextptr;
            }
        }
    }
    return LDI;
    /*int num[DIM] = LDI;
    int even[DIM];
    int Min = 0;
    int k = 0;
    for (int i = 0; i < DIM; i++)
    {
        if (num[i] % 2 == 0)
        {
            even[k] = num[i];
            k++;
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (even[j] > even[j + 1])
            {
                Min = even[j + 1];
            }
        }
    }
    return Min;*/
}