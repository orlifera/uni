#include <stdio.h>
#include <stdlib.h>

struct list
{
    int val;
    struct list *next;
};

typedef struct list L;

L *firstodd(L *l);
L *firstrec(L *l);
void preinsert(L **l, int k);
void print(L *l);

int main()
{
    L *l = NULL;
    for (int i = 0; i < 7; i++)
    {
        preinsert(&l, i);
    }
    for (int i = 2; i < 10; i++)
    {
        preinsert(&l, i);
    }
    print(l);
    printf("\n");
    printf("%d", firstodd(l)->val);
}
void print(L *l)
{
    if (l != NULL)
    {
        printf("%d", l->val);
        print(l->next);
    }
}

void preinsert(L **l, int k)
{
    L *temp;
    temp = *l;
    *l = malloc(sizeof(L));
    (*l)->val = k;
    (*l)->next = temp;
}

L *firstodd(L *l)
{
    L *min = l;
    if (!l)
    {
        return NULL;
    }
    while (l->next != NULL)
    {
        if (l->val < min->val && l->val % 2 != 0)
        {
            min->val = l->val;
        }
        l = l->next;
    }
    return min;
}

L *firstrec(L *l)
{
    if (!l)
    {
        return NULL;
    }
    L *min = firstrec(l->next);
    if (l->val < min->val && l->val % 2 != 0 || !min)
    {
        return l;
    }
    return min;
}