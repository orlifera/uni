#include "giocatore.h"
#include "board.h"
#include <stdlib.h>
#include <stdio.h>

void scegli_mossa_utente(int *x, int *y)
{
    printf("Inserisci Mossa: ");
    scanf("%d %d", x, y);
}

void scegli_mossa_computer(int *x, int *y)
{
    int x = rand() % BOARD_LATO;
    int y = rand() % BOARD_LATO;
}
