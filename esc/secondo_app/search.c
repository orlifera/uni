#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int val;
    struct tree *sx, *dx;
};

typedef struct tree T;

int search(T *t, int k);
void insert(T **t, int k);

int main()
{
    T *t = NULL;
    for (int i = 0; i < 6; i++)
    {
        insert(&t, i);
    }
    int c = search(t, 3);
    if (c)
    {
        puts("found");
    }
    else
    {
        puts("bruh");
    }
}

void insert(T **t, int k)
{
    if (*t == NULL)
    {
        *t = malloc(sizeof(T));
        (*t)->val = k;
        (*t)->sx = NULL;
        (*t)->dx = NULL;
    }
    else if (*t != NULL && (*t)->val < k)
    {
        insert(&((*t)->dx), k);
    }
    else if (*t != NULL && (*t)->val > k)
    {
        insert(&((*t)->sx), k);
    }
    else
    {
        puts("Dup");
    }
}

int search(T *t, int k)
{

    if (t != NULL && t->val == k)
    {
        return 1;
    }
    else if (t != NULL && t->val < k)
    {
        return search(t->dx, k);
    }
    else if (t != NULL && t->val > k)
    {
        return search(t->sx, k);
    }
    else
    {
        return 0;
    }
}