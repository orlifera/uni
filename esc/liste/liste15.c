#include <stdio.h>

struct el
{
    int info;
    struct el *next;
};
typedef struct el ElementoDiLista;
typedef ElementoDiLista *ListaDiElementi;

int main()
{
    printf("Hello World");
}
void printList(ListaDiElementi l)
{
    ListaDiElementi s = l;
    while (s->next != NULL)
    {
        printf("%d ->", s->info);
        s = l->next;
    }
    if (s->next == NULL)
    {
        printf("%d -> //", s->info);
    }
}

void printList_rec(ListaDiElementi s)
{
    ListaDiElementi l = s;
    if (l->next != NULL)
    {
        printf("%d ->", l->info);
        printList_rec(l->next);
    }
    else
    {
        printf("//");
    }
}

int listaElementi(ListaDiElementi s)
{
    int counter = 0;
    while (s->next != NULL)
    {
        counter++;
        s = s->next;
    }
    return counter;
}

int listaElementi_rec(ListaDiElementi s)
{
    int counter;
    if (s->next != NULL)
    {
        counter += 1;
        return listaElementi_rec(s->next);
    }
    return counter;
}

void dealloca(ListaDiElementi s)
{
    if (s != NULL)
    {
        dealloca(s->next);
        free(s);
    }
}

int primopari(ListaDiElementi l)
{
    int *p;
    ListaDiElementi s;
    while (l != NULL)
    {
        if (l->info % 2 == 0)
        {
            p = l->info;
            return &p;
        }
        l = l->next;
    }
    return 0;
}

int primoPari(ListaDiElementi l)
{
    if (l != NULL && l->info % 2 != 0)
    {
        l = l->next;
    }
    else
    {
        return l;
    }
}

int primopari_rec(ListaDiElementi l)
{
    if (l != NULL && l->info % 2 != 0)
    {
        return primopari_rec(l->next);
    }
    return l;
}

int elimina(ListaDiElementi l, int x)
{
    if (l != NULL && x > 0)
    {
        l = l->next;
        x--;
    }
    return l;
}

int elimina_rec(ListaDiElementi l, int x)
{
    if (l == NULL || x == 0)
    {
        return l;
    }
    else
    {
        return elimina_rec(l->next, x - 1);
    }
}

void print_reversed(ListaDiElementi s)
{
    if (s != NULL)
    {
        print_reversed(s->next);
        printf("%d -> ", s->info);
    }
    else
    {
        printf("//\n");
    }
}

int pointer(ListaDiElementi l)
{
    if (l->next != NULL)
    {
        pointer(l->next);
    }
    return l;
}

int lastpt_rec(ListaDiElementi s)
{
    if (s->next != NULL)
    {
        lastpt_rec(s->next);
    }
    else
    {
        return s;
    }
}

int pt(ListaDiElementi s)
{
    if ((s->next)->next == NULL)
    {
        return s;
    }
    else
    {
        pt(s->next);
    }
}

int lista(ListaDiElementi s)
{
    ListaDiElementi temp;
    if (s != NULL)
    {
        lista(s->next);
    }
    else
    {
        temp = s;
        temp->next = s->next;
        free(s);
        s = temp;
    }
}

int i_element(ListaDiElementi s, unsigned int pos)
{
    if (s != NULL && pos != 0)
    {
        i_element(s->next, pos - 1);
    }
    else
    {
        return s->info;
    }
}

int i_element_it(ListaDiElementi s, unsigned int pos)
{
    for (; pos != 0; pos--)
    {
        s = s->next;
    }
    return s;
}

int somma(ListaDiElementi s)
{
    int somma;
    while (s != NULL)
    {
        somma += s->info;
        s = s->next;
    }
    return somma;
}

int sep(ListaDiElementi s)
{
    ListaDiElementi p, d;
    p = malloc(sizeof(ElementoDiLista));
    d = malloc(sizeof(ElementoDiLista));

    while (s != NULL)
    {
        p = malloc(sizeof(ElementoDiLista));
        d = malloc(sizeof(ElementoDiLista));
        if (s->info % 2 == 0)
        {
            p->info = s->info;
            p = p->next;
        }
        else
        {
            d->info = s->info;
            d = d->next;
        }
        s = s->next;
    }
    return p, d;
}

int max_rec(ListaDiElementi s)
{
    int max = 0;
    if (s != NULL)
    {
        if (s->info > max)
        {
            max = s->info;
        }
        return max_rec(s->next);
    }

    return max;
}

int prodotto(ListaDiElementi s1, ListaDiElementi s2)
{
    int pro = 0;
    if (s1 != NULL && s2 != NULL)
    {
        pro *= (s1->info) * (s2->info);
        return prodotto(s1->next, s2->next);
    }
    return pro;
}

int ord(ListaDiElementi s, int dim)
{
    ListaDiElementi testa = NULL;
    ListaDiElementi temp = NULL;
    int min = 0;
    dim = listaElementi_rec(s);
    while (s != NULL)
    {
        if (s->info < min)
        {
            temp = malloc(sizeof(ElementoDiLista));
            min = s->info;
            temp->info = min;
            free(s);
            temp->next = testa;
            testa = s->next;
        }
        s = s->next;
    }
    print_reversed(temp);
}
