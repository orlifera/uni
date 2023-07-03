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
    Lista *c = NULL;
    Lista *s = NULL;

    for (int i = 0; i < 3; i++)
    {
        int item = i;
        sufinsert(&l, item);
        preinsert(&c, item);
    }

    printf("\nSufinsert: ");
    print(l);

    printf("\npreinsert: ");
    print(c);

    printf("\nSearch: ");
    int k = 2;
    //scanf("%d", &k);
    search(l, k);

    printf("\nDelete: ");
    int d = 2;
    //scanf("%d", &d);
    delete (&l, k);

    printf("\nNew list: ");
    print(l);

    printf("Clone: ");
    clone(l, &s);
    print(s);
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

void search(Lista *l, int k)
{
    if (l == NULL)
    {
        printf("List is empty\n");
    }
    else if (l != NULL && l->value == k)
    {
        printf("Item found\n");
    }
    else if (l != NULL && l->value != k)
    {
        search(l->next, k);
    }
    else
    {
        printf("Item not found\n");
    }
}

void clone(Lista *l, Lista **c)
{
    *c = malloc(sizeof(Lista));
    if (l != NULL)
    {
        (*c)->value = l->value;
        clone(l->next, &(*c)->next);
    }
}

void delete (Lista **l, int k)
{
    Lista *temp;
    temp = *l;
    if (*l == NULL)
    {
        printf("List is empty\n");
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
        printf("Item not found\n");
    }
}