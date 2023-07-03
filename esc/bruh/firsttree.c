#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int val;
    struct tree *sx, *dx;
};

typedef struct tree T;

void insert(T **t, int k);
void print(T *t);
T *firstodd(T *t);
int main()
{
    T *t = NULL;
    T *cpy = NULL;
    for (int i = 0; i < 6; i++)
    {
        cpy = malloc(sizeof(T));
        cpy = t;

        insert(&t, i);
    }
    print(t);
    printf("\n");
    firstodd(t);
    T *tmp = t;
    printf("%d", tmp->val);
}

void insert(T **t, int k)
{
    if (*t == NULL)
    {
        *t = malloc(sizeof(T));
        (*t)->val = k;
        (*t)->sx = NULL;
        (*t)->dx = NULL;
    }
    else if (*t != NULL && (*t)->val < k)
    {
        insert(&((*t)->dx), k);
    }
    else if (*t != NULL && (*t)->val > k)
    {
        insert(&((*t)->sx), k);
    }
    else
    {
        printf("Dup");
    }
}

T *firstodd(T *t)
{
    T *min = t;
    if (t != NULL)
    {
        while (t->sx != NULL && t->dx != NULL)
        {
            if ((t->sx)->val < min->val && (t->sx)->val < (t->dx)->val && (t->sx)->val % 2 != 0)
            {
                min->val = (t->sx)->val;
            }
            else
            {
                min->val = (t->dx)->val;
            }
            t = t->sx;
            t = t->dx;
        }
    }
    return min;
}

void print(T *t)
{
    if (t != NULL)
    {
        print(t->sx);
        print(t->dx);
        printf("%d", t->val);
    }
}
