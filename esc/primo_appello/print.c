#include <stdio.h>
#include <stdlib.h>

struct list
{
    int val;
    struct list *next;
};

typedef struct list L;
void print(L *l);
void preinsert(L **l, int k);
void ordinsert(L **l, int k);

int main()
{
    L *l = NULL;
    for (int i = 0; i < 6; i++)
    {
        preinsert(&l, i);
    }

    print(l);
    printf("\n");
    ordinsert(&l, 3);
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
        print(l->next);
        printf("%d ", l->val);
    }
}

void ordinsert(L **l, int k)
{
    if (*l != NULL && (*l)->val > k)
    {
        ordinsert(&((*l)->next), k);
    }
    else
    {
        preinsert(l, k);
    }
}