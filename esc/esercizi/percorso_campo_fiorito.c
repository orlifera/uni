#include <stdio.h>

/*
 * Definire una funzione ricorsiva che determini 
 * se esiste un percorso che permetta di attraversare 
 * un campo fiorito, dal basso verso l'alto, 
 * senza calpestare alcun fiore. 
 * Il campo è rappresentato da una matrice, i cui valori
 * rappresentano la presenza di un fiore (0) oppure la sua
 * assenza (1).
 * E' possibile muoversi una casella in alto oppure una 
 * casella verso destra. 
 * Leggere le coordinate della casella di partenza 
 * da tastiera.  
 * Ad esempio se il campo è definito come segue: 
 * {0,0,0,1,0}
 * {0,1,0,1,1}
 * {1,0,1,1,0}
 * {1,0,1,1,1}
 * {1,0,1,0,0}
 * e la casella di partenza è (4,2), un percorso è il 
 * seguente: SU, SU, DESTRA, SU, SU (raffigurato dalle X) 
 * {0,0,0,X,0}
 * {0,1,0,X,1}
 * {1,0,X,X,0}
 * {1,0,X,1,1}
 * {1,0,X,0,0}
 */
int mossa(int righe, int colonne, int **mat, int x, int y);
void inizializza_coordinate(int **mat, int x, int y);

int main(void)
{

    int campo[5][5] = {
        {0, 0, 0, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 0, 1, 1, 0},
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 0}};
    int x, y;
    printf("Inserire coordinate prima mossa\n");
    scanf("%d", &x);
    scanf("%d", &y);

    if (mossa(5, 5, campo, x, y) == 1)
    {
        printf("Esiste un percorso da %d,%d alla riga 0\n", x, y);
    }
    else
    {
        printf("Non esiste un percorso da %d,%d alla riga 0\n", x, y);
    }
}

int mossa(int righe, int colonne, int **mat, int x, int y)
{
    int cella = **mat;
    righe = righe + x;
    colonne = colonne + y;
    if (righe == 0 && cella == 1)
    {
        return 1;
    }
    //TODO: controllo il contenuto della cella corrente; che ci faccio?
    if (cella == 1)
    {
        return mossa(righe - 1, colonne, mat, x, y);
    }
    else
    {
        return mossa(righe + 1, colonne + 1, mat, x, y);
    }
}
