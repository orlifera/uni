#include <stdlib.h>
#include <stdio.h>

typedef struct listnode
{
    char data;         //ogni nodo contiene un carattere;
    ListNode *nextPtr; //puntatore al prossimo nodo;
} ListNode;            //sinonimo per nodo;

typedef ListNode *nodeptr; //sinonimo per Nodo;

//prototipi;
void insert(nodeptr *sPtr, char value);
char delete (nodeptr *sPtr, char value);
int isEmpty(nodeptr sPtr); //ritorna 1 se è vuota
void printList(nodeptr currentPtr);
void instructions(void);

int main()
{
    nodeptr startPtr = NULL;
    char item;

    instructions();
    printf("?\n");
    unsigned int choice;
    scanf("%u", &choice);

    while (choice != 3)
    {
        if (choice == 1)
        {
            printf("Enter a charatcter\n");
            scanf("%c", &item);
            insert(startPtr, item);
            printList(startPtr);
        }

        else if (choice == 2)
        {
            if (isEmpty != 1)
            {
                printf("Enter character to be deleted\n");
                scanf("");
            }
        }
    }
}

void instructions(void)
{
    printf("Choose an option:\n1) Enter character:\n2) Delete character.\n3) End.\n");
}

void insert(nodeptr *sPtr, char value)
{
    nodeptr newPtr = malloc(sizeof(ListNode));
    if (newPtr != NULL) //se c'è spazio
    {
        newPtr->data = value;   //inserisce il valore nel nodo
        newPtr->nextPtr = NULL; //il puntatore ultimo è NULL

        nodeptr previousPtr = NULL;
        nodeptr currentPtr = *sPtr;

        while (currentPtr != NULL && value > currentPtr->data)
        {
            previousPtr = currentPtr;         //il corrente diventa il precedente
            currentPtr = currentPtr->nextPtr; //il prossimo diventa il corrente -> va avanti di un ptr
        }

        //inserisce un nuovo nodo in testa
        if (previousPtr == NULL)
        {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else
        {
            //inserisce il nodo tra current e previous
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else
    {
        printf("%c not inserted. No memory available\n", value);
    }
}

char delete (nodeptr *sPtr, char value)
{
    if (value == (*sPtr)->data)
    {
        nodeptr tempPtr = *sPtr;
        *sPtr = (*sPtr)->nextPtr;
        free(tempPtr);
        return value;
    }
    else
    {
        nodeptr previousPtr = *sPtr;
        nodeptr currentPtr = (*sPtr)->nextPtr;

        while (currentPtr != NULL && currentPtr->data != value)
        {
            previousPtr = currentPtr;         // va avanti ...
            currentPtr = currentPtr->nextPtr; // ... al nodo successivo135
        }
        if (currentPtr != NULL)
        {
            nodeptr tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }
    return '\0';
}
//restituisci 1 se la lista e ' vuota, altrimenti 0
int isEmpty(nodeptr sPtr)
{
    return sPtr == NULL;
}
// stampa la lista156
void printList(nodeptr currentPtr)
{
    // se la lista e' vuota159
    if (isEmpty(currentPtr))
    {
        puts("List is empty.\n");
    }
    else
    {
        puts("The list is:");
        // finche' non si raggiunge la fine della lista166
        while (currentPtr != NULL)
        {
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        puts("NULL\n");
    }
}
