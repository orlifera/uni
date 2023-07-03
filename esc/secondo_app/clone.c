#include <stdio.h>
#include <stdlib.h>

struct list
{
    int val;
    struct list *next;
};
typedef struct list L;

void sufinsert(L **l, int k);
void clone(L *l, L **s);
void print(L *l);
int main()
{
    L *l = NULL;
    L *s = NULL;
    for (int i = 0; i < 6; i++)
    {
        sufinsert(&l, i);
    }
    print(l);
    printf("\n");
    clone(l, &s);
    print(s);
}
void print(L *l)
{
    if (l != NULL)
    {
        printf("%d ", l->val);
        print(l->next);
    }
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

void clone(L *l, L **s)
{
    if (l != NULL)
    {
        *s = malloc(sizeof(L));
        (*s)->val = l->val;
        clone(l->next, &((*s)->next));
    }
}