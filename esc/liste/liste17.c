#include <stdio.h>
#include <stdlib.h>

struct lista
{
    float value;
    struct lista *next;
};
typedef struct lista Lista;
//typedef Lista *L;

void clone_list(Lista *s, Lista **l);
void insert(Lista **s, float k);
void print(Lista *s);

int main()
{
    Lista *s = NULL;
    Lista *l = NULL;
    for (float i = 0; i < 3; i++)
    {
        float item = (i + 3.55);
        //printf("%.2f\t", item);
        insert(&s, item);
    }
    //print(s);

    //clone_list(s, &l);
    print(s);
}

void insert(Lista **s, float k)
{
    //if (*s == NULL)
    //{
    Lista *tmp;
    tmp = *s;
    *s = malloc(sizeof(Lista));
    (*s)->value = k;
    (*s)->next = tmp;
    //}
    /*else
    {
        insert(&((*s)->next), k);
    }*/
}

void print(Lista *s)
{
    if (s != NULL)
    {
        printf("%.2f\t\n", s->value);
        print(s->next);
    }
}

void clone_list(Lista *s, Lista **l)
{
    (*l) = malloc(sizeof(Lista));
    if (s != NULL)
    {
        (*l)->value = s->value;
        clone_list(s->next, &((*l)->next));
    }
}