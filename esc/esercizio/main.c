#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_CITY 6

typedef struct lista
{
    char nome[20];
    char temp;
    struct lista *next;
} L;

typedef L *LPtr;
void TempConst(char *fp);
int contalinee(FILE *fp);
char code(int temp);

int main()
{

    TempConst("city.txt");
}

void TempConst(char *fp)
{
    LPtr lista;
    LPtr last;
    LPtr curr;

    FILE *file = fopen(fp, "r"); //apro file
    int num_righe = 0;
    if (fp == NULL)
    {
        fprintf(stderr, "File non trovato.\n "); //se vuoto messaggio di errore
        return;
    }
    else
    {
        num_righe = contalinee(file);
        for (int i = 0; i < NUM_CITY; i++)
        {
            if (i == 0)
            {
                fscanf(file, "%d %20s", &lista->temp, lista->nome);
                last = lista;
            }
            else
            {
                LPtr nuovoNodo = malloc(sizeof(L));
                fscanf(file, "%d %20s", &lista->temp, lista->nome);

                last->next = nuovoNodo; //prec == lista, il next di prec è nuovoNodo
                last = nuovoNodo;       //prec diventa nuovoNodo
            }
        }
    }
    //creo lista

    fclose(file);
}

int

    int
    contalinee(FILE *fp)
{
    char counter = fgetc(fp); // dichiaro una variabile, il cui valore è dato da fgetc
    int linee = 1;
    while (counter != EOF) // fino a che il counter è diverso da EOF "end of file" eseguo il while
    {
        if (counter == '\n') // fino a che counter non raggiunge la fine della riga, e quindi "\n", non entro mai nell'if
        {
            linee++; // quando il counter arriva a fine riga, incremento linee e ricomincio
        }
        counter = fgetc(fp); // fgetc mi fa arrivare a fine riga, ottenendo ogni volta il nuovo carattere puntato da fp (in questo caso)
    }
    rewind(fp); // mi ritorna all'inizio del file
    return linee;
    // POST: conta il numero di entries nel file
}