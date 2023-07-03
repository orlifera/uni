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
int mossa(int **mat, int coord_iniz_x, int coord_iniz_y);
void inizializza_coordinate(int **mat, int coord_iniz_x, int coord_iniz_y);
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

    if (mossa(campo, x, y) == 1)
    {
        printf("Esiste un percorso da %d,%d alla riga 0\n", x, y);
    }
    else
    {
        printf("Non esiste un percorso da %d,%d alla riga 0\n", x, y);
    }
}

int mossa(int **mat, int coord_iniz_x, int coord_iniz_y)
{
    mat = mat + coord_iniz_x;
    *mat = *mat + coord_iniz_y;
    if (**mat == 1)
    {
        mat -= 1;                                      //si sposta in su di una riga
        *mat += coord_iniz_y;                          // si sposta a dx di coord_iniz_y
        return mossa(mat, coord_iniz_x, coord_iniz_y); //ricorsione
    }
    else
    {
        *mat -= coord_iniz_y;                          //resetta il puntatore di array alla prima cella
        mat += 1;                                      //torna in giù di uno
        *mat += 1;                                     //va a dx di uno
        coord_iniz_y += 1;                             //aumenta il valore di y
        return mossa(mat, coord_iniz_x, coord_iniz_y); //ricorsione
    }
}

void inizializza_coordinate(int **mat, int coord_iniz_x, int coord_iniz_y)
{

    mat = mat + coord_iniz_x;
    *mat = *mat + coord_iniz_y;
}