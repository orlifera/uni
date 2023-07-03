#include <stdio.h>

void copia_array(int *X, int dim_X, int *Y, int dim_Y, int *Ord);
void ordina_array(int *Ord);

int main()
{
    int X[] = {3, 6, 8};
    int Y[] = {4, 5, 7, 9};
    int Z[7];

    copia_array(X, 3, Y, 4, Z);

    for (int i = 0; i <)

        printf("{");
    for (int i = 0; i < 7; i += 1)
    {
        printf(" %d ", Z[i]);
    }
    printf("}");
    printf("\n");
}

void copia_array(int *X, int dim_X, int *Y, int dim_Y, int *Ord)
{
    int dim_Ord = dim_X + dim_Y;
    for (int i = 0; i < dim_X; i++)
    {
        *Ord = *X;
        Ord += 1;
        X += 1;
    }

    for (int j = dim_X; j < dim_Ord; j++)
    {
        *Ord = *Y;
        Ord += 1;
        Y += 1;
    }
}
