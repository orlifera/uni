#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int value;
    struct lista *next;
};
typedef struct lista Lista;

void sufinsert(Lista **l, int k);
void preinsert(Lista **l, int k);
void print(Lista *l);
void delete (Lista **l, int k);

int main()
{
    Lista *l = NULL;
    Lista *s = NULL;
    for (int i = 0; i < 5; i++)
    {
        int item = i;
        sufinsert(&s, item);
        preinsert(&l, item);
    }

    printf("\nList with head insertion is: ");
    print(l);

    printf("\nList with tail inserion is: ");
    print(s);

    printf("\nEnter item to delete: ");
    int k = 3;
    scanf("%d", &k);
    delete (&l, k);

    printf("\nNew list is: ");
    print(l);
}

void print(Lista *l)
{
    if (l->next != NULL)
    {
        printf("%d  ->  ", l->value);
        print(l->next);
    }
    else
    {
        printf("%d  ->  //\n", l->value);
    }
}

void sufinsert(Lista **l, int k)
{
    if (*l == NULL)
    {
        Lista *temp;
        temp = *l;
        *l = malloc(sizeof(Lista));
        (*l)->value = k;
        (*l)->next = temp;
    }
    else
    {
        sufinsert(&((*l)->next), k);
    }
}

void preinsert(Lista **l, int k)
{

    Lista *temp;
    temp = *l;
    *l = malloc(sizeof(Lista));
    (*l)->value = k;
    (*l)->next = temp;
}

void delete (Lista **l, int k)
{
    Lista *temp;
    temp = *l;

    if (*l == NULL)
    {
        puts("List empty\n");
    }
    if (*l != NULL && (*l)->value == k)
    {
        temp = (*l)->next;
        free(*l);
        *l = temp;
    }
    else if (*l != NULL && (*l)->value != k)
    {
        delete (&((*l)->next), k);
    }
    else
    {
        puts("Item not found\n");
    }
}