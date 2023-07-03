#include <stdlib.h>
#include <stdio.h>

struct lista
{
    int val;
    struct lista *next;
};
typedef struct lista L;

void pre_insert(L **l, int k);
void print(L *l);
void isPrime(L **l, L **s);

int main()
{
    L *l = NULL;
    L *s = NULL;

    for (int i = 2; i < 7; i++)
    {
        pre_insert(&l, i);
        isPrime(&l, &s);
    }
    print(s);
}

void pre_insert(L **l, int k)
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
        pre_insert(&((*l)->next), k);
    }
}

void print(L *l)
{
    if (l->next != NULL)
    {
        printf("%d -> ", l->val);
        print(l->next);
    }
    else
    {
        printf("%d -> //\n", l->val);
    }
}

void isPrime(L **l, L **s)
{
    int counter = 0;
    for (int j = 2; j < (*l)->val; j++)
    {
        if ((*l)->val % j == 0)
        {
            counter++;
        }
    }
    if (counter == 0)
    {
        pre_insert(s, (*l)->val);
        *l = (*l)->next;
        return;
    }
    else
    {
        return;
    }
}
