#include <stdio.h>
#include <stdlib.h>

struct list
{
    int val;
    struct list *next;
};
typedef struct list L;

void sufinsert(L **l, int k);
void print(L *l);
void conc(L **l, L *s);

int main()
{
    L *l = NULL;
    L *s = NULL;
    for (int i = 0; i < 6; i++)
    {
        sufinsert(&l, i);
    }
    for (int j = 5; j < 10; j++)
    {
        sufinsert(&s, j);
    }
    printf("list l is: ");
    print(l);
    printf("\n");
    printf("List s is: ");
    print(s);
    conc(&l, s);
    printf("\n");
    print(l);
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
        printf("%d ", l->val);
        print(l->next);
    }
}

void conc(L **l, L *s)
{
    if (s == NULL)
    {
        return;
    }

    if ((*l)->next == NULL)
    {
        sufinsert(l, s->val);
        conc(&((*l)->next), s->next);
    }
    else
    {
        conc(&((*l)->next), s);
    }
}
