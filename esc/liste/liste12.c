#include <stdio.h>
#include <stdlib.h>

typedef struct El
{
    int dato;
    struct El *next;
} ELEMENTO;
ELEMENTO insert(ELEMENTO **l, int val);
int somma(ELEMENTO *Testa, int M);

int main()
{
}

ELEMENTO insert_testa(ELEMENTO **l, int val)
{
    ELEMENTO *tempPtr;
    tempPtr = *l;
    *l = malloc(sizeof(ELEMENTO));
    (*l)->dato = val;
    (*l)->next = tempPtr;
}

int somma(ELEMENTO *Testa, int M)
{
    int sum = 0;
    //somma i valori della lista multipli di M;
    if (Testa == NULL)
    {
        return -1;
    }
    else
    {
        while (Testa != NULL)
        {
            if (Testa->dato % M == 0)
            {
                sum = sum + Testa->dato;
            }
            Testa = Testa->next;
        }
        return sum;
    }
}