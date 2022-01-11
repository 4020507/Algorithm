#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 20000
#define INF 1e9

int V, E;
int dist[MAX + 1];
vector < pair<int, int>> graph[MAX+1];

int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> E;
    int start;
    cin >> start;
    
    for (int i = 1;i <= V;i++)
        dist[i] = INF;

    int u, v, w;
    dist[start] = 0;
    for (int i = 0;i < E;i++)
    {
        //u->v까지 가는데 w만큼
        cin >> u >> v >> w;
        graph[u].push_back({ w,v });
    }

    priority_queue<pair<int, int>> pq;
    pq.push({ 0,start });
    int cost, next;
    while (!pq.empty())
    {
        cost = -pq.top().first;
        start = pq.top().second;
        pq.pop();

        if (dist[start] < cost)
            continue;
        
        for (auto g : graph[start])
        {
            next = g.second;
            w = g.first + cost;

            if (dist[next] > w)
            {
                dist[next] = w;
                pq.push({ -w,next });
            }
        }
    }

    for (int i = 1;i <= V;i++)
    {
        if (dist[i] != INF)
            cout << dist[i] << '\n';
        else
            cout << "INF" << '\n';
    }

    return 0;

}
