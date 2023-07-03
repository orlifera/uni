#include <stdio.h>

struct list
{
    int val;
    struct list *next;
};

typedef struct list List;
typedef List *L;
List insord(L l, int value)
{
    L nPtr = malloc(sizeof(List));
    L cPtr;
    L pPtr;
    cPtr = l;
    if (l != NULL && value < l->val)
    {
        pPtr->val = value;
        cPtr->next = l->next;
    }
    else if ()
    {
    }
    else if ()
    {
    }
}
