#include <stdio.h>

void bishop(int C[][8], int x, int y);
void init(int C[][8]);
int mossa(int C[][8], int x, int y);
int main()
{
    int a[8][8];
    init(a);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    printf("-------------------\n");
    bishop(a, 3, 4);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
}

void bishop(int C[][8], int x, int y)
{
    int i = 0;
    init(C);
    for (i = 0; mossa(C, x + i, y + i); i++)
        ;
    for (i = 0; mossa(C, x - i, y - i); i++)
        ;
    for (i = 0; mossa(C, x - i, y + i); i++)
        ;
    for (i = 0; mossa(C, x + i, y - i); i++)
        ;
}

void init(int C[][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            C[i][j] = 0;
        }
    }
}

int mossa(int C[][8], int x, int y)
{
    if (x >= 0 && x < 8 && y >= 0 && y < 8)
    {
        C[x][y] = 1;
        return 1;
    }
    return 0;
}