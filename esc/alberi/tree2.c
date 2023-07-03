#include <stdio.h>
#include <stdlib.h>

struct btree
{
    int value;
    struct btree *sx;
    struct btree *dx;
};

typedef struct btree tree;

void insert(tree **l, int k);
void search(tree *l, int k);

int main()
{
    tree *l = NULL;
    for (int i = 0; i < 3; i++)
    {
        int item = i;
        insert(&l, item);
    }

    //int k = 2;
    search(l, 2);
}

void insert(tree **l, int k)
{
    if (*l == NULL)
    {
        *l = malloc(sizeof(tree));
        (*l)->value = k;
        (*l)->sx = NULL;
        (*l)->dx = NULL;
    }
    else if (*l != NULL && (*l)->value < k)
    {
        insert(&((*l)->dx), k);
    }
    else if (*l != NULL && (*l)->value > k)
    {
        insert(&((*l)->sx), k);
    }
    else
    {
        printf("Dup");
    }
}

void search(tree *l, int k)
{
    if (l == NULL)
    {
        printf("Empty\n");
    }
    if (l != NULL && k == l->value)
    {
        printf("Found\n");
    }
    else if (l != NULL && k > l->value)
    {
        search(l->dx, k);
    }
    else if (l != NULL && k < l->value)
    {
        search(l->sx, k);
    }
    else
    {
        printf("Not found\n");
    }
}