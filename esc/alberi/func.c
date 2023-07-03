#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DIM 10
struct btree
{
    int value;
    struct btree *sx;
    struct btree *dx;
};
typedef struct btree Tree;
typedef Tree *T;

void insert(T *l, int k);
int search(T l, int k);
void preorder(T l);
void inorder(T l);
void postorder(T l);

int main()
{
    T l = NULL;

    printf("Please wait, inserting random numbers\n...\n...\n...\n");
    for (int i = 0; i < DIM; i++)
    {
        int item = (i + 3) * (DIM - 2);
        printf("Item is: %d\t", item);
        insert(&l, item);
    }

    printf("Choose an option:\n1. Search an item\n2. Preorder traversal\n3. Inorder traversal\n4. Postorder traversal\n5. End");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter item to search for: ");
        int k;
        scanf("%d", &k);
        //search(l, k);
        if (search(l, k) == 1)
        {
            printf("Item found\n");
        }
        else
        {
            printf("Item not found\n");
        }
    }
    if (choice == 2)
    {

        printf("Tree with preorder traversal is: ");
        preorder(l);
    }
    if (choice == 3)
    {
        printf("Tree with inorder traversal is: ");
        inorder(l);
    }
    if (choice == 4)
    {
        printf("Tree with postorder traversal is: ");
        postorder(l);
    }
}

void insert(T *l, int k)
{
    if ((*l) == NULL)
    {
        (*l) = malloc(sizeof(Tree));
        (*l)->value = k;
        (*l)->sx = NULL;
        (*l)->dx = NULL;
    }
    else if (k > (*l)->value)
    {
        insert(&((*l)->dx), k);
    }
    else if (k < (*l)->value)
    {
        insert(&((*l)->sx), k);
    }
    else
    {
        puts("Dup");
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

int search(T l, int k)
{
    if (k == l->value)
    {
        return 1;
    }
    else if (k > l->value)
    {
        search(l->dx, k);
    }
    else if (k < l->value)
    {
        search(l->sx, k);
    }
    else
    {
        return 0;
    }
}

void insert(T *l, int k)
{
    if (*l == NULL)
    {
        l = malloc(sizeof(Tree));

        (*l)->value = k;
        (*l)->sx = NULL;
        (*l)->dx = NULL;
    }
    else if (k > (*l)->value)
    {
        insert(&(((*l)->dx)), k);
    }
    else if (k < (*l)->value)
    {
        insert(&(((*l)->sx)), k);
    }
    else
    {
        puts("Dup");
    }
}