#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M, x, y, K;
int map[20][20];
int dice[7];

bool east()
{
    if (y == M - 1)
        return false;
    y++;

    int temp[7];

    for (int i = 1;i <= 6;i++)
        temp[i] = dice[i];

    dice[1] = temp[4];
    dice[2];
    dice[3] = temp[1];
    dice[4] = temp[6];
    dice[5];
    dice[6] = temp[3];

    return true;
}

bool west()
{
    if (y == 0)
        return false;
    y--;

    int temp[7];

    for (int i = 1;i <= 6;i++)
        temp[i] = dice[i];

    dice[1] = temp[3];
    dice[2];
    dice[3] = temp[6];
    dice[4] = temp[1];
    dice[5];
    dice[6] = temp[4];

    return true;
}

bool north()
{
    if (x == 0)
        return false;
    x--;

    int temp[7];

    for (int i = 1;i <= 6;i++)
        temp[i] = dice[i];

    dice[1] = temp[5];
    dice[2] = temp[1];
    dice[3];
    dice[4];
    dice[5] = temp[6];
    dice[6] = temp[2];

    return true;
}

bool south()
{
    if (x == N - 1)
        return false;
    x++;

    int temp[7];

    for (int i = 1;i <= 6;i++)
        temp[i] = dice[i];

    dice[1] = temp[2];
    dice[2] = temp[6];
    dice[3];
    dice[4];
    dice[5] = temp[1];
    dice[6] = temp[5];
    return true;
}
int main(int argc, const char* argv[]) {

    cin >> N >> M >> x >> y >> K;

    memset(dice, 0, sizeof(dice));

    
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < M;j++)
            cin >> map[i][j];
    }

    int order;
    for (int i = 0;i < K;i++)
    {
        cin >> order;

        if (order == 1)
        {
            if (!east())
                continue;
        }
        else if (order == 2)
        {
            if (!west())
                continue;
        }
        else if (order == 3)
        {
            if (!north())
                continue;
        }
        else if (order == 4)
        {
            if (!south())
                continue;
        }

        if (map[x][y] == 0)
        {
            map[x][y] = dice[6];
        }
        else
        {
            dice[6] = map[x][y];
            map[x][y] = 0;
        }

        cout << dice[1] << '\n';
    }

    return 0;
}
