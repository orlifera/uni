#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct nodo
{
    int info;
    struct nodo next;
} Nodo;
typedef Nodo *NODO;
void print(NODO ptr);
void insert_coda_rc(NODO ptr, Nodo Ptr);

int main()
{
    printf("Questo programma prende in input n valori interi in una lista, e trovati i numeri primi, \nli mette in una seconda lista\n");
    NODO ptr1 = malloc(sizeof(Nodo));
    NODO ptr2 = malloc(sizeof(Nodo));
    printf("Quanti numeri si vogliono inserire?\n");
    int dim = 3;
    scanf("%d", &dim);
    int val = 1;
    for (int i = 0; i < dim; i++)
    {
        printf("Inserire un valore\n");
        scanf("%d", &val);
        NODO nPtr = malloc(sizeof(Nodo));
        nPtr->info = val;
        insert_coda_rc(ptr1, nPtr);
    }
    // second_list(&ptr2, ptr1);
    print(ptr1);
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

void insert_coda_rc(NODO ptr, Nodo Ptr)
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
