#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list
{
    char data;
    struct list *next;
};

typedef struct list List;
typedef List *L;
void insert(L *s, char value);
char delete (L *l, char value);
void menu(void);
void printList(L m);
int main()
{
    L sPtr = NULL;
    char item;
    int choice;

    menu();
    printf("? ");

    scanf("%d", &choice);

    while (choice != 3)
    {
        switch (choice)
        {
        case 1:
            printf("Insert value: ");
            scanf("%c", &item);
            insert(&sPtr, item);
            //printList(sPtr);
            break;
        case 2:
            printf("Enter value to be deleted: ");
            scanf("%c", &item);
            if (delete (&sPtr, item))
            {
                printf("%c deleted.\n", item);
                printList(sPtr);
            }
            else
            {
                printf("%c not found.\n", item);
            }

            break;
        default:
            printf("Invalid.\n");
            menu();
            break;
        }
        printf("%s", "? ");
        scanf("%d", &choice);
    }
}
void insert(L *s, char value)
{
    L nPtr = malloc(sizeof(List));

    if (nPtr == NULL)
    {
        printf("List is empty");
        return;
    }
    if (nPtr != NULL)
    {
        nPtr->data = value;
        nPtr->next = NULL;

        L cPtr = malloc(sizeof(List));
        L pPtr = malloc(sizeof(List));

        while (cPtr != NULL && value > cPtr->data)
        {
            cPtr = pPtr;
            cPtr = cPtr->next;
        }
        if (pPtr == NULL)
        {
            nPtr->next = *s;
            *s = nPtr;
        }
        else
        {
            pPtr->next = nPtr;
            nPtr->next = cPtr;
        }
    }
    else
    {
        printf("No memory available.\n");
    }
}
char delete (L *l, char value)
{
    if (value == (*l)->data)
    {
        L temp = *l;
        *l = (*l)->next;
        free(temp);
        return value;
    }
    else
    {
        L pPtr = *l;
        L cPtr = (*l)->next;
        while (cPtr != NULL && cPtr->data != value)
        {
            pPtr = cPtr;
            cPtr = cPtr->next;
        }
        if (cPtr != NULL)
        {
            L temp = cPtr;
            pPtr->next = cPtr->next;
            free(temp);
            return value;
        }
    }
    return '\0';
}
void menu(void)
{
    printf("Enter your choice:\n1. Insert value.\n2. Delete value.\n3. End\n");
}

void printList(L m)
{
    while (m != NULL)
    {
        if (m->next != NULL)
        {
            printf("%c -> ", m->data);
        }
        else
        {
            printf("%c -> //", m->data);
        }
    }
}