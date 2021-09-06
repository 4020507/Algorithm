#include<iostream>
#include<queue>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;

int N, M;
bool visited[50][50];
int map[50][50];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { 1,0,-1,1,-1,1,-1,0 };

int bfs(int x, int y)
{
    queue<pair<int, pair<int,int>>> q;
    q.push({ 0,{x,y} });
    visited[x][y] = true;
    while (!q.empty())
    {
        int count = q.front().first;
        int a = q.front().second.first;
        int b = q.front().second.second;

        if (map[a][b] == 1)
        {
            return count;
        }
        q.pop();
        for (int i = 0;i < 8;i++)
        {
            int c = a + dx[i];
            int d = b + dy[i];

            if (c >= 0 && c < N && d >= 0 && d < M)
            {
                if (!visited[c][d])
                {
                    visited[c][d] = true;
                    q.push({ count + 1,{c,d} });
                }
            }
        }
    }

    return -1;
}
int main(int argc, char** argv)
{
    cin >> N >> M;

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < M;j++)
        {
            cin >> map[i][j];
        }
    }
    int ans = 0;

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < M;j++)
        {
            if (map[i][j] != 1)
            {
                memset(visited, false, sizeof(visited));
                ans = max(ans,bfs(i, j));
            }
        }
    }

    cout << ans;
    return 0;
}
