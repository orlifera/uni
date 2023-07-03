/* Un file di testo (TEMP.TXT) contiene i dati relativi alle medie di tutti gli studenti che
 * devono accedere ad una sessione di laurea. Si realizzi un programma C che:
 * 1. Costruisca in memoria centrale una lista che memorizzi, in modo ordinato crescente
 * tali medie (intere) e la stampi.
 * 2. Letti due valori interi da console N e M, utilizzando la lista, visualizzi il valore delle
 * medie comprese fra N e M ed un opportuno messaggio se non ne esistono.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct medie
{
    int voto;
    struct medie *prossimo_elemento;
} Medie;

void leggiFile(FILE *fp, Medie *ptr);
int contaLinee(FILE *fp);

int main()
{
    FILE *fp;
    Medie *ptr;
    leggiFile(fp, ptr);
}

void leggiFile(FILE *fp, Medie *ptr)
{
    Medie *ultimoElementoInserito;
    int numero_righe = 0;

    fp = fopen("voti.txt", "r");
    if (fp == NULL)
    {
        printf("Il file non può essere letto");
        return;
    }
    else
    {
        numero_righe = contaLinee(fp);
        for (int i = 0; i < numero_righe; i++)
        {
            if (i == 0)
            {
                fscanf(fp, "%d", &ptr->voto);
                ultimoElementoInserito = ptr;
            }
            else
            {
                Medie *nodocorrente;
                nodocorrente = malloc(sizeof(Medie));
                fscanf(fp, "%d", &nodocorrente->voto);
                ultimoElementoInserito->prossimo_elemento = nodocorrente;
                ultimoElementoInserito = nodocorrente;
            }
        }
    }
    fclose(fp);
}

int contaLinee(FILE *fp)
{
    int linee = 1;
    char carattere = fgetc(fp);
    while (carattere != EOF)
    {
        if (carattere == '\n')
        {
            linee++;
        }
        carattere = fgetc(fp);
    }
    rewind(fp);
    return linee;
}
