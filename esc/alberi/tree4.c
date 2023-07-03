#include <stdio.h>
#include <stdlib.h>

struct list
{
    int val;
    struct list *next;
};
typedef struct list L;

void preinsert(L **l, int x);
void sufinsert(L **l, int x);
void delete(L **l, int x);
void print(L *l);
void ordinsert(L **l, int x);
int counter(L *l);
void clone(L *l, L **s);

int main()
{
    L *l = NULL;
    L *s = NULL;
    L *m = NULL;
    int a = 0;
    for (int i = 0; i < 6; i++)
    {
        preinsert(&l, i);
        sufinsert(&s, i);
    }

    printf("List with preinsert is: ");
    print(l);
    printf("\nList with sufinsert is: ");
    print(s);
    printf("\nCloned list is: ");
    clone(l, &m);
    print(m);

    delete (&l, 3);
    printf("\nNew list is: ");
    print(l);
    printf("There are %d nodes in List l\n", counter(l));
}

void preinsert(L **l, int x)
{
    L *temp;
    temp = *l;
    *l = malloc(sizeof(L));
    (*l)->val = x;
    (*l)->next = temp;
}

void sufinsert(L **l, int x)
{
    if (*l == NULL)
    {
        preinsert(l, x);
    }
    else
    {
        sufinsert(&((*l)->next), x);
    }
}

int counter(L *l)
{
    if (l == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + counter(l->next);
    }
}

void delete(L **l, int x)
{
    L *temp;
    temp = *l;
    if (*l != NULL && (*l)->val == x)
    {
        temp = (*l)->next;
        free(*l);
        *l = temp;
        printf("Item deleted\n");
    }
    else if (*l != NULL && (*l)->val != x)
    {
        delete (&((*l)->next), x);
    }
    else
    {
        printf("Item not found or list empty\n");
    }
}

void print(L *l)
{
    if (l->next != NULL)
    {
        printf("%d -> ", l->val);
        print(l->next);
    }
    else
    {
        printf("%d -> //\n", l->val);
    }
}

void ordinsert(L **l, int x)
{
    if (*l != NULL && (*l)->val < x)
    {
        l = &((*l)->next);
    }
    preinsert(l, x);
}

void clone(L *l, L **s)
{
    *s = malloc(sizeof(L));
    if (l != NULL)
    {
        (*s)->val = l->val;
        clone(l->next, &((*s)->next));
    }
    else
    {
        printf("Empty list\n");
    }
}
