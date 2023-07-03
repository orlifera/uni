#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CLASSI 30
#define MAX_STUD 30

typedef struct studenti
{
    char nome[20];
    char cognome[20];
    int eta;
} stud;
typedef stud *S;

typedef struct corso
{
    char lingua[10];
    int livello;
    int iscritti;
    char nomeInsegnante[20];
    stud alunno;
} Corso;
typedef Corso *C;

Corso ScuolaLingue[MAX_CLASSI];

int main()
{
    C cPtr;
    S sPtr;
    stud *Stud[MAX_STUD];
    int media;
    for (int i = 0; i < MAX_CLASSI; i++)
    {

        if (strcmp(cPtr->lingua, "Inglese") || strcmp(cPtr->lingua, "inglese"))
        {
            for (int k = 0; k < MAX_STUD; k++)
            {
                media = (Stud[k]->eta) / (cPtr->iscritti);
            }
        }
    }
}