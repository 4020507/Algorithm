#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

int dice[7] = { 0,1,2,3,4,5,6 };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int map[21][21];
int visited[21][21];
int N, M, K, x, y;

void east()
{
    int temp1 = dice[1];
    int temp2 = dice[2];
    int temp3 = dice[3];
    int temp4 = dice[4];
    int temp5 = dice[5];
    int temp6 = dice[6];

    dice[1] = temp4;
    dice[2] = temp2;
    dice[3] = temp1;
    dice[4] = temp6;;
    dice[5] = temp5;
    dice[6] = temp3;
}

void west()
{
    int temp1 = dice[1];
    int temp2 = dice[2];
    int temp3 = dice[3];
    int temp4 = dice[4];
    int temp5 = dice[5];
    int temp6 = dice[6];

    dice[1] = temp3;
    dice[2] = temp2;
    dice[3] = temp6;
    dice[4] = temp1;;
    dice[5] = temp5;
    dice[6] = temp4;
}

void north()
{
    int temp1 = dice[1];
    int temp2 = dice[2];
    int temp3 = dice[3];
    int temp4 = dice[4];
    int temp5 = dice[5];
    int temp6 = dice[6];

    dice[1] = temp5;
    dice[2] = temp1;
    dice[3] = temp3;
    dice[4] = temp4;;
    dice[5] = temp6;
    dice[6] = temp2;
}

void south()
{
    int temp1 = dice[1];
    int temp2 = dice[2];
    int temp3 = dice[3];
    int temp4 = dice[4];
    int temp5 = dice[5];
    int temp6 = dice[6];

    dice[1] = temp2;
    dice[2] = temp6;
    dice[3] = temp3;
    dice[4] = temp4;;
    dice[5] = temp1;
    dice[6] = temp5;
}

int reverse(int d)
{
    if (d == 0)
        return 1;
    if (d == 1)
        return 0;
    if (d == 2)
        return 3;
    else
        return 2;
}

int calc(int x, int y)
{
    memset(visited, false, sizeof(visited));
    int num = map[x][y];
    int cnt = 1;

    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = true;

    int nx, ny;

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0;i < 4;i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                if (num == map[nx][ny] && !visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push({ nx,ny });
                    cnt++;
                }
            }
        }
    }

    return num * cnt;
}

int setDir(int d, int res)
{
    if (res > 0)
    {
        switch (d)
        {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 1;
        case 3:
            return 0;
        }
    }
    else if (res < 0)
    {
        switch (d)
        {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return 0;
        case 3:
            return 1;
        }
    }

    return d;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> N >> M >> K;

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < M;j++)
            cin >> map[i][j];
    }
    int x, y, d;
    x = y = d = 0;
    int nx, ny;
    int ans = 0;

    for (int i = 0;i < K;i++)
    {
        nx = x + dx[d];
        ny = y + dy[d];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
        {
            d = reverse(d);
            nx = x + dx[d];
            ny = y + dy[d];
        }

        ans += calc(nx, ny);
        
        if (d == 0)
            east();
        else if (d == 1)
            west();
        else if (d == 2)
            south();
        else
            north();
        d = setDir(d, dice[6] - map[nx][ny]);
        x = nx;
        y = ny;
    }

    cout << ans;

    return 0;
}
