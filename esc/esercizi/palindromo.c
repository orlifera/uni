#include <stdio.h>

/*
 * Dato un array di interi di lunghezza N, scriveru un programma che stampa
 * "L'array è palindromo" se l'array è palindromo o "L'array non è palindromo" se non lo è.
 * Un array è definito palindromo se invertendolo rimane uguale (es. [1, 2, 3, 2, 1] è palindromo)
 * ATTENZIONE: l'input non è più fisso, la dimensione N e i valori dell'array saranno forniti come input. 
*/
int palindromo(int *X, int dim);

int main()
{
    int dim;
    printf("Inserire dimensione array.\n");
    scanf("%d", &dim);

    int array[dim];

    for (int i = 0; i < dim; i++)
    {
        printf("Inserire un valore: ");
        scanf("%d", array + i);
    }
    int pal = palindromo(array, dim); //inizializzo una variabile pal al valore ritornato dalla funzione
    if (pal == 1)
    {
        printf("L'array è palindromo.\n");
    }
    else
    {
        printf("L'array non è palindromo.\n");
    }
}

int palindromo(int *X, int dim)
{
    int i = 0;                        //primo counter
    int j = dim - 1;                  //secondo counter che parte da dim - 1
    int flag = 1;                     //flag
    while (i != dim / 2 && flag != 0) //finché non arrivano a dimm/ 2 o flag == 0 itera
    {
        if (X[i] != X[j])
        {
            flag = 0;
        }
        i++; //aumenta i
        j--; //diminuisce j
    }
    return flag; //ritorna il valore di flag
}
