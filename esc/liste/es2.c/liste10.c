#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "es2.h"

Lista Lunghezza_it(Lista Ptr)
{
    int contatore = 0;
    while (Ptr->next != NULL)
    {
        Ptr = Ptr->next;
        contatore++;
    }

    return contatore;
}

Lista Lunghezza_rc(Lista Ptr)
{
    if (Ptr->next == NULL)
    {
        return 0;
    }
    else
    {
        return Lunghezza_rc(Ptr->next) + 1;
    }
}

void dealloca(Lista Ptr)
{
    if (Ptr != NULL)
    {
        dealloca(Ptr->next);
        free(Ptr);
    }
}

Lista primoPari_It(Lista ptr)
{
    while (ptr != NULL && ptr->info % 2 == 0)
    {
        ptr = ptr->next;
        return ptr;
    }
}

Lista primoPari_Rc(Lista ptr)
{
    if (ptr != NULL && ptr->info % 2 == 0)
    {
        return ptr;
    }
    else
    {
        return primoPari_Rc(ptr->next);
    }
}

Lista minimo_PariIt(Lista ptr)
{
    Lista min = NULL;
    while (ptr != NULL && ptr->info % 2 == 0)
    {
        ptr = ptr->next;
        if (min == NULL)
        {
            min = ptr;
        }
        else if (ptr != NULL && ptr->info < min->info)
        {
            min = ptr;
        }
        if (ptr != NULL)
        {
            ptr = ptr->next;
        }
    }
    return min;
}

Lista elimina(Lista ptr, int X)
{
    while (ptr != NULL && X > 0)
    {
        ptr = ptr->next; //si muove nella lista
        X--;             //cancella elementi senza free
    }
    return ptr;
}

Lista elimina_rc(Lista ptr, int X)
{
    if (ptr == NULL || X == 0)
    {
        return ptr;
    }
    else
    {
        return elimina_rc(ptr->next, X--);
    }
}
Lista ordina(Lista Ptr)
{
}
Lista Merge(Lista Ptr)
{
    Lista temp;
    Lista p = malloc(sizeof(Elemento));
    Lista unione = malloc(sizeof(Elemento));
    int i = 0;

    while (Ptr->next != NULL && p->next != NULL)
    {
        if (p->info > Ptr->info)
        {
            unione->info = Ptr->info;
            unione = unione->next;
            unione->info = p->info;
            unione = unione->next;
        }
        else
        {
            unione->info = p->info;
            unione = unione->next;
            unione->info = Ptr->info;
        }
        Ptr = Ptr->next;
        p = p->next;
    }
}
