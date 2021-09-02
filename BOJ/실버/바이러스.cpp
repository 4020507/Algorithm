#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;

int N;
int graph[101][101];
int main(int argc, char** argv)
{
    cin >> N;

    int e;
    cin >> e;

    memset(graph, 1, sizeof(graph));
    for (int i = 0;i < e;i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    int count = 0;
    queue<int> q;
    for (int i = 2;i <= N;i++)
    {
        if (graph[1][i] == 1)
        {
            q.push(i);
        }
    }
    bool visited[101];
    memset(visited, false, sizeof(visited));
    visited[1] = true;
    while (!q.empty())
    {
        int a = q.front();

        q.pop();
        if (visited[a])
            continue;

        visited[a] = true;
        count++;

        for (int i = 1;i <= N;i++)
        {
            if (!visited[i] && graph[a][i] == 1)
            {
                q.push(i);
            }
        }
    }
    cout << count;
    return 0;
}
