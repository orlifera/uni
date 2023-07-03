#include <stdio.h>
#include <stdlib.h>

struct bTree
{
    int value;
    struct bTree *sx;
    struct bTree *dx;
};

typedef struct bTree BT;

void insert(BT **T, int x);
void search(BT *T, int x);
void preorder(BT *T);
void inorder(BT *T);
void postorder(BT *T);

int main()
{
    BT *T = NULL;

    for (int i = 0; i < 6; i++)
    {
        insert(&T, i);
    }

    printf("PreOrder is: ");
    preorder(T);
    printf("\nInOrder is: ");
    inorder(T);
    printf("\nPostOrder is: ");
    postorder(T);

    search(T, 4);
}

void preorder(BT *T)
{
    if (T != NULL)
    {
        printf("%d -> ", T->value);
        preorder(T->sx);
        preorder(T->dx);
    }
}

void inorder(BT *T)
{
    if (T != NULL)
    {
        inorder(T->sx);
        printf("%d -> ", T->value);
        inorder(T->dx);
    }
}

void postorder(BT *T)
{
    if (T != NULL)
    {
        postorder(T->sx);
        postorder(T->dx);
        printf("%d -> ", T->value);
    }
}

void search(BT *T, int x)
{
    if (T != NULL && x == T->value)
    {
        printf("Item found!\n");
    }
    else if (T != NULL && x > T->value)
    {
        search(T->dx, x);
    }
    else if (T != NULL && x < T->value)
    {
        search(T->sx, x);
    }
    else
    {
        printf("Item not found\n");
    }
}

void insert(BT **T, int x)
{
    if (*T == NULL)
    {
        *T = malloc(sizeof(BT));
        (*T)->value = x;
        (*T)->sx = NULL;
        (*T)->dx = NULL;
    }
    else if ((*T) != NULL && (*T)->value < x)
    {
        insert(&((*T)->dx), x);
    }
    else if ((*T) != NULL && (*T)->value > x)
    {
        insert(&((*T)->sx), x);
    }
    else
    {
        printf("DUP");
    }
}
