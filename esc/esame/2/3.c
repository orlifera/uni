#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int val;
    struct tree *sx;
    struct tree *dx;
};
typedef struct tree T;

int search(T *t, int k);
void insert(T **t, int k);
void preorder(T *t);
void postorder(T *t);
void inorder(T *t);

int main()
{
    T *t = NULL;
    for (int i = 0; i < 7; i++)
    {
        int c;
        scanf("%d", &c);
        insert(&t, c);
    }
    inorder(t);
    printf("\n");
    preorder(t);
    printf("\n");
    postorder(t);
    int c = search(t, 3);
    if (c)
    {
        puts("Yes");
    }
}

void inorder(T *t)
{
    if (t != NULL)
    {
        inorder(t->sx);
        printf("%3d ", t->val);
        inorder(t->dx);
    }
}
void postorder(T *t)
{
    if (t != NULL)
    {
        postorder(t->sx);
        postorder(t->dx);
        printf("%3d ", t->val);
    }
}
void preorder(T *t)
{
    if (t != NULL)
    {
        printf("%3d ", t->val);
        preorder(t->sx);
        preorder(t->dx);
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

void insert(T **t, int k)
{
    if (*t == NULL)
    {
        *t = malloc(sizeof(T));

        (*t)->val = k;
        (*t)->sx = NULL;
        (*t)->sx = NULL;
    }
    else
    {
        if (k > (*t)->val)
        {
            insert(&((*t)->dx), k);
        }
        else if (k < (*t)->val)
        {
            insert(&((*t)->sx), k);
        }
        else
        {
            printf("DUP");
        }
    }
}