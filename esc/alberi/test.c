#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct btree
{
    int value;
    struct btree *leftptr;
    struct btree *rightptr;
};
typedef struct btree tree;
typedef tree *T;

void insert(T *l, int item);
void preorder(T l);
void inorder(T l);
void postorder(T l);

int main()
{
    T root = NULL;

    //srand(time(NULL));

    printf("Random numbers will be entered in the tree. If two numbers are equal, they will be marked as 'dup'\n");

    for (int i = 0; i < 10; i++)
    {
        int item = i; //rand() % 15;
        printf("Number entered is: %3d\n", item);
        insert(&root, item);
    }

    printf("\n\nTree in order is: ");
    inorder(root);

    printf("\n\nTree in postorder is: ");
    postorder(root);

    printf("\n\nTree in preorder is: ");
    preorder(root);
}

void insert(T *l, int item)
{
    if ((*l) == NULL)
    {
        (*l) = malloc(sizeof(tree));
        (*l)->value = item;
        (*l)->leftptr = NULL;
        (*l)->rightptr = NULL;
    }
    else if ((*l)->value < item)
    {
        insert(&((*l)->rightptr), item);
    }
    else if ((*l)->value > item)
    {
        insert(&((*l)->leftptr), item);
    }
    else
    {
        printf("Dup");
    }
}

void inorder(T l)
{
    if (l != NULL)
    {
        inorder(l->leftptr);
        printf("%3d", l->value);
        inorder(l->rightptr);
    }
}

void preorder(T l)
{
    if (l != NULL)
    {
        printf("%3d", l->value);
        postorder(l->leftptr);
        postorder(l->rightptr);
    }
}

void postorder(T l)
{
    if (l != NULL)
    {
        postorder(l->leftptr);
        postorder(l->rightptr);
        printf("%3d", l->value);
    }
}
