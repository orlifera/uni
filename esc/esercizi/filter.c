#include <stdio.h>

/* Dato un Array A di dimensione len, filtrare tutti gli elementi f.
 * Questo significa restituire l'array compattato composta da tutti gli elementi originali di A meno gli elementi uguali ad f.
 * ES: [1,24,3,4] 3 -> [1,24,4]
 * ES: [1,2,1,3,4,6] 1 -> [2,3,4,6]
*/
void filter(int *array, int *f, int *risultato, int len);
int counter(int len, int *array, int f);
int main()
{
    unsigned int len;
    int f = 0;
    printf("Inserire dimensione array\n");
    scanf("%2u", &len);
    int A[len];

    printf("Inserire valori array\n");
    for (int i = 0; i < len; i = i + 1)
    {
        scanf("%d", A + i);
    }
    printf("Inserire un valore da filtrare\n");
    scanf("%d", &f);

    int len_risultato = counter(len, A, f);
    printf("len_ris %d\n", len_risultato);

    int risultato[len_risultato];

    filter(A, &f, risultato, len);

    printf("[");
    for (int i = 0; i < len_risultato; i += 1)
    {
        printf(" %d", risultato[i]);
    }

    printf(" ]\n");
}

void filter(int *array, int *f, int *risultato, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (*array != *f)
        {
            *risultato = *array;
            risultato += 1;
        }

        array += 1;
    }
}

int counter(int len, int *array, int f)
{
    int lunghezza = len;
    for (int i = 0; i < len; i++)
    {
        if (*array == f)
        {
            lunghezza -= 1;
        }
        array += 1;
    }

    return lunghezza;
}
