#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int value;
    struct tree *leftPtr, *rightPtr;
};
typedef struct tree BTree;

void delete_node(BTree **ptrPtr);
void insert(BTree **t, int k);
void print(BTree *t);
void search(BTree *t, int k);
int main()
{
    BTree *t = NULL;
    for (int i = 0; i < 6; i++)
    {
        insert(&t, i);
    }
    print(t);
    printf("\n");
    search(t, 3);
    printf("\n");
    delete_node(&(t->leftPtr));
    print(t);
}

void delete_node(BTree **ptrPtr)
{
    BTree *tmpPtr = NULL;
    BTree *currentPtr = *ptrPtr;
    if (currentPtr->leftPtr == NULL && currentPtr->rightPtr == NULL)
    {
        free(currentPtr);
        *ptrPtr = NULL;
    }
    else
    {
        if (currentPtr->leftPtr == NULL)
        {
            *ptrPtr = currentPtr->leftPtr;
            free(currentPtr);
        }
        else
        {
            tmpPtr = currentPtr->rightPtr;
            while (tmpPtr->leftPtr != NULL)
            {
                tmpPtr = tmpPtr->leftPtr;
            }
            currentPtr->value = tmpPtr->value;
            delete_node(&(currentPtr->rightPtr));
        }
    }
}

void insert(BTree **t, int k)
{
    if (*t == NULL)
    {
        *t = malloc(sizeof(BTree));
        (*t)->value = k;
        (*t)->leftPtr = NULL;
        (*t)->rightPtr = NULL;
    }

    else if (*t != NULL && (*t)->value < k)
    {
        insert(&((*t)->rightPtr), k);
    }
    else if (*t != NULL && (*t)->value > k)
    {
        insert(&((*t)->leftPtr), k);
    }
    else
    {
        puts("Dup");
    }
}

void search(BTree *t, int k)
{
    if (t == NULL)
    {
        printf("Empty");
    }
    else if (t != NULL && t->value == k)
    {
        printf("Found");
    }
    else if (t != NULL && t->value < k)
    {
        search(t->rightPtr, k);
    }
    else if (t != NULL && t->value > k)
    {
        search(t->leftPtr, k);
    }
    else
    {
        puts("Not found");
    }
}

void print(BTree *t)
{
    if (t != NULL)
    {
        printf("%d", t->value);
        print(t->leftPtr);
        print(t->rightPtr);
    }
}