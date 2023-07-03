#include <stdio.h>
#include <stdlib.h>

struct btree
{
    int valore;
    struct btree *leftPtr;
    struct btree *rightPtr;
};

typedef struct btree BTree;

void init(BTree **ptrPtr);
int isempty(BTree *ptr);
int search_rec(BTree *ptr, int val);
void print_rec(BTree *ptr);
void ordinsert_rec(BTree **ptrPtr, int val);

int main(void)
{
    BTree *albero;
    init(&albero);
    printf("Albero vuoto? %d\n", isempty(albero));

    ordinsert_rec(&albero, 2);
    printf("Albero vuoto? %d\n", isempty(albero));
    ordinsert_rec(&albero, 1);
    ordinsert_rec(&albero, 0);
    ordinsert_rec(&albero, 2);
    ordinsert_rec(&albero, 6);
    ordinsert_rec(&albero, 6);
    ordinsert_rec(&albero, 9);
    ordinsert_rec(&albero, 5);
    print_rec(albero);

    int target = 7;
    printf("\nL'albero contiene %d? %d\n", target, search_rec(albero, target));

    return 0;
}

void init(BTree **ptrPtr)
{
    *ptrPtr = NULL;
}

// restituisce 1 se l'albero è vuoto, 0 altrimenti
int isempty(BTree *ptr)
{
    return ptr == NULL;
}

// restituisce 1 se l'albero contie l'elemento val, 0 altrimenti
int search_rec(BTree *ptr, int val)
{
    if (ptr != NULL)
    {
        if (ptr->valore == val)
        {
            return 1;
        }
        else
        {
            if (ptr->valore > val)
                return search_rec(ptr->leftPtr, val);
            else
                return search_rec(ptr->rightPtr, val);
        }
    }
    else
    {
        return 0;
    }
}

// visita ricorsiva
void print_rec(BTree *ptr)
{
    if (ptr != NULL)
    {
        //printf("%d ", ptr->valore); // visita in pre-ordine
        print_rec(ptr->leftPtr);
        printf("%d ", ptr->valore); // visita simmetrica (in ordine)
        print_rec(ptr->rightPtr);
        //printf("%d ", ptr->valore); // visita in post-ordine (in profondità / "depth-first")
    }
}

// inserimento in ordine (con ricorsione)
void ordinsert_rec(BTree **ptrPtr, int val)
{
    if ((*ptrPtr) != NULL)
    {
        if (val <= (*ptrPtr)->valore)
            ordinsert_rec(&((*ptrPtr)->leftPtr), val);
        else
            ordinsert_rec(&((*ptrPtr)->rightPtr), val);
    }
    else
    {
        (*ptrPtr) = (BTree *)malloc(sizeof(BTree));
        (*ptrPtr)->valore = val;
        (*ptrPtr)->leftPtr = NULL;
        (*ptrPtr)->rightPtr = NULL;
    }
}
