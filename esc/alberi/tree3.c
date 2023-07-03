#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int val;
    struct nodo *sx, *dx;
};
typedef struct nodo NODO;
typedef NODO T;

void preorder(T *t);
void inorder(T *t);
void postorder(T *t);
void insert(T **t, int x);
void search(T *t, int x);
int Sum(T *t);

int main()
{
    T *t = NULL;
    for (int i = 0; i < 5; i++)
    {
        insert(&t, i);
    }

    printf("PreOrder is: ");
    preorder(t);
    printf("\nInOrder is: ");
    inorder(t);
    printf("\nPostOrder is: ");
    postorder(t);
    search(t, 4);
    // printf("max is: %d", Max(t));
    printf("Sum is: %d", Sum(t));
}

int Sum(T *t)
{
    int s = 0;
    if (t != NULL)
    {
        s = t->val + Sum(t->sx) + Sum(t->dx);
    }
    return s;
}

void insert(T **t, int x)
{
    if (*t == NULL)
    {
        *t = malloc(sizeof(T));
        (*t)->val = x;
        (*t)->sx = NULL;
        (*t)->dx = NULL;
    }
    else if (*t != NULL && (*t)->val > x)
    {
        insert(&((*t)->sx), x);
    }
    else if (*t != NULL && (*t)->val < x)
    {
        insert(&((*t)->dx), x);
    }
    else
    {
        puts("DUP");
    }
}

void preorder(T *t)
{
    if (t != NULL)
    {
        printf("%3d -> ", t->val);
        preorder(t->sx);
        preorder(t->dx);
    }
}

void inorder(T *t)
{
    if (t != NULL)
    {
        inorder(t->sx);
        printf("%3d -> ", t->val);
        inorder(t->dx);
    }
}

void postorder(T *t)
{
    if (t != NULL)
    {
        postorder(t->sx);
        postorder(t->dx);
        printf("%3d -> ", t->val);
    }
}

void search(T *t, int x)
{
    if (t != NULL && x == t->val)
    {
        printf("Item found\n");
    }
    else if (t != NULL && t->val > x)
    {
        search(t->sx, x);
    }
    else if (t != NULL && t->val < x)
    {
        search(t->dx, x);
    }
    else
    {
        printf("Item not found\n");
    }
}
