#include <stdio.h>
#include <stdlib.h>

#define MAX_PPL 5
#define MAX_AGE 20
typedef struct persona
{
    int peso;
    int altezza;
    int eta;

} Ppl;
typedef Ppl *PPL;

int main()
{
    Ppl arch[MAX_PPL];
    for (int i = 0; i < MAX_PPL; i++)
    {

        printf("Inserire peso in Kg, altezza in cm e età.\n");
        scanf("%d%d%d", &(arch[i].peso), &(arch[i].altezza), &(arch[i].eta));
    }

    int temp;
    for (int k = 0; k < MAX_PPL - 1; k++)
    {
        for (int l = 0; l < MAX_PPL - 1; l++)
        {
            if (arch[l].eta > arch[l + 1].eta)
            {
                temp = arch[l + 1].eta;
                arch[l + 1].eta = arch[l].eta;
                arch[l].eta = temp;
            }
        }
    }

    printf("\tla lista in ordine crescente di eta' è:\n");
    for (int i = 1; i <= MAX_PPL; i++)
    {
        printf("%d. peso: %d altezza: %d eta: %d \n");
    }

    printf("-----------------------\n\tLa lista delle persone sotto i 20 anni è:\n");

    int i = 1;
    for (int k = 0; k < MAX_PPL; k++)
    {

        if (arch[k].eta <= MAX_AGE)
        {
            printf("%d.   peso: %d, altezza: %d, eta': %d\n", i, arch[k].peso, arch[k].altezza, arch[k].eta);
            i++;
        }
    }
}
