#include <stdio.h>
#include <stdlib.h>

struct btree
{
    int value;
    struct btree *sx;
    struct btree *dx;
};

typedef struct btree Tree;
// typedef Tree *T;

void insert(Tree **l, int k);
void inorder(Tree *l);
void postorder(Tree *l);
void preorder(Tree *l);
void search(Tree *l, int k);

int main()
{
    Tree *l = NULL;
    for (int i = 0; i < 3; i++)
    {
        int item = i;
        insert(&l, item);
    }

    printf("Inorder: ");
    inorder(l);

    printf("\npostorder: ");
    postorder(l);

    printf("\npreorder: ");
    preorder(l);

    printf("\nsearch: ");
    int s = 2;
    search(l, s);
}

void insert(Tree **l, int k)
{
    if (*l == NULL)
    {
        *l = malloc(sizeof(Tree));
        (*l)->value = k;
        (*l)->sx = NULL;
        (*l)->dx = NULL;
    }
    else if (*l != NULL && k > (*l)->value)
    {
        insert(&((*l)->dx), k);
    }
    else if (*l != NULL && k < (*l)->value)
    {
        insert(&((*l)->sx), k);
    }
    else
    {
        printf("Dup");
    }
}

void search(Tree *l, int k)
{
    if (l != NULL && l->value == k)
    {
        printf("Found\n");
    }
    else if (l != NULL && l->value > k)
    {
        search(l->sx, k);
    }
    else if (l != NULL && l->value < k)
    {
        search(l->dx, k);
    }
    else
    {
        printf("Not found\n");
    }
}

void inorder(Tree *l)
{
    if (l != NULL)
    {
        inorder(l->sx);
        printf("%3d", l->value);
        inorder(l->dx);
    }
}

void postorder(Tree *l)
{
    if (l != NULL)
    {
        postorder(l->sx);
        postorder(l->dx);
        printf("%3d", l->value);
    }
}

void preorder(Tree *l)
{
    if (l != NULL)
    {
        printf("%3d", l->value);
        preorder(l->sx);
        preorder(l->dx);
    }
}