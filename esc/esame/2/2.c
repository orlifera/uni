#include <stdio.h>
#include <stdlib.h>

struct list
{
    int val;
    struct list *next;
};
typedef struct list L;

void clone(L *l, L **s);
void insert(L **l, int k);
void print(L *l);
int search(L *l, int k);
void delete(L **l, int k);

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
    printf("\n");
    printf("%d\n", search(l, 3));
    delete (&l, 3);
    print(l);
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

int search(L *l, int k)
{
    if (l != NULL && l->val == k)
    {
        return 1;
    }
    else if (l != NULL && l->val != k)
    {
        return search(l->next, k);
    }
    else
    {
        return 0;
    }
}

void insert(L **l, int k)
{
    L *temp = *l;
    *l = malloc(sizeof(L));
    (*l)->val = k;
    (*l)->next = temp;
}

void print(L *l)
{
    if (l != NULL)
    {
        printf("%d ", l->val);
        print(l->next);
    }
}

void delete(L **l, int k)
{
    L *temp = (*l)->next;
    if (*l != NULL && (*l)->val == k)
    {
        free(*l);
        *l = temp;
    }
    else if (*l != NULL && (*l)->val != k)
    {
        delete (&((*l)->next), k);
    }
    else
    {
        return;
    }
}