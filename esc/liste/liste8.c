#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista
{
    int val;
    struct lista *next;
} Lista;

typedef Lista *L;

void insert_testa(Lista **l, int valore);
void insert_coda(Lista **l, int valore);
void insert_coda_ric(Lista **l, int valore);
void delete (Lista **l, unsigned int pos);
void print(Lista *l);

int main()
{
    Lista *ptr = malloc(sizeof(Lista));
    ptr->val = 2;
    ptr->next = NULL;
    insert_coda(&ptr, 3);
    print(ptr);
}

void insert_testa(Lista **l, int valore)
{
    Lista *tmpPtr;
    tmpPtr = *l;
    *l = malloc(sizeof(Lista));
    (*l)->val = valore;
    (*l)->next = tmpPtr;
}
void insert_coda(Lista **l, int valore)
{
    while ((*l)->next != NULL)
    {
        l = &((*l)->next);
        (*l)->next = NULL;
    }
    insert_testa(l, valore);
}

void insert_coda_ric(Lista **l, int valore)
{
    if (*l != NULL)
    {
        insert_coda_ric(&((*l)->next), valore);
    }
    else
    {
        insert_testa(l, valore);
    }
}

void delete (Lista **l, unsigned int pos)
{
    if (*l == NULL)
    {
        printf("La lista è vuota coglione.\n");
        return;
    }
    else
    {
        if (pos == 0)
        {
            Lista *nPtr = ((*l)->next);
            free(*l);
            *l = nPtr;
        }
        else if (pos == 1 && *l != NULL)
        {
            Lista *ptr = ((*l)->next->next);
            free((*l)->next);
            (*l)->next = ptr;
        }
        Lista *last;
        last = *l;
        while (pos > 1 && last->next != NULL)
        {
            last = last->next;
            pos--;
        }
    }
}
void print(Lista *l)
{
    if (l != NULL)
    {
        printf("%d", l->val);
        print(l->next);
    }
}