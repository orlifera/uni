#include <stdio.h>
#include "board.h"

int board_riempita(char board[])
{
    /* 
        POST Restituisce 
                1 se tutte le caselle hanno un simbolo diverso da CASELLA_VUOTA (lo spazio)
                0 altrimenti
    */
    for (int i = 0; i < BOARD_SIZE; i += 1)
        if (board[i] == CASELLA_VUOTA)
            return 0;
    return 1;
}

int board_vincente(char board[])
{
    /* 
        PRE board ha dimensione BOARD_SIZE = BOARD_LATO*BOARD_LATO
        POST Restituisce 
                1 se uno dei due giocatori ha vinto (si hanno 3 simboli uguali su una riga, una colonna o su una diagonale)
                0 altrimenti
    */
    for (int i = 0; i < BOARD_LATO; i += 1)
        if (tris_in_riga(board, i) == 1 || tris_in_colonna(board, i) == 1)
            return 1;
    if (tris_in_diagonali(board) == 1)
        return 1;
    return 0;
}

void effettua_mossa(char board[], int x, int y, char simbolo_giocatore)
{
    /*
        POST board cambiata aggiungendo la mossa (x,y) se ammissibile.  
    */
    if (mossa_ammissibile(board, x, y))
        board[x * BOARD_LATO + y] = simbolo_giocatore;
}

int mossa_ammissibile(char board[], int x, int y)
{
    /*
        L'utente inserisce le coordinate bidimensionali x,y della mossa,
        board[] è un vettore unidimensionale. 
        Una mossa ammissibile è se le coordinate sono all'interno 
        delle dimensioni della board (BOARD_LATO x BOARD_LATO) e 
        la casella non è già stata selezionata da un altro giocatore. 

        PRE board è un array di dimensione BOARD_SIZE
        POST restituisce 1 se la mossa è ammissibile, 0 altrimenti
     */

    // INSERITE IL CODICE QUA
    if (board[x * BOARD_LATO + y] != CASELLA_VUOTA || board[x * BOARD_LATO + y] >= BOARD_SIZE)
    {
        return 0;
    }
    return 1;
}

int partita_terminata(char board[])
{
    /*
     * PRE board è un array di dimensione BOARD_SIZE
     * POST restituisce 
                1 se la partita è terminata
                0 altrimenti
     */
    if (board_vincente(board) == 1 || board_riempita(board) == 1)
        return 1;
    return 0;
}

void print_board(char board[])
{
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[0], board[1], board[2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[3], board[4], board[5]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", board[6], board[7], board[8]);

    printf("     |     |     \n\n");
}

void reset_board(char board[])
{
    /*
     * PRE: board ha dimensione BOARD_SIZE
     * POST per ogni i tale che 0<=i<BOARD_SIZE si ha board[i]=CASELLA_VUOTA
     */
    for (int i = 0; i < BOARD_SIZE; i += 1)
        board[i] = CASELLA_VUOTA;
}

int tris_in_colonna(char board[], int num_col)
{
    /* 
        POST Restituisce 
                1 se la riga num_riga è non vuota e con tutti i simboli uguali
                0 altrimenti
    */

    if (board[num_col] == CASELLA_VUOTA)
    {
        return 0;
    }
    for (int i = 1; i < BOARD_LATO; i++)
    {
        if (board[num_col] != board[num_col + (BOARD_LATO * i)])
        {
            return 0;
        }
    }

    return 1;
}

int tris_in_diagonali(char board[])
{
    if (board[0] == CASELLA_VUOTA && board[BOARD_LATO - 1] == CASELLA_VUOTA)
    {
        return 0;
    }

    if (board[0] != CASELLA_VUOTA)
    {
        for (int i = 2; i <= BOARD_LATO; i++)
        {
            if (board[0] != board[(BOARD_LATO * i) - i])
            {
                return 0;
            }
        }
    }
    if (board[BOARD_LATO - 1] != CASELLA_VUOTA)
    {
        for (int i = 1; i < BOARD_LATO; i++)
        {
            if (board[BOARD_LATO - 1] != board[(BOARD_LATO * i)])
            {
                return 0;
            }
        }
    }
    return 1;
}

int tris_in_riga(char board[], int num_riga)
{
    /* 
        POST Restituisce 
                1 se la riga num_riga è non vuota e con tutti i simboli uguali
                0 altrimenti
    */
    if (board[num_riga * BOARD_LATO] == CASELLA_VUOTA)
        return 0;
    for (int i = 1; i < BOARD_LATO; i++)
        if (board[num_riga * BOARD_LATO] != board[num_riga * BOARD_LATO + i])
            return 0;
    return 1;
}
