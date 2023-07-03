#include "partita.h"
#include "board.h"
#include "giocatore.h"
#include <stdio.h>

void gioca(char board[], void (*p1)(int *x, int *y), void (*p2)(int *x, int *y))
{
    int x, y;
    while (partita_terminata(board) == 0)
    {
        do
        {
            p1(&x, &y);
            effettua_mossa(board, x, y, SIMB_X);
        } while (mossa_ammissibile(board, x, y) == 0);
        print_board(board);
        //controllare se ho vinto qua
        do
        {
            p2(&x, &y);
            effettua_mossa(board, x, y, SIMB_O);
        } while (mossa_ammissibile(board, x, y) == 0);
        print_board(board);
    }
    if (board_vincente(board) == 1) //l'ultimo che ha giocato ha vinto
    {
        printf("La partita è terminata e il vincitore è %c", );
    }
}