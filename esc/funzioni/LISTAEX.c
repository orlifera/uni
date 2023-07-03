#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//struttura autoreferenziale

typedef struct nodoLista
{
    int valore;
    struct nodoLista *nextptr;
} Lista, *ptr;

//prototipi
void initialize(Lista **ptrPtr);
void stampa_lista_rec(Lista *l);
_Bool isEmpty(Lista *l);
void pre_insert(Lista **ptrPtr, int val);
void suf_insert(Lista **ptrPtr, int val);
void suf_insert_rec(Lista **ptrPtr, int val);
void delete_element(Lista **ptrPtr, unsigned int pos);
unsigned int conta_elementi(Lista *ptrPtr);
void lista_inversa_rec(Lista *l); //non ha funzionato

// MAIN

int main()
{

    ptr l;
    ptr s;

    l = malloc(sizeof(Lista));
    (*l).valore = 2; //l->val=2
    (*l).nextptr = malloc(sizeof(Lista));
    (*(*l).nextptr).valore = -9; //(*(l->next->val))

    (*(*l).nextptr).nextptr = malloc(sizeof(Lista));
    (*(*(*l).nextptr).nextptr).valore = 1;
    (*(*(*l).nextptr).nextptr).nextptr = NULL;

    stampa_lista_rec(l);
    printf("La lista iniziale è:\n");
    stampa_lista_rec(l);
    printf("\n");
    pre_insert(&l, 5);
    printf("La lista dopo aver inserito un nuovo elemento in testa è:\n");
    stampa_lista_rec(l);
    printf("\n");
    suf_insert(&l, 6);
    printf("La lista dopo aver inserito un nuovo elemento in coda è:\n");
    stampa_lista_rec(l);
    printf("\n");
    suf_insert_rec(&l, 7);
    printf("La lista dopo aver inserito in coda con ricorsione è:\n");
    stampa_lista_rec(l);
    printf("\n");
    delete_element(&l, 2);
    stampa_lista_rec(l);
    printf("\n");
    printf("In totale ci sono %d elementi", conta_elementi(l));
    printf("\n");
    printf("La lista inversa è:\n");
    lista_inversa_rec(l);
}
//FUNZIONI DA USARE NEL MAIN
void initialize(Lista **ptrPtr)
{ //il puntatore non punta a nulla dall'inzio
    *ptrPtr = NULL;
}

void stampa_lista_rec(Lista *l)
{ //STAMPA GLI ELEMENTI DELLA LISTA
    Lista *s;

    s = l;
    if (s != NULL)
    {
        printf("%d ", s->valore);
        //s=s->next;
        stampa_lista_rec(s->nextptr);
    }
}

void pre_insert(Lista **ptrPtr, int val)
{ //INSERISCE GLI ELEMENTI IN TESTA
    Lista *tmpPtr;
    tmpPtr = *ptrPtr;
    *ptrPtr = malloc(sizeof(Lista));
    (*ptrPtr)->valore = val;
    (*ptrPtr)->nextptr = tmpPtr;
}

void suf_insert(Lista **ptrPtr, int val)
{ //INSERISCE GLI ELEMENTI IN CODA
    while (*ptrPtr != NULL)
    {
        ptrPtr = &((*ptrPtr)->nextptr);
    }

    pre_insert(ptrPtr, val);
}

void suf_insert_rec(Lista **ptrPtr, int val)
{ //INSERISCE ELEMENTI IN CODA CON RICORSIONE

    if (*ptrPtr != NULL)
    {
        suf_insert_rec(&((*ptrPtr)->nextptr), val);
    }
    else
    {
        pre_insert(ptrPtr, val);
    }
}

_Bool isEmpty(Lista *l)
{ //CONTROLLA SE LA LISTA E' VUOTA

    if (l == NULL)
        return false;
    return true;
}

void delete_element(Lista **l, unsigned int pos)
{ //CANCELLA UN ELEMENTO IN UNA CERTA POSIZIONE
    if (*l == NULL)
    { //la lista è vuota
        return;
    }
    if (pos == 0)
    {
        Lista *new_ptr = (*l)->nextptr; //nella prima posizione viene messo l'elemento dopo
        free(*l);                       //viene liberato lo spazio che conteneva il primo elemento eliminato
        *l = new_ptr;
        return;
    }
    Lista *last = (*l);
    while (last->nextptr != NULL && pos > 1)
    {
        last = last->nextptr; //last->nextptr sovrascrive il valore di last
        pos--;
    }
    if (pos == 1 && last->nextptr != NULL)
    {
        Lista *new_ptr = (last->nextptr)->nextptr;
        free(last->nextptr);
        last->nextptr = new_ptr;
    }
}

unsigned int conta_elementi(Lista *ptrPtr)
{ //CONTA QUANTI ELEMENTI CI SONO IN UNA LISTA
    unsigned int i = 0;
    while (ptrPtr != NULL)
    {
        i++;
        ptrPtr = ptrPtr->nextptr;
    }
    return i;
}

void lista_inversa_rec(Lista *l)
{
    if (l != NULL)
    {
        lista_inversa_rec(l->nextptr);
        printf("%d ", l->valore);
    }
}
