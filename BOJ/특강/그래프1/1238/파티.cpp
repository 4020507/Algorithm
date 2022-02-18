#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1000
#define INF 1e9

int N, M, X;
int dist[MAX + 1][MAX+1];
vector < pair<int, int>> graph[MAX+1];

void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,start });

    int village, cost, next, w;
    while (!pq.empty())
    {
        cost = -pq.top().first;
        village = pq.top().second;
        pq.pop();

        if (dist[start][village] < cost)
            continue;
        for (auto g : graph[village])
        {
            next = g.first;
            w = cost + g.second;

            if (w < dist[start][next])
            {
                dist[start][next] = w;
                pq.push({ -w,next });
            }
        }
    }
}
int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> X;

    int start, end, taken;

    for (int i = 0;i < M;i++)
    {
        cin >> start >> end >> taken;

        graph[start].push_back({ end,taken });
    }

    for (int i = 1;i <= N;i++)
    {
        for (int j = 1;j <= N;j++)
            dist[i][j] = INF;
        dist[i][i] = 0;
        dijkstra(i);
        
    }

    int res = 0;

    for (int i = 1;i <= N;i++)
        res = max(res, dist[i][X] + dist[X][i]);

    cout << res;

    return 0;

}
