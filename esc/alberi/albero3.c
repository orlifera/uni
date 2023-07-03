#include <stdio.h>
#include <stdlib.h>

struct btree
{
    int value;
    struct btree *sx;
    struct btree *dx;
};

typedef struct btree Tree;
typedef Tree *T;

void insert(T *l, int k);
void preorder(T l);
void postorder(T l);
void inorder(T l);
void search(T l, int k);

int main()
{

    T l = NULL;
    for (int i = 0; i < 5; i++)
    {
        int item = i;
        //scanf("%d", &item);
        insert(&l, item);
    }

    printf("\nTree in preorder traversal is: ");
    preorder(l);

    printf("\nTree in postorder traversal is: ");
    postorder(l);

    printf("\nTree in order traversal is: ");
    inorder(l);

    printf("\nEnter item to be searched: ");
    int k = 3;
    //scanf("%d", &k);
    search(l, k);
}

void inorder(T l)
{
    if (l != NULL)
    {
        inorder(l->sx);
        printf("%3d", l->value);
        inorder(l->dx);
    }
}

void postorder(T l)
{
    if (l != NULL)
    {
        postorder(l->sx);
        postorder(l->dx);
        printf("%3d", l->value);
    }
}

void preorder(T l)
{
    if (l != NULL)
    {
        printf("%3d", l->value);
        preorder(l->sx);
        preorder(l->dx);
    }
}

void insert(T *l, int k)
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

void search(T l, int k)
{
    if (l != NULL && k == l->value)
    {
        printf("Item found!\n");
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
        printf("Item not found\n");
    }
}