#include <stdio.h>
#include <stdlib.h>

struct btree
{
    int value;
    struct btree *leftPtr;
    struct btree *rightPtr;
};
typedef struct btree BTree;
void delete_node_rec(BTree **ptrPtr);
int main()
{
}
void delete_node_rec(BTree **ptrPtr)
{
    BTree *currPtr = *ptrPtr;
    BTree *tempPtr = NULL;
    if (currPtr->leftPtr == NULL && currPtr->rightPtr == NULL)
    {
        free(currPtr);
        *ptrPtr = NULL;
    }
    else
    {
        if (currPtr->leftPtr == NULL)
        {
            *ptrPtr = currPtr->rightPtr;
            free(currPtr);
        }
        else
        {
            if (currPtr->rightPtr == NULL)
            {
                *ptrPtr = currPtr->leftPtr;
                free(currPtr);
            }
            else
            {
                tempPtr = currPtr->rightPtr;
                while (tempPtr->leftPtr != NULL)
                {
                    tempPtr = tempPtr->leftPtr;
                }
                currPtr->value = tempPtr->value;
                delete_node_rec(&(currPtr->rightPtr));
            }
        }
    }
}