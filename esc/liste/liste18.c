#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int value;
    struct lista *next;
};
typedef struct lista Lista;

void preinsert(Lista **l, int k);
void sufinsert_rec(Lista **s, int k);
int search(Lista *l, int k);
void print_rec(Lista *l);
void printrev_rec(Lista *l);

int main()
{
    Lista *l = NULL;
    Lista *s = NULL;
    for (int i = 0; i < 5; i++)
    {
        printf("Enter a value: ");
        int item;
        scanf("%d", &item);
        preinsert(&l, item);
        sufinsert_rec(&s, item);
    }

    /* printf("Do you want to search for an item in the list?\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter the integer to search: ");
        int k;
        scanf("%d", &k);
        search(*s, k);
    }
    else
    {
        puts("Invalid. Printing list...");
    }*/

    printf("\nList with head insert is: ");
    print_rec(l);

    printf("\nList with tail insert is: ");
    print_rec(s);

    puts("\nList printed in reverse is: ");
    printrev_rec(l);
    puts("\nAnd: ");
    printrev_rec(s);
}

void print_rec(Lista *l)
{
    if (l->next != NULL)
    {
        printf("%d  ->  ", l->value);
        print_rec(l->next);
    }
    else
    {
        printf("%d  ->  //", l->value);
    }
}

void printrev_rec(Lista *l)
{
    if (l != NULL)
    {
        printrev_rec(l->next);
        printf("%d  ->  ", l->value);
    }
}

void preinsert(Lista **l, int k)
{
    Lista *temp;

    temp = *l;
    (*l) = malloc(sizeof(Lista));
    (*l)->value = k;
    (*l)->next = temp;
}

void sufinsert_rec(Lista **l, int k)
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
        sufinsert_rec(&((*l)->next), k);
    }
}

int search(Lista *l, int k)
{
    if (l != NULL)
    {
        if (l->value == k)
        {
            return 1;
        }
        else
        {
            search(l->next, k);
        }
    }
    return 0;
}