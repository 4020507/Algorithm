#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int dist[2][10003];
bool house[10001];
vector<pair<int, int>> edges[10003];
int x, y;
int V;

void dijkstra(int node, int index) {

    int i;

    queue<pair<int, int>> q;
    q.push({ node,0 });

    int d, sum, curr, next;

    dist[index][node] = 0;

    while (!q.empty()) {
        curr = q.front().first;
        d = q.front().second;

        q.pop();

        for (i = 0; i < edges[curr].size(); i++) {
            next = edges[curr][i].first;
            sum = edges[curr][i].second + d;

            if (index == 0 && sum > x) {
                continue;
            }
            else if (index == 1 && sum > y) {
                continue;
            }
            else if (sum < dist[index][next]) {
                dist[index][next] = sum;
                q.push({ next,sum });
            }
        }

    }
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int E, u, v, w, M, S;

    cin >> V >> E;

    int i;

    for (i = 1; i <= V; i++) {
        dist[0][i] = 1e9;
        dist[1][i] = 1e9;
        house[i] = true;
    }

    for (i = 0; i < E; i++) {
        cin >> u >> v >> w;

        edges[u].push_back({ v,w });
        edges[v].push_back({ u,w });
    }

    cin >> M >> x;

    for (i = 0; i < M; i++) {
        cin >> u;

        edges[V + 1].push_back({ u,0 });
        house[u] = false;
    }

    cin >> S >> y;

    for (i = 0; i < S; i++) {
        cin >> u;

        edges[V + 2].push_back({ u,0 });
        house[u] = false;
    }

    dijkstra(V + 1, 0);
    dijkstra(V + 2, 1);

    int ans = x + y + 1;

    for (i = 1; i <= V; i++) {
        if (house[i]) {
            if (dist[0][i] + dist[1][i] < ans) {
                ans = dist[0][i] + dist[1][i];
            }
        }
    }

    if (ans < x + y + 1) {
        cout << ans;
    }
    else {
        cout << -1;
    }
    return 0;
}
