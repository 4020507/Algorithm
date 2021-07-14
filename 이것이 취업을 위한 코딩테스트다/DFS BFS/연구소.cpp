#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int N, M;
int map[8][8];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int temp[8][8];
int result;

void virus(int a, int b)
{
    for (int i = 0;i < 4;i++)
    {
        int c = a + dx[i];
        int d = b + dy[i];

        if (c >= 0 && c < N && d >= 0 && d < M)
        {
            if (temp[c][d] == 0)
            {
                temp[c][d] = 2;
                virus(c, d);
            }
        }
    }
}

void safe()
{
    int count = 0;
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < M;j++)
        {
            if (temp[i][j] == 0)
            {
                count++;
            }
        }
    }

    result = max(result, count);
}
void dfs(int count)
{
    if (count == 3)
    {
        for (int i = 0;i < N;i++)
        {
            for (int j = 0;j < M;j++)
            {
                temp[i][j] = map[i][j];
            }
        }

        for (int i = 0;i < N;i++)
        {
            for (int j = 0;j < M;j++)
            {
                if (temp[i][j] == 2)
                {
                    virus(i, j);
                }
            }
        }
        safe();

    }
    else
    {
        for (int i = 0;i < N;i++)
        {
            for (int j = 0;j < M;j++)
            {
                if (map[i][j] == 0)
                {
                    map[i][j] = 1;
                    dfs(count + 1);
                    map[i][j] = 0;
                }
            }
        }
    }
}
int main(void) {
    
    cin >> N >> M;

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < M;j++)
            cin >> map[i][j];
    }

    result = 0;

    dfs(0);

    cout << result << endl;

    return 0;
    
}
