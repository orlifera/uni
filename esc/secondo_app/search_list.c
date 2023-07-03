#include <stdio.h>
#include <stdlib.h>

struct list
{
    int val;
    struct list *next;
};
typedef struct list L;

int search(L *l, int k);
void preinsert(L **l, int k);
void print(L *l);
void delete(L **l, int k);

int main()
{
    L *l = NULL;
    for (int i = 0; i < 6; i++)
    {
        preinsert(&l, i);
    }
    print(l);
    printf("\n");
    int c = search(l, 3);
    if (c)
    {
        printf("found\n");
    }

    delete (&l, 4);
    print(l);
}

void preinsert(L **l, int k)
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
        printf("%d ", l->val);
        print(l->next);
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

void delete(L **l, int k)
{
    L *temp = *l;
    if (*l != NULL && (*l)->val == k)
    {
        temp = (*l)->next;
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