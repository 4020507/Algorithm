#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;

int N, M, V;
int graph[1001][1001];
bool visited[1001];
vector<int> d;
vector<int> b;
void dfs(int v)
{
    visited[v] = true;
    d.push_back(v);
    for (int i = 1;i <= N;i++)
    {
        if (graph[v][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}

void bfs(int v)
{
    queue<int> q;
    q.push(v);
    
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        if (visited[a])
            continue;
        visited[a] = true;
        b.push_back(a);
        for (int i = 1;i <= N;i++)
        {
            if (graph[a][i] == 1 && !visited[i])
            {
                q.push(i);
            }
        }

    }
}
int main(int argc, char** argv)
{
    cin >> N >> M >> V;

    for (int i = 0;i < M;i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    memset(visited, false, sizeof(visited));
    
    dfs(V);
    memset(visited, false, sizeof(visited));
    bfs(V);

    for (auto i : d)
    {
        cout << i << ' ';
    }
    cout << '\n';

    for (auto i : b)
    {
        cout << i << ' ';
    }
    return 0;
}
