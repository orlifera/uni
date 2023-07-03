#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int value;
    struct lista *next;
};
typedef struct lista Lista;

void sufinsert(Lista **l, int k);
void preinsert(Lista **l, int k);
void delete (Lista **l, int k);
void search(Lista *l, int k);
void print(Lista *l);
void clone(Lista *l, Lista **s);

int main()
{
    Lista *l = NULL;
    Lista *c = NULL;
    Lista *s = NULL;

    for (int i = 0; i < 3; i++)
    {
        int item = i;
        preinsert(&l, item);
        sufinsert(&c, item);
    }

    printf("Preinsert: ");
    print(l);

    printf("\nSufinsert: ");
    print(c);

    printf("\nDelete: ");
    delete (&l, 2);
    printf("\nNew list: ");
    print(l);

    printf("Search: ");
    search(l, 2);

    printf("Clone: ");
    clone(l, &s);
    print(s);
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
    if (*l == NULL)
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

    if (*l != NULL && k == (*l)->value)
    {
        temp = (*l)->next;
        free(*l);
        *l = temp;
    }
    else if (*l != NULL && k != (*l)->value)
    {
        delete (&((*l)->next), k);
    }
    else
    {
        printf("Not found\n");
        return;
    }
}

void search(Lista *l, int k)
{

    if (l != NULL && l->value == k)
    {
        printf("Item found\n");
    }
    else if (l != NULL && k != l->value)
    {
        search(l->next, k);
    }
    else
    {
        printf("Item not found\n");
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