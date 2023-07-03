#include <stdio.h>
#include <stdlib.h>

struct list
{
    int val;
    struct list *next;
};
typedef struct list L;

void clone(L *l, L **s);
void print(L *l);
void sufinsert(L **l, int k);

int main()
{
    L *l = NULL, *s = NULL;
    for (int i = 0; i < 5; i++)
    {
        sufinsert(&l, i);
    }

    print(l);
    printf("\ncloning...");
    clone(l, &s);
    print(s);
}

void sufinsert(L **l, int k)
{
    if (*l == NULL)
    {
        L *temp;
        temp = *l;
        *l = malloc(sizeof(L));
        (*l)->val = k;
        (*l)->next = temp;
    }
    else
    {
        sufinsert(&((*l)->next), k);
    }
}

void print(L *l)
{
    if (l != NULL)
    {
        printf("%d, ", l->val);
        print(l->next);
    }
}

void clone(L *l, L **s)
{
    if (l != NULL)
    {
        *s = malloc(sizeof(L));
        (*s)->val = l->val;
        clone(l->next, &((*s)->next));
    }
}