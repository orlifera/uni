#include <stdio.h>
#include "functions.h"

Node *create_node(int value, Node *next)
{
    Node *node = malloc(sizeof(Node)); //crea un nuovo nodo allocando memoria
    node->value = value;               //inserisce il valore
    node->next = next;                 //scorre

    return node;
}

void print_list(Node *list)
{
    if (list == NULL) //se vuota stampa niente
    {
        printf("\n");
        return;
    }

    printf("%d -> ", list->value); //stampa il value
    print_list(list->next);        //ricorsione
}

void print_inverted_list(Node *list)
{
    if (list == NULL)
        return;

    print_inverted_list(list->next); //ricorsione
    printf("%d -> ", list->value);   //stampa value
}

int list_size(Node *node)
{
    if (node == NULL)
        return 0;

    return 1 + list_size(node->next);
}

void push(Node **list, int value)
{
    if (list == NULL)
    {
        *list = create_node(value, NULL);
    }
    else
    {
        Node *last_node = *list;

        while (last_node->next != NULL)
        {
            last_node = last_node->next;
        }
        last_node->next = create_node(value, NULL);
    }
}

void insert_at(Node **list, int value, int pos) //ricorda doppio * e &
{
    if (pos == 0)
    {
        *list = create_node(value, *list); //se pos == 0 crea nodo e inserisce valore
        return;
    }

    if (*list == NULL) //se lista vuota, interrompe
        return;

    // Node at position pos;
    Node *node = *list;

    while (node != NULL && pos > 1)
    {
        node = node->next;
        pos--;
    }

    if (pos == 1)
    {
        node->next = create_node(value, node->next);
    }
}

void delete_at(Node **list, int pos)
{
    if (*list == NULL) //se vuota, nulla
        return;

    if (pos == 0) //se pos == 0
    {
        Node *new_list = (*list)->next; //crea nuovo nodo dove mette il next della lista
        free(*list);                    //cancella la lista
        *list = new_list;               //rimette value dentro lista

        return;
    }

    Node *last_node = *list;

    while (last_node != NULL && pos > 1)
    {
        pos--;                       //diminuisce dim
        last_node = last_node->next; //scorre
    }

    if (pos == 1 && last_node->next != NULL)
    {
        Node *new_list = last_node->next->next;
        free(last_node->next);
        last_node->next = new_list;
    }
}

// Recoursive;

int read(Node *list, int pos)
{
    if (list == NULL)
        return -1;

    if (pos == 0)
    {
        return list->value;
    }

    return read(list->next, pos - 1);
}

void insert_at_rec(Node **list, int value, int pos)
{
    if (pos == 0)
    {
        *list = create_node(value, *list);
        return;
    }

    if (*list == NULL)
        return;

    insert_at_rec(&(*list)->next, value, pos - 1);
}

void delete_at_rec(Node **list, int pos)
{
    if (*list == NULL)
        return;

    if (pos == 0)
    {
        Node *new_list = (*list)->next;
        free(*list);
        *list = new_list;
    }
    else
    {
        delete_at_rec(&(*list)->next, pos - 1);
    }
}

void ordinsert_rec(Node **list, int value)
{
    if (*list == NULL)
    {
        *list = create_node(value, NULL);
        return;
    }

    // LOWER THAN THE FIRST ONE

    if (value < (*list)->value)
    {
        *list = create_node(value, *list);
        return;
    }

    // GREATER THAN THE LAST ONE

    if ((*list)->next == NULL)
    {
        (*list)->next = create_node(value, NULL);
        return;
    }

    Node *last_node = (*list)->next;

    // LOWER THAN THE LAST ONE
    if (value <= last_node->value)
    {
        (*list)->next = create_node(value, last_node);
        return;
    }

    ordinsert_rec(&(*list)->next, value);
}

void pre_insert(Node **list, int value)
{
    Node *temp_node = *list;

    *list = malloc(sizeof(Node));
    (*list)->value = value;
    (*list)->next = temp_node;
}

void suf_insert(Node **list, int value)
{
    while (*list != NULL)
    {
        list = &((*list)->next);
    }

    *list = create_node(value, *list);
}

void suf_insert_rec(Node **list, int value)
{
    if (*list == NULL)
    {
        *list = create_node(value, *list);
    }
    else
    {
        suf_insert_rec(&((*list)->next), value);
    }
}

void remove_elements(Node **list, int number)
{
    if (number == 0)
        return;

    *list = (*list)->next;

    remove_elements(list, number - 1);
}

void reverse(Node **list)
{
    Node *current = *list;
    Node *next;

    while (current->next != NULL)
    {
        next = current->next;
        current->next = next->next;
        next->next = (*list);
        *list = next;
    }
}

void reverse_recursive(Node **list)
{
    Node *first, *rest;

    if (*list == NULL)
        return;

    first = *list;
    rest = first->next;

    if (rest == NULL)
        return;

    reverse_recursive(&rest);

    first->next->next = first;
    first->next = NULL;
    *list = rest;
}

void sort_list(Node **list)
{
    Node *result = NULL;
    Node *current = *list;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        ordinsert_rec(&result, current->value);
        current = next;
    }
    *list = result;
}

void append_list(Node **list_a, Node **list_b)
{
    if (*list_a == NULL)
        *list_a = *list_b;
    else
    {
        Node *current = *list_a;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = *list_b;
        *list_b = NULL;
    }
}