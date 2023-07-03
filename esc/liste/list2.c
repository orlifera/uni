#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int value;
    struct lista *next;
};

typedef struct lista L;

void sufinsert(L **l, int k);
void preinsert(L **l, int k);
void delete (L **l, int k);
void search(L *l, int k);
void print(L *l);
void clone(L *l, L **c);

int main()
{
    L *s = NULL;
    L *c = NULL;
    L *l = NULL;

    for (int i = 0; i < 5; i++)
    {
        int item = i;
        preinsert(&l, item);
        sufinsert(&s, item);
    }

    printf("\nList with preinsert is: ");
    print(l);

    printf("\nList with postinsert is: ");
    print(s);

    printf("\nEnter item to search: ");
    int k;
    scanf("%d", &k);
    search(l, k);

    printf("Enter item to delete: ");
    int a;
    scanf("%d", &a);
    delete (&l, k);
    printf("new list is: ");
    print(l);

    printf("Cloning list...");
    clone(l, &c);
    print(c);
}

void print(L *l)
{
    if (l->next != NULL)
    {
        printf("%3d  ->  ", l->value);
        print(l->next);
    }
    else
    {
        printf("%3d  ->  //", l->value);
    }
}

void preinsert(L **l, int k)
{
    L *temp;
    temp = *l;
    *l = malloc(sizeof(L));
    (*l)->value = k;
    (*l)->next = temp;
}

void sufinsert(L **l, int k)
{
    if (*l == NULL)
    {
        L *temp;
        temp = *l;
        *l = malloc(sizeof(L));
        (*l)->value = k;
        (*l)->next = temp;
    }
    else
    {
        sufinsert(&((*l)->next), k);
    }
}

void delete (L **l, int k)
{
    L *temp;
    temp = *l;
    if (*l == NULL)
    {
        printf("List is empty\n");
    }
    if (*l != NULL && (*l)->value == k)
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

void clone(L *l, L **s)
{
    *s = malloc(sizeof(L));
    if (l != NULL)
    {
        (*s)->value = l->value;
        clone(l->next, &(*s)->next);
    }
}

void search(L *l, int k)
{
    if (l != NULL && l->value == k)
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