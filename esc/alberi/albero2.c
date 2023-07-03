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

int search(T l, int k);

int main()
{
    T l;
    printf("Enter a value to search in the tree: ");
    int value;
    scanf("%d", &value);
    search(l, value);
}

int search(T l, int k)
{
    if (l != NULL)
    {
        if (l->value = k)
        {
            return 1;
        }
        else if (k > l->value)
        {
            search(l->sx, k);
        }
        else if (k < l->value)
        {
            search(l->dx, k);
        }
    }
    else
    {
        return 0;
    }
}