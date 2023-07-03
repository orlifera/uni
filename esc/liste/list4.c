#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int value;
    struct lista *next;
};

typedef struct lista Lista;

void preinsert(Lista **l, int k);
void sufinsert(Lista **l, int k);
void delete (Lista **l, int k);
void clone(Lista *l, Lista **c);
void search(Lista *l, int k);
void print(Lista *l);

int main()
{
    Lista *l = NULL;
    Lista *s = NULL;
    Lista *c = NULL;

    for (int i = 0; i < 3; i++)
    {
        int item = i;
        sufinsert(&l, item);
        preinsert(&c, item);
    }

    printf("Preinsert: ");
    print(c);

    printf("\nSufinsert: ");
    print(l);

    printf("\nDelete: ");
    int d = 1;
    delete (&l, d);
    print(l);

    printf("\nSearch: ");
    int a = 2;
    search(l, a);

    printf("\nCloning");
    clone(l, &s);
}

void print(Lista *l)
{
    if (l->next != NULL)
    {
        printf("%d  ->  ", l->value);
        print(l->next);
    }
    else
    {
        printf("%d  ->  //", l->value);
    }
}

void preinsert(Lista **l, int k)
{
    Lista *temp;
    temp = *l;
    *l = malloc(sizeof(Lista));
    (*l)->value = k;
    (*l)->next = temp;
}

void sufinsert(Lista **l, int k)
{
    if (l == NULL)
    {
        Lista *temp;
        temp = *l;
        *l = malloc(sizeof(Lista));
        (*l)->value = k;
        (*l)->next = temp;
    }
    else
    {
        sufinsert(&((*l)->next), k);
    }
}

void delete (Lista **l, int k)
{
    Lista *temp;
    temp = *l;
    if (*l == NULL)
    {
        printf("Empty\n");
    }
    else if (*l != NULL && (*l)->value == k)
    {
        temp = (*l)->next;
        free(*l);
        *l = temp;
    }
    else if (*l != NULL && (*l)->value != k)
    {
        delete (&((*l)->next), k);
    }
    else
    {
        printf("Not found\n");
    }
}

void clone(Lista *l, Lista **s)
{
    *s = malloc(sizeof(Lista));
    if (l != NULL)
    {
        (*s)->value = l->value;
        clone(l->next, &(*s)->next);
    }
}