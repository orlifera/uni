#include <stdio.h>

/*
 * Scrivere una funzione che dati: 
 * - due array X e Y ordinati in modo crescente
 * - le loro dimensioni dim_X e dim_Y
 * - un terzo array Ord di dimensione dim_X+dim_Y
 * immetta i valori di X e Y in Ord in modo che anche
 * Ord risulti ordinato in modo crescente. Il prototipo
 * della funzione è il seguente
 *
 void combina_array(int *X, int dim_X, int *Y, int dim_Y, int *Ord)
 * 
 * Ad esempio se X={3,6,8} e Y={4,5,7,9}; 
 * Ord={3,4,5,6,7,8,9}
 * 
 */
void leggi_array(int *X, int dim);
void combina_array(int *X, int dim_X, int *Y, int dim_Y, int *Ord)
{
    /* 
        PRE: X, di dimensione dim_X ed Y, di dimensione dim_Y, sono ordinati in modo crescente;
        Ord è di dimensione dim_X+dim_Y
        POST: Ord contiene gli elementi di X e Y, Ord è ordinato in modo crescente  
    */
    int dim_ord = dim_X + dim_Y;
    int minore = 0;
    int maggiore = 0;
    int dim_min = dim_X < dim_Y ? dim_X : dim_Y;
    int dim_max = dim_X < dim_Y ? dim_Y : dim_X;

    for (int i = 0; i < dim_min; i++)
    {
        minore = *X < *Y ? *X : *Y;
        maggiore = *X > *Y ? *X : *Y;
        *Ord = minore;
        Ord += 1;
        *Ord = maggiore;
        Ord += 1;
        X += 1;
        Y += 1;
        printf("1\n");
    }

    if (dim_X < dim_Y)
    {
        printf("2\n");
        for (int c = dim_min; c < dim_max; c++)
        {
            //TODO: Controlla che questo codice sia corretto; esecuzione mentale
            *Ord = *Y;
            Ord += 1;
            Y += 1;
        }
    }
    else
    {
        printf("3\n");
        //TODO: Scrivi la casisttica opposta; quando sei sicuro, esecuzione mentale
        for (int k = dim_min; k < dim_max; k++)
        {
            //TODO: Controlla che questo codice sia corretto; esecuzione mentale
            *Ord = *X;
            Ord += 1;
            X += 1;
        }
    }
    //TODO: il codice è giusto? Esegui con tutte casistiche, specialmente inventate
    //TODO: Il codice funziona PERFETTAMENTE? Snellisci
}

int main(void)
{
    int dim_X;
    int dim_Y;
    printf("Inserire due dimensioni degli array X e Y.\n");
    scanf("%d%d", &dim_X, &dim_Y);
    int dim_Z = dim_X + dim_Y;
    int X[dim_X];
    int Y[dim_Y];
    int Z[dim_Z];
    printf("Inserire i valori del primo array\n");
    leggi_array(X, dim_X);
    printf("Inserire i valori del secondo array\n");
    leggi_array(Y, dim_Y);
    /* int X[] = {3, 6, 8};
    int Y[] = {4, 5, 7, 9};
    int Z[7];*/

    combina_array(X, dim_X, Y, dim_Y, Z);
    //printf("%d\n", dim_Z);
    printf("{");
    for (int i = 0; i < dim_Z; i += 1)
    {
        printf(" %d ", Z[i]);
    }
    printf("}");
    printf("\n");
}

void leggi_array(int *X, int dim)
{
    for (int k = 0; k < dim; k++)
    {
        scanf("%d", &X[k]);
    }
}
