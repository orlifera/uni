#include <stdio.h>

/*
* Scrivete un programma che trovi il minimo ed il massimo
* di una lista di interi.
*
* Il programma deve stampare i valori trovati. Utilizzare:
* printf("Valore minimo: array[%d] -> %d\n", min_indice, array[min_indice]);
* printf("valore massimo: array[%d] -> %d", max_indice, array[max_indice]);
*
* Per la consegna utilizzare il seguente array: [3, 5, 1, 7, 0, 9, 4, 6, 2, 8]
*/

int main(void)
{
    int array[] = {3, 5, 1, 7, 0, 9, 4, 6, 2, 8};
    int min_indice = 0;
    int max_indice = 0;

    for (int i = 0; i < 10; i++)
    {
        if (array[i] < array[min_indice])
        {
            min_indice = i;
        }
        if (array[i] > array[max_indice])
        {
            max_indice = i;
        }
    }

    printf("Valore minimo: array[%d] -> %d\n", min_indice, array[min_indice]);
    printf("valore massimo: array[%d] -> %d\n", max_indice, array[max_indice]);

    return 0;
}
