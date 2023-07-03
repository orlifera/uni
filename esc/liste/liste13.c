#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int val;
    struct nodo *next;

} Nodo;

typedef Nodo *lista;
lista radice;

Nodo *max(lista l)
{
    Nodo *e;
    if (l == NULL)
    {
        printf("Lista vuota\n");
        return 0;
    }
    if (l->next == NULL)
    {
        return l;
    }
    e = max(l->next);
    if (e->val > l->val)
    {
        return e;
    }
    else
    {
        return l;
    }
}