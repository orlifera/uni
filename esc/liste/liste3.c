#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct lista_1
{
    char nome1[20];
    struct l1 *nextPtr1;
} l1;
typedef l1 *L1;

typedef struct lista_2
{
    char nome2[20];
    struct l2 *nextPtr;
} l2;
typedef l2 *L2;

typedef struct lista_conc
{
    char nomeC[20];
    char nameC[20];
    struct conc *nextPtr;
} conc;
typedef conc *Conc;
void concatenate(l1 *L1, l2 *L2, conc *Conc);

int main()
{

    L1 ptrL1 = malloc(sizeof(l1));
    L2 ptrL2 = malloc(sizeof(l2));
    Conc concPtr = malloc(sizeof(conc));

    strcpy(ptrL1->nome1, "Virgilio");
    //ptrL1->age1 = 18;

    strcpy(ptrL2->nome2, "Anita");
    //ptrL2->age2 = 10;
    //L1 startPtr = ptrL1;

    // printf("%s", ptrL2->nome2);
    concatenate(ptrL1, ptrL2, concPtr);
    while (ptrL1 != NULL)
    {
        printf("%s - %s\n", concPtr->nomeC, concPtr->nameC);
        ptrL1 = ptrL1->nextPtr1;
    }

    //printf("%d - %d ", concPtr->etaC, concPtr->ageC);
}

void concatenate(l1 *L1, l2 *L2, conc *Conc)
{
    *Conc->nomeC = *L1->nome1;
    *Conc->nameC = *L2->nome2;
}