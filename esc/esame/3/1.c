#include <stdio.h>

int bishop(int m[][8], int x, int y);
int mossa(int m[][8], int x, int y);
void init(int m[][8]);

int main()
{
    int a[8][8];
    int x = 2;
    int y = 3;
    init(a);
    mossa(a, x, y);
    bishop(a, x, y);
}

void init(int m[][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            m[i][j] = 0;
        }
    }
}

int mossa(int m[][8], int x, int y)
{
    if (x >= 0 && x < 8 && y >= 0 && y < 8)
    {
        m[x][y] = 1;
        return 1;
    }
    return 0;
}

int bishop(int m[][8], int x, int y)
{
    for (int i = 0; mossa(m, x + 1, y + 1); i++)
        ;
    for (int i = 0; mossa(m, x + 1, y - 1); i++)
        ;
    for (int i = 0; mossa(m, x - 1, y + 1); i++)
        ;
    for (int i = 0; mossa(m, x - 1, y - 1); i++)
        ;
}