#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct List1
{
    unsigned int val;
    struct List1 *next;
};
typedef struct List1 L1;

void pre_insert(int k, L1 **s);
void isPrime(L1 **s, L1 **l);
void print_rec(L1 *s);

int main()
{
    L1 *s = NULL;
    L1 *l = NULL;
    // unsigned int k = 0;
    /*
    for (int i = 0; i < 3; i++)
    {
        printf("Enter a positive integer: ");
        scanf("%d", &k);
        pre_insert(k, &s);
    }
    */

    for (int i = 1; i < 4; i++)
    {
        pre_insert(i, &s);
        // isPrime(&s, &l);
    }

    isPrime(&s, &l);
    // print_rec(s);
    print_rec(l);
}

void pre_insert(int k, L1 **s)
{
    L1 *temp;
    temp = *s;
    *s = malloc(sizeof(L1));
    (*s)->val = k;
    (*s)->next = temp;
}

void print_rec(L1 *s)
{
    if (s->next != NULL)
    {
        printf(" %d ->  ", s->val);
        print_rec(s->next);
    }
    else
    {
        printf("%d -> //\n", s->val);
    }
}

void isPrime(L1 **s, L1 **l)
{
    if (*s != NULL && (((*s)->val % 2 != 0) || ((*s)->val % 3 != 0)))
    {
        //*s = malloc(sizeof(L1));
        pre_insert((*s)->val, l);
        s = &(*s)->next;
        l = &(*l)->next;
    }
    else if (*s == NULL)
    {
        return;
    }
    else
    {
        s = &(*s)->next;
        l = &(*l)->next;
    }
}