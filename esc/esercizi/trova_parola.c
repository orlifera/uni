#include <stdio.h>

/*
 * Enigmistica - Parole intrecciate. 
 * Scrivere una funzione che, data una tabella di caratteri
 * di dimensione 13x15 e una stringa, cerchi se la stringa
 * appare nella tabella: la stringa può apparire scritta:
 * 
 * 1) in orizzontale da sinistra a destra 
 * 2) in orizzontale da destra a sinistra
 * 
 * Se la parola è presente nella tabella, restituire le sue
 * coordinate; se la parola non
 * compare, utilizzare le coordinate -1,-1. 
 * Nel main utilizzare il seguente frammento di codice per 
 * stampare il risultato:
    // gli interi x,y contengono le coordinate,
    // dir è un intero che rappresenta la direzione del match (0 se è da sinistra a destra, 1 viceversa) 
    // parola la parola da cercare
    printf("Parola %s ", parola);
    if (x != -1)
        printf("in (%d,%d), direzione %s\n", x, y, dir==0?"s->d":"d->s");
    else
        printf("non trovata\n");;
 * 
 * Ad esempio nella tabella fornita sotto, se
 * parola_cercata = "Riposo"; allora stampa
    Parola Riposo in (1,0), direzione s->d
 * ATTENZIONE: le parole fornite possono avere sia lettere maiuscole che minuscole
 *             mentre la tabella contiene solo caratteri maiuscoli
 */

void trova_parola(int *x, int *y, int *dir, char *parola, char **tabella);

int main(void)
{

    char tabella[13][16] = {
        {"ESEOPIDLNOTETM"},
        {"RIPOSOTICUCBAOI"},
        {"ETROPSIVOOINMRL"},
        {"RSINNETIITGSFAA"},
        {"ROCKSPCNTOIOOLM"},
        {"OLAUOSSABLLIRLI"},
        {"CAMPINGZCBDAUYN"},
        {"BCOLLEZIONISMOA"},
        {"ALTIROCONLARCOB"},
        {"LAOIGGANIDRAIGM"},
        {"LIBGCINEMAIERLA"},
        {"OROTALIGUPORITS"},
        {"OTENOIZAMROFNIE"}};

    int x, y, dir;
    char parola[256];

    scanf("%255s", parola);

    //codice qui
    trova_parola(&x, &y, &dir, parola, tabella); //indirizzo al valore dell'intero
    printf("Parola %s ", parola);
    if (x != -1)
        printf("in (%d,%d), direzione %s\n", x, y, dir == 0 ? "s->d" : "d->s");
    else
        printf("non trovata\n");
}

void trova_parola(int *x, int *y, int *dir, char *parola, char **tabella)
{
    int i = 0;
    int k = 0;
    /* while (*parola != '\0')
    {
        parola += 1;
        i++;
    }*/
    while (k != 16)
    {
        k++;
        if (**tabella == *parola)
        {
            *tabella += 1;
            parola += 1;
        }
        else
        {
            *tabella += 1;
        }
    }
}
