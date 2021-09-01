#include<iostream>
#include<string.h>
#include<stdio.h>
#include<queue>
#pragma warning(disable:4996)
using namespace std;

int N, M;
int graph[101][101];
bool visited[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans;

int main(int argc, char** argv)
{
    cin >> N >> M;
    memset(visited, false, sizeof(visited));

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < M;j++)
        {
            scanf("%1d", &graph[i][j]);
        }
    }

    visited[0][0] = true;

    queue < pair<int, pair<int, int>>> q;
    q.push({ 1, {0,0} });

    while (!q.empty())
    {
        int cost = q.front().first;
        int a = q.front().second.first;
        int b = q.front().second.second;

        if (a == N - 1 && b == M - 1)
        {
            ans = cost;
            break;
        }
        q.pop();

        for (int i = 0;i < 4;i++)
        {
            int c = a + dx[i];
            int d = b + dy[i];

            if (c >= 0 && c < N && d >= 0 && d < M)
            {
                if (graph[c][d] == 1 && !visited[c][d]) {
                    q.push({ cost + 1,{c,d} });
                    visited[c][d] = true;
                }
                    
            }
        }
    }
    cout << ans;
    return 0;
}
