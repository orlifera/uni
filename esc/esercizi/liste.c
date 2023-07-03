#include <stdlib.h>
#include <stdio.h>

typedef struct nodo
{
    int valore;
    Nodo *prossimoNodo;
} Nodo;

typedef Nodo ListaInteri;

void inserisciInCoda(ListaInteri *l, Nodo *prossimo)
{
    if ((*l).prossimoNodo == NULL)
    {
        (*l).prossimoNodo = prossimo;
        return;
    }

    inserisciInCoda((*l).prossimoNodo, prossimo);
}

int main()
{
    int valoreIniziale;

    scanf("%d", &valoreIniziale);

    ListaInteri lista = {
        valoreIniziale,
        NULL,
    };

    Nodo secondoNodo = {
        2,
        NULL,
    };

    Nodo terzoNodo = {
        7,
        NULL,
    };

    inserisciInCoda(&lista, &secondoNodo);
    inserisciInCoda(&lista, &terzoNodo);
}