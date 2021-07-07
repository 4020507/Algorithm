#pragma warning(disable:4996)
#include<iostream>
#include<queue>
#include<vector>
#define INF 1e9

using namespace std;

vector<pair<int,int>> v[30001];
int d[30001];


void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    d[start] = 0;

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d[node] < cost)
            continue;

        for (int i = 0;i < v[node].size();i++)
        {
            int dist = cost + v[node][i].second;

            if (d[v[node][i].first] > dist)
            {
                d[v[node][i].first] = dist;
                pq.push(make_pair(-dist, v[node][i].first));
            }
        }
    }
}
int main(void) {
    
    int N, M, C;
    
    cin >> N >> M >> C;

    for (int i = 0;i < M;i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
    }

    fill(d, d + 30001,INF);

    dijkstra(C);

    int taken = 0;
    int count = 0;
    for (int i = 1;i <= N;i++)
    {
        if (d[i] == INF)
            continue;
        if (d[i] != INF && d[i] != 0)
            count++;
        taken = max(taken, d[i]);
    }

    cout << count << " " << taken << endl;
    return 0;
    
}
