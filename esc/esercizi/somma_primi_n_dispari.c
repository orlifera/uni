#include <stdio.h>

/*
 * Definire una funzione che, dato un parametro intero n,
 * restituisca la somma dei numeri naturali dispari fino ad n incluso:
 * 
 * int sommaDispariN(int n);
 *  
 * Nel main stampare la somma restituita a video. 
 * Ad es. se n=8 stampa (notate l'a capo finale)
 * Somma dei numeri dispari minori di n: 16
 * 
 */
int sommaDispariN(int n);

int main(void)
{

    int n;
    //leggere da input n
    scanf("%d", &n);

    printf("Somma dei numeri dispari minori di n: %d\n", sommaDispariN(n));
}

int sommaDispariN(int n)
{
    int somma = 0;

    for (int i = 0; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            somma += i;
        }
    }

    return somma;
}
