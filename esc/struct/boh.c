#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATI 20
typedef char string[40];
typedef struct foglia
{
    string specie;
    int quantita;
} Foglia;

typedef struct Elenco
{
    Foglia dati[MAX_DATI];
    int numeroEff;
} ElFo;
void insertFoglia(ElFo *f);
void ricercaFoglia(ElFo *el);

int main()
{

    printf("Scegliere una delle seguenti opzioni(-1 per chiudere):\n1. Inserimento Foglia.\n2. Ricerca Foglia.\n");
    int choice = 1;
    //scanf("%d", &choice);
    while (choice != -1)
    {
        if (choice == 1)
        {
            ElFo *f;
            insertFoglia(f);
        }
        else if (choice == 2)
        {
            ElFo *Eptr;
            //ricercaFoglia(Eptr);
        }
        else
        {
            return -1;
        }
    }
}

void insertFoglia(ElFo *f)
{
    ElFo s = *f;
    for (int i = 0; i < MAX_DATI; i++)
    {
        printf("Inserisci il nome della specie:\n");
        string nome_foglia = "ciao";
        //scanf("%s", nome_foglia);

        if (strcmp(s.dati->specie, nome_foglia) == 0)
        {
            s.dati->quantita += 1;
        }
        else
        {
            strcpy(s.dati->specie, nome_foglia);
            printf("Inserisci il codice della specie:\n");
            //scanf("%d", &(*f).numeroEff);
        }
    }
}