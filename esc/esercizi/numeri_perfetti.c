#include <stdio.h>

/*
* Scrivete un programma che trovi tutti i numeri perfetti tra due estremi. Sia estremi che i numeri trovati dovranno essere interi.
* Un numero perfetto si definisce tale quando la somma di tutti i suoi divisori eccetto se stesso è uguale al sumero stesso.
*
* Il programma deve stampare i valori trovati, utilizzare
* printf("Il numero %d è perfetto\n", limite_inferiore);
*
* Per la consegna utilizzare il seguenti limiti:
* limite_inferiore = 4
* limite_superiore = 30
*/
int divisori(int n);
int main(void)
{
    int limite_inferiore = 4;
    int limite_superiore = 30;
    for (int i = limite_inferiore; i <= limite_superiore; i++)
    {
        if (divisori(i) == i)
        {
            printf("Il numero %d è perfetto\n", i);
        }
    }
}
int divisori(int n)
{
    int somma = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            somma += i;
        }
    }
    return somma;
}
