/*
Un ABT è un albero i cui sottoalberi di destra hanno valore maggiore dell'albero padre e i sottoalberi
di sinistra hanno sempre valore minore dell'albero padre. Inoltre i due sottoalberi dx e sx devono essere
a loro volta ABT. */
#include <stdio.h>
#include <stdlib.h>

struct Btree
{
    int val;
    struct Btree *sx, *dx;
};

typedef struct Btree T;

void inorder(T *t);
void ordinsert(T **t, int k);
int main()
{
    T *t = NULL;
    for (int i = 0; i < 5; i++)
    {
        ordinsert(&t, i);
    }
    inorder(t);
}

void ordinsert(T **t, int k)
{
    if (*t != NULL)
    {
        if ((*t)->val < k)
        {
            ordinsert(&((*t)->dx), k);
        }
        else if ((*t)->val > k)
        {
            ordinsert(&((*t)->sx), k);
        }
        else
        {
            puts("Dup");
        }
    }
    else
    {
        *t = malloc(sizeof(T));
        (*t)->val = k;
        (*t)->sx = NULL;
        (*t)->dx = NULL;
    }
}

void inorder(T *t)
{
    if (t != NULL)
    {
        inorder(t->sx);
        printf("%d", t->val);
        inorder(t->dx);
    }
}