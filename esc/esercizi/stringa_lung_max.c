#include <stdio.h>

/*
 * Scrivere una funzione che, dato un array di stringhe,
 * restituisca la stringa di lunghezza massima. 
 * Nel main si dovrà stampare tale stringa.
 * Inoltre, si tratti in modo appropriato il caso in cui
 * il numero di stringhe nell'array sia zero. In particolare,
 * nel main si stampi "array vuoto\n". Se il numero di 
 * stringhe è maggiore di zero, utilizzare il seguente comando
 * nel main per la stampa della stringa più lunga:
 * 
 * printf("%s\n", stringa_lung_max(stringhe, num_stringhe));
 * 
 * Il numero di stringhe e le stringhe stesse sono lette da 
 * tastiera. 
 * 
 */

//char *stringa_lung_max(char stringhe[][256], int num_stringhe, int max);
char stringa_lung_max(char **stringhe, int num_stringhe)
{
    if (num_stringhe > 1)
    {
        return;
    }

    int lunghezza_stringa_corrente = 0;

    while (**stringhe != '\0')
    {
        lunghezza_stringa_corrente += 1;
        *stringhe += 1;
    }

    stringhe += 1;

    int lunghezza_stringa_succ = 0;
    while (**stringhe != '\0')
    {
        lunghezza_stringa_succ += 1;
        *stringhe += 1;
    }

    if (lunghezza_stringa_corrente < lunghezza_stringa_succ)
    {
        return stringa_lung_max(stringhe += 1, num_stringhe - 1);
    }
    else
    {
        return stringa_lung_max(stringhe, num_stringhe - 1);
    }
}

int main(void)
{

    int num_stringhe;
    int max = 0;
    printf("Inserire un numero di stringhe.\n");
    scanf("%d", &num_stringhe);
    if (num_stringhe == 0)
    {
        printf("L'array è vuoto.\n");
        return 0;
    }

    char stringhe[num_stringhe][256];
    for (int i = 0; i < num_stringhe; i += 1)
    {
        scanf("%255s", stringhe[i]);
    }

    char *s_max = stringa_lung_max(stringhe, num_stringhe);
    // printf("%s\n", (s_max==NULL)?"array vuoto": s_max);
    printf("La stringa più lunga è %s", s_max);
}
/*char *stringa_lung_max(char stringhe[][256], int num_stringhe, int max)

{
    if (num_stringhe == 0)
    {
        stringhe -= 1;
        return *stringhe;
    }
    int i = 0;
    while (**stringhe != '\0')
    {
        i += 1;
        *stringhe += 1;
    }
    if (i > max)
    {
        max = i;
    }

    return stringa_lung_max(stringhe + 1, num_stringhe - 1, max);
}
*/
