#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodo
{
    int info;
    struct nodo *next;
} Nodo;

typedef Nodo *NODO;
void print(NODO ptr);
void insert_coda_rc(NODO ptr, Nodo *Ptr);
void primo(NODO lista1, NODO lista2);
_Bool is_prime(int x);
void second_list(NODO *tocopy, NODO fromcopy);

int main()
{
    printf("Questo programma prende in input n valori interi in una lista, e trovati i numeri primi, \nli mette in una seconda lista\n");
    NODO ptr1 = malloc(sizeof(Nodo));
    NODO ptr2 = malloc(sizeof(Nodo));
    printf("Quanti numeri si vogliono inserire?\n");
    int dim = 3;
    scanf("%d", &dim);
    int val = 0;
    for (int i = 0; i < dim; i++)
    {
        printf("Inserire un valore\n");

        scanf("%d", &val);
        NODO nPtr = malloc(sizeof(Nodo));
        nPtr->info = val;
        insert_coda_rc(ptr1, nPtr);
    }
    second_list(&ptr2, ptr1);

    print(ptr2);
}

void print(NODO ptr)
{
    if (ptr == NULL)
    {
        printf("Parte vuota, ->\n");
    }
    if (ptr->next != NULL)
    {
        printf("%d -> ", ptr->info);
        print(ptr->next);
    }
    else
    {
        printf("%d -> //\n", ptr->info);
    }
}

void insert_coda_rc(NODO ptr, Nodo *Ptr)
{
    if (ptr == NULL)
    {
        ptr = Ptr;
        return;
    }
    if (ptr->next == NULL)
    {
        ptr->next = Ptr;
        return;
    }

    insert_coda_rc(ptr->next, Ptr);
}

void primo(NODO lista1, NODO lista2)
{
    while (lista1->next != NULL)
    {
        if (lista1->info)
        {
            lista2->info = lista1->info;
            lista2->next = lista1->next;
        }
        else
        {
            primo(lista1->next, lista2);
        }
    }
}

bool is_prime(int x)
{
    if (x == 1)
    {
        return false;
    }
    int count = 1; // perché tutti i numeri sono divisibili per 1;
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            count += 1;
        }
    }
    return count == 1;
}

void second_list(NODO *tocopy, NODO fromcopy)
{

    if (fromcopy == NULL)
    {
        printf("Fanculo\n");
        return;
    }

    if (!is_prime(fromcopy->info))
    {
        NODO newNode = malloc(sizeof(Nodo)); //RICORDA ALLOCAZIONE MEMORIA
        newNode->info = fromcopy->info;
        (*tocopy)->next = newNode;
        second_list(&(*tocopy)->next, fromcopy->next);
        return;
    }

    second_list(tocopy, fromcopy->next);
}
