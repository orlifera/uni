#include <stdio.h>
#include <stdlib.h>

struct list
{
    int val;
    struct list *next;
};
typedef struct list L;

void print(L *l);
void insert(L **l, int k);
void ord_insert(L **l, int k);
void clone(L *l, L **s);
int main()
{
    L *l = NULL;
    L *s = NULL;
    for (int i = 0; i < 6; i++)
    {
        insert(&l, i);
    }
    print(l);
    printf("\n");
    clone(l, &s);
    print(s);
    // ord_insert(&l, 19);
    // print(l);
    // printf("\n");
}

void insert(L **l, int k)
{
    L *temp;
    temp = *l;
    *l = malloc(sizeof(L));
    (*l)->val = k;
    (*l)->next = temp;
}

void print(L *l)
{
    if (l != NULL)
    {
        print(l->next);
        printf("%d ", l->val);
    }
}

void ord_insert(L **l, int k)
{
    if (*l == NULL)
    {
        insert(l, k);
    }
    else if (*l != NULL && (*l)->val < k)
    {
        insert(l, k);
    }
    else
    {
        ord_insert(&((*l)->next), k);
    }
}

void clone(L *l, L **s)
{
    if (l != NULL)
    {
        while (l->next != NULL)
        {
            *s = malloc(sizeof(L));
            (*s)->val = l->val;
            l = l->next;
            *s = (*s)->next;
        }
    }
}