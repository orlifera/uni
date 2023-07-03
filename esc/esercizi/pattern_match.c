#include <stdio.h>

/* Date due stringhe N e T, trovare la posizione del primo match di T in N.
 * Trovare un match significa trovare una sottosequenza di caratteri adiacenti in N uguali a T.
 * (ovvero una *(N+k)==*T, *(N+(k+1))==*(T+1), ..., *(N+(k+n))==*(T+n) dove n è (la lunghezza di T)-$
 * La posizione del match è uguale a quella del primo carattere matchato in N.
 * ES: N="programmazione2022", T="gra" -> "Match found at position 3"
 * ES: N="programmazione2020", T="ez" -> "No match found"
*/

unsigned int len(char *N);
unsigned int match(char *N, char *T, int N_len, int T_len);

int main()
{

    /* Nota:
     * 256 è la dimensione massima della stringa ma il numero di caratteri può essere inferiore
     * implementare una funzione len per misurare la lunghezza di una stringa
     * (contare quanti caratteri ci sono prima del delimiter "\0")*/
    char N[256];
    char T[256];
    printf("Inserire due stringhe.\n");
    scanf("%255s", N);
    scanf("%255s", T);
    int i = 0;
    int flag = 0;

    int N_len = len(N), T_len = len(T);
    for (i = 0; i < N_len; i++)
    {
        if (N[i] == T[0])
        {
            flag = 0;
            for (int k = 0; k < T_len; k++)
            {
                if (N[i + k] == T[k])
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
            }
            if (flag == 1)
            {
                printf("Match found at position %d\n", i);
                return 0;
            }
        }
    }

    printf("Match not found.\n");
}
unsigned int len(char *N)
{
    int i = 0;
    while (*N != '\0')
    {
        N += 1;
        i += 1;
    }
    return i;
}
