#pragma warning(disable:4996)

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;


int N, M;
int rectangular[50][50];
int ans;

void make(int x, int y, int ny)
{
    if (ny == M)
        return;
    int diff = ny - y;

    if (x + diff >= N)
        return;
    if (rectangular[x][y] == rectangular[x][ny])
    {
        if (rectangular[x][y] == rectangular[x + diff][y] && rectangular[x][y] == rectangular[x + diff][ny])
        {
            ans = max(ans, (diff+1) * (diff+1));
        }
    }

    make(x, y, ny + 1);
}

int main(int argc, const char* argv[]) {

    cin >> N >> M;
    
    for (int i = 0;i < N;i++)
        for (int j = 0;j < M;j++)
            scanf("%1d", &rectangular[i][j]);
    ans = 1;
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < M;j++)
        {
            for (int k = j + 1;k < M;k++)
            {
                make(i, j, k);
            }
        }
    }

    cout << ans;

    return 0;
}
