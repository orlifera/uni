#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct el
{
    int dato;
    struct el *next;
} EL;

int somma(EL *Testa, int M);
int main()
{

    EL *Ptr = malloc(sizeof(EL));
    Ptr->dato = 90;
    printf("Inserire un valore intero.\n");
    int v;
    scanf("%d", &v);

    printf("La somma dei valori multipli di %d è(-1 se lista vuota): %d\n", v, somma(Ptr, v));
}

int somma(EL *Testa, int M)
{
    int sum = 0;
    if (Testa == NULL)
    {
        return -1;
    }
    else
    {
        while (Testa != NULL)
        {
            if ((Testa->dato) % M == 0)
            {
                sum = sum + (Testa->dato);
            }
            Testa = Testa->next;
        }
    }
    //printf("La somma dei valori multipli di %d è: %d\n", M, sum);
    return sum;
}