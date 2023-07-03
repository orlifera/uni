#include <stdio.h>

struct list
{
    int val;
    struct list *dx, *sx;
};

typedef struct list BTree;

void delete(BTree **ptrPtr)
{
    (*ptrPtr)->val = ((*ptrPtr)->sx)->val;
    (*ptrPtr)->sx = ((*ptrPtr)->sx)->sx;
    BTree *temp = malloc(sizeof(BTree));
    temp->dx = (*ptrPtr)->dx;

    BTree *next = (*ptrPtr)->sx;
    while (next->dx == NULL)
    {
        next = next->dx;
    }
    next->dx = temp->dx;
}