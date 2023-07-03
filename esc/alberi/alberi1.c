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

void insert(T *l, int dato);
void print(T l);
void preorder(T l);
void postorder(T l);
void inorder(T l);

int main()
{
    T rootPtr = NULL;
    //srand(time(NULL));
    printf("The numbers are: ");

    for (int i = 0; i < 10; i++)
    {
        int item = i;
        //int item = rand() % 15;
        printf("%3d", item);
        insert(&rootPtr, item);
    }

    printf("tree in preorder is: ");
    preorder(rootPtr);

    printf("\ntree in order is: ");
    inorder(rootPtr);

    printf("\ntree in postorder is: ");
    postorder(rootPtr);
}

void inorder(T l)
{
    inorder(l->leftptr);
    printf("%3d", l->value);
    inorder(l->rightptr);
}

void preorder(T l)
{
    printf("%3d", l->value);
    postorder(l->leftptr);
    postorder(l->rightptr);
}

void postorder(T l)
{
    postorder(l->leftptr);
    postorder(l->rightptr);
    printf("%3d", l->value);
}

void insert(T *l, int dato)
{
    if (*l == NULL)
    {
        *l = malloc(sizeof(tree));
        (*l)->value = dato;
        (*l)->leftptr = NULL;
        (*l)->rightptr = NULL;
    }
    else
    {
        if (dato < (*l)->value)
        {
            insert(&((*l)->leftptr), dato);
        }
        else if (dato > (*l)->value)
        {
            insert(&((*l)->rightptr), dato);
        }
        else
        {
            printf("dup");
        }
    }
}
