#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
};
typedef struct list L;

void preinsert(L **l, int k);
void sufinsert(L **l, int k);
void print(L *l);
void search(L *l, int k);
void delete(L **l, int k);

int main()
{
    L *l = NULL;
    L *s = NULL;
    for (int i = 0; i < 4; i++)
    {
        sufinsert(&l, i);
        preinsert(&s, i);
    }
    printf("sufinsert: ");
    print(l);
    printf("preinsert: ");
    print(s);
    printf("Searching 3...");
    search(l, 3);
    printf("Deleting 2...");
    delete (&l, 2);
}

void preinsert(L **l, int k)
{
    L *temp;
    temp = *l;
    *l = malloc(sizeof(L));
    (*l)->data = k;
    (*l)->next = temp;
}

void sufinsert(L **l, int k)
{
    if (*l == NULL)
    {
        preinsert(l, k);
    }
    else
    {
        sufinsert(&((*l)->next), k);
    }
}

void search(L *l, int k)
{
    if (l == NULL)
    {
        printf("List is empty");
    }
    else if (l != NULL && l->data == k)
    {
        printf("Element found\n");
    }
    else if (l != NULL && l->data != k)
    {
        search(l->next, k);
    }
    else
    {
        printf("item not found");
    }
}

void delete(L **l, int k)
{
    L *temp;
    temp = *l;
    if (l != NULL && (*l)->data == k)
    {
        temp = (*l)->next;
        free(*l);
        *l = temp;
        printf("Item deleted\n");
    }
    else if (l != NULL && (*l)->data != k)
    {
        delete (&((*l)->next), k);
    }
    else
    {
        printf("Item not found\n");
    }
}

void print(L *l)
{
    if (l->next != NULL)
    {
        printf("%d -> ", l->data);
        print(l->next);
    }
    else
    {
        printf("%d -> //", l->data);
    }
}