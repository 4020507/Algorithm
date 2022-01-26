#pragma warning(disable:4996)
#include <iostream>
#include <math.h>
using namespace std;


int dx[4] = { 0,1,0,-1};
int dy[4] = { -1,0,1,0 };
int send[503][503];
int N;
int remains;
void spread(int i, int x, int y, int nx, int ny)
{
    int init = send[nx][ny];
    if (i == 0)
    {
        if (x - 1 >= 1)
        {
            send[x - 1][y] += floor(send[nx][ny] * 0.01);
        }
        else
            remains += floor(send[nx][ny] * 0.01);
        init -= floor(send[nx][ny] * 0.01);

        if (x + 1 <= N)
            send[x + 1][y] += floor(send[nx][ny] * 0.01);
        else
            remains += floor(send[nx][ny] * 0.01);
        init -= floor(send[nx][ny] * 0.01);

        if (x - 1 >= 1 && y - 1 >= 1)
        {
            send[x - 1][y - 1] += floor(send[nx][ny] * 0.07);
        }
        else
            remains += floor(send[nx][ny] * 0.07);
        init -= floor(send[nx][ny] * 0.07);

        if (x - 2 >= 1 && y - 1 >= 1)
        {
            send[x - 2][y - 1] += floor(send[nx][ny] * 0.02);
        }
        else
            remains += floor(send[nx][ny] * 0.02);
        init -= floor(send[nx][ny] * 0.02);

        if (x + 1 <= N && y - 1 >= 1)
        {
            send[x + 1][y - 1] += floor(send[nx][ny] * 0.07);
        }
        else
            remains += floor(send[nx][ny] * 0.07);
        init -= floor(send[nx][ny] * 0.07);

        if(x+2 <= N && y-1 >= 1)
            send[x + 2][y - 1] += floor(send[nx][ny] * 0.02);
        else
            remains += floor(send[nx][ny] * 0.02);
        init -= floor(send[nx][ny] * 0.02);

        if (x - 1 >= 1 && y - 2 >= 1)
            send[x - 1][y - 2] += floor(send[nx][ny] * 0.1);
        else
            remains += floor(send[nx][ny] * 0.1);
        init -= floor(send[nx][ny] * 0.1);

        if (x + 1 <= N && y - 2 >= 1)
            send[x + 1][y - 2] += floor(send[nx][ny] * 0.1);
        else
            remains += floor(send[nx][ny] * 0.1);
        init -= floor(send[nx][ny] * 0.1);

        if (y - 3 >= 1)
            send[x][y - 3] += floor(send[nx][ny] * 0.05);
        else
            remains += floor(send[nx][ny] * 0.05);
        init -= floor(send[nx][ny] * 0.05);
    }
    else if (i == 1)
    {
        if (y - 1 >= 1)
            send[x][y - 1] += floor(send[nx][ny] * 0.01);
        else
            remains += floor(send[nx][ny] * 0.01);
        init -= floor(send[nx][ny] * 0.01);

        if (y + 1 <= N)
            send[x][y + 1] += floor(send[nx][ny] * 0.01);
        else
            remains += floor(send[nx][ny] * 0.01);
        init -= floor(send[nx][ny] * 0.01);

        if (x + 1 <= N && y - 1 >= 1)
            send[x + 1][y - 1] += floor(send[nx][ny] * 0.07);
        else
            remains += floor(send[nx][ny] * 0.07);
        init -= floor(send[nx][ny] * 0.07);

        if (x + 1 <= N && y - 2 >= 1)
            send[x + 1][y - 2] += floor(send[nx][ny] * 0.02);
        else
            remains += floor(send[nx][ny] * 0.02);
        init -= floor(send[nx][ny] * 0.02);

        if (x + 1 <= N && y + 1 <= N)
            send[x + 1][y + 1] += floor(send[nx][ny] * 0.07);
        else
            remains += floor(send[nx][ny] * 0.07);
        init -= floor(send[nx][ny] * 0.07);

        if (x + 1 <= N && y + 2 <= N)
            send[x + 1][y + 2] += floor(send[nx][ny] * 0.02);
        else
            remains += floor(send[nx][ny] * 0.02);
        init -= floor(send[nx][ny] * 0.02);

        if (x + 2 <= N && y + 1 <= N)
            send[x + 2][y + 1] += floor(send[nx][ny] * 0.1);
        else
            remains += floor(send[nx][ny] * 0.1);
        init -= floor(send[nx][ny] * 0.1);

        if (x + 2 <= N && y - 1 >= 1)
            send[x + 2][y - 1] += floor(send[nx][ny] * 0.1);
        else
            remains += floor(send[nx][ny] * 0.1);
        init -= floor(send[nx][ny] * 0.1);

        if (x + 3 <= N)
            send[x + 3][y] += floor(send[nx][ny] * 0.05);
        else
            remains += floor(send[nx][ny] * 0.05);
        init -= floor(send[nx][ny] * 0.05);
    }
    else if (i == 2)
    {
        if (x - 1 >= 1)
            send[x - 1][y] += floor(send[nx][ny] * 0.01);
        else
            remains += floor(send[nx][ny] * 0.01);
        init -= floor(send[nx][ny] * 0.01);

        if (x + 1 <= N)
            send[x + 1][y] += floor(send[nx][ny] * 0.01);
        else
            remains += floor(send[nx][ny] * 0.01);
        init -= floor(send[nx][ny] * 0.01);

        if (x - 1 >= 1 && y + 1 <= N)
            send[x - 1][y + 1] += floor(send[nx][ny] * 0.07);
        else
            remains += floor(send[nx][ny] * 0.07);
        init -= floor(send[nx][ny] * 0.07);

        if (x - 2 >= 1 && y + 1 <= N)
            send[x - 2][y + 1] += floor(send[nx][ny] * 0.02);
        else
            remains += floor(send[nx][ny] * 0.02);
        init -= floor(send[nx][ny] * 0.02);

        if (x + 1 <= N && y + 1 <= N)
            send[x + 1][y + 1] += floor(send[nx][ny] * 0.07);
        else
            remains += floor(send[nx][ny] * 0.07);
        init -= floor(send[nx][ny] * 0.07);

        if (x + 2 <= N && y + 1 <= N)
            send[x + 2][y + 1] += floor(send[nx][ny] * 0.02);
        else
            remains += floor(send[nx][ny] * 0.02);
        init -= floor(send[nx][ny] * 0.02);

        if (x - 1 >= 1 && y + 2 <= N)
            send[x - 1][y + 2] += floor(send[nx][ny] * 0.1);
        else
            remains += floor(send[nx][ny] * 0.1);
        init -= floor(send[nx][ny] * 0.1);

        if (x + 1 <= N && y + 2 <= N)
            send[x + 1][y + 2] += floor(send[nx][ny] * 0.1);
        else
            remains += floor(send[nx][ny] * 0.1);
        init -= floor(send[nx][ny] * 0.1);

        if (y + 3 <= N)
            send[x][y + 3] += floor(send[nx][ny] * 0.05);
        else
            remains += floor(send[nx][ny] * 0.05);
        init -= floor(send[nx][ny] * 0.05);
    }
    else if (i == 3)
    {
        if (y - 1 >= 1)
            send[x][y - 1] += floor(send[nx][ny] * 0.01);
        else
            remains += floor(send[nx][ny] * 0.01);
        init -= floor(send[nx][ny] * 0.01);

        if (y + 1 <= N)
            send[x][y + 1] += floor(send[nx][ny] * 0.01);
        else
            remains += floor(send[nx][ny] * 0.01);
        init -= floor(send[nx][ny] * 0.01);

        if (x - 1 >= 1 && y - 1 >= 1)
            send[x - 1][y - 1] += floor(send[nx][ny] * 0.07);
        else
            remains += floor(send[nx][ny] * 0.07);
        init -= floor(send[nx][ny] * 0.07);

        if (x - 1 >= 1 && y - 2 >= 1)
            send[x - 1][y - 2] += floor(send[nx][ny] * 0.02);
        else
            remains += floor(send[nx][ny] * 0.02);
        init -= floor(send[nx][ny] * 0.02);

        if (x - 1 >= 1 && y + 1 <= N)
            send[x - 1][y + 1] += floor(send[nx][ny] * 0.07);
        else
            remains += floor(send[nx][ny] * 0.07);
        init -= floor(send[nx][ny] * 0.07);

        if (x - 1 >= 1 && y + 2 <= N)
            send[x - 1][y + 2] += floor(send[nx][ny] * 0.02);
        else
            remains += floor(send[nx][ny] * 0.02);
        init -= floor(send[nx][ny] * 0.02);

        if (x - 2 >= 1 && y + 1 <= N)
            send[x - 2][y + 1] += floor(send[nx][ny] * 0.1);
        else
            remains += floor(send[nx][ny] * 0.1);
        init -= floor(send[nx][ny] * 0.1);

        if (x - 2 >= 1 && y - 1 >= 1)
            send[x - 2][y - 1] += floor(send[nx][ny] * 0.1);
        else
            remains += floor(send[nx][ny] * 0.1);
        init -= floor(send[nx][ny] * 0.1);

        if (x - 3 >= 1)
            send[x - 3][y] += floor(send[nx][ny] * 0.05);
        else
            remains += floor(send[nx][ny] * 0.05);
        init -= floor(send[nx][ny] * 0.05);
    }

    send[nx][ny] = 0;

    if (i == 0)
    {
        if (ny - 1 >= 1)
            send[nx][ny - 1] += init;
        else
            remains += init;
    }
    else if (i == 1)
    {
        if (nx + 1 <= N)
            send[nx + 1][ny] += init;
        else
            remains += init;
    }
    else if (i == 2)
    {
        if (ny + 1 <= N)
            send[nx][ny + 1] += init;
        else
            remains += init;
    }
    else if (i == 3)
    {
        if (nx - 1 >= 1)
            send[nx - 1][ny] += init;
        else
            remains += init;
    }
}
int main()
{
    cin >> N;

    for (int i = 1;i <= N;i++)
    {
        for (int j = 1;j <= N;j++)
            cin >> send[i][j];
    }

    int x = N / 2 + 1;
    int y = x;
    int nx, ny;
    int move = 1;
    int i;
    remains = 0;
    while (1)
    {
        for (i = 0;i < move;i++)
        {

            nx = x + dx[0];
            ny = y + dy[0];

            spread(0, x, y, nx, ny);

            x = nx;
            y = ny;
            if (x == 1 && y == 1)
            {
                cout << remains;
                return 0;
            }
        }

        for (i = 0;i < move;i++)
        {
            nx = x + dx[1];
            ny = y + dy[1];

            spread(1, x, y, nx ,ny);
            x = nx;
            y = ny;
        }

        move++;

        for (i = 0;i < move;i++)
        {
            nx = x + dx[2];
            ny = y + dy[2];

            spread(2, x, y, nx ,ny);

            x = nx;
            y = ny;
        }

        for (i = 0;i < move;i++)
        {
            nx = x + dx[3];
            ny = y + dy[3];

            spread(3, x, y, nx, ny);
            x = nx;
            y = ny;
        }
        move++;
    }
    return 0;
}
