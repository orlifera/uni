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
void clone(L *l, L **s);
void print(L *l);
void delete (L **l, int k);

int main()
{
    L *l = NULL;
    L *s = NULL;
    L *c = NULL;
    for (int i = 0; i < 5; i++)
    {
        int item = i + 5;
        sufinsert(&l, item);
        preinsert(&s, item);
    }

    printf("List with pre insertion is: ");
    print(s);

    printf("List with post insertion is: ");
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
        printf("%3d  ->  //\n", l->value);
    }
}

void clone(L *l, L **s)
{
    *s = malloc(sizeof(L));
    if (l != NULL)
    {
        (*s)->value = l->value;
        clone(l->next, &((*s)->next));
    }
    else
    {
        printf("List empty\n");
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