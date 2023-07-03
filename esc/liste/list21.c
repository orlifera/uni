#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
};
typedef struct list L;

void pre_insert(L **l, int k);
void suf_insert(L **l, int k);
void print(L *l);
void print_rev(L *l);
int counter(L *l);

int main()
{
    L *l = NULL;
    for (int i = 0; i < 3; i++)
    {
        suf_insert(&l, i);
    }

    printf("List with preisert is: ");
    print_rev(l);
    printf("List with sufinsert is: ");
    print(l);
    printf("there are %d nodes\n", counter(l));
}

void suf_insert(L **l, int k)
{
    if (*l == NULL)
    {
        L *temp;
        temp = *l;
        *l = malloc(sizeof(L));
        (*l)->data = k;
        (*l)->next = temp;
    }
    else
    {
        suf_insert(&((*l)->next), k);
    }
}

void pre_insert(L **l, int k)
{
    L *temp;
    temp = *l;
    *l = malloc(sizeof(L));
    (*l)->data = k;
    (*l)->next = temp;
}

void print(L *l)
{
    if (l != NULL)
    {
        printf("%d -> ", l->data);
        print(l->next);
    }
}

void print_rev(L *l)
{
    if (l != NULL)
    {
        print(l->next);
        printf("%d -> ", l->data);
    }
    else
    {
        printf("%d -> //", l->data);
    }
}

int counter(L *l)
{
    int i = 0;
    L *temp;
    temp = l;
    if (temp != NULL)
    {
        i++;
        counter(temp->next);
    }
    else
    {
        puts("list empty");
    }
    return i;
}