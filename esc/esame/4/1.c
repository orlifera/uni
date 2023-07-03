#include <stdio.h>
#define DIM_X 5
#define DIM_Y 5
int mossa(int m[DIM_X][DIM_Y], int x, int y);

int main()
{
}

int mossa(int m[DIM_X][DIM_Y], int x, int y)
{
    if (x < 0 || x > DIM_X - 1 || y < 0 || y > DIM_Y - 1)
    {
        return 0;
    }
    if (m[x][y] == 0)
    {
        return 0;
    }
    if (x == 0)
    {
        return 1;
    }
    else
    {
        return mossa(m, x - 1, y) + mossa(m, x, y - 1);
    }
}
