#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

vector<pair<int,int>> local[101];
int items[101];
int dist[101];
int N, M, R;
int ans;
void dijk(int start) {
    queue<int>q;

    q.push({start});

    for (int i = 1; i <= N; i++)
        dist[i] = 1e9;

    int node, nxt, item, cost;
    dist[start] = 0;

    while (!q.empty()) {
        node = q.front();
        item = dist[node];

        q.pop();

        for (int i = 0; i < local[node].size(); i++) {
            nxt = local[node][i].first;
            cost = local[node][i].second;

            if (dist[nxt] > item + cost) {
                dist[nxt] = cost + item;
                q.push({ nxt });
            }
        }
    }
    item = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] <= M)
            item += items[i];
    }

    ans = max(ans, item);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N >> M >> R;

    for (int i = 1; i <= N; i++) {
        cin >> items[i];
    }

    int a, b, c;
    ans = 0;

    for (int i = 0; i < R; i++) {
        cin >> a >> b >> c;
        local[a].push_back({ b,c });
        local[b].push_back({ a,c });
    }

    for (int i = 1; i <= N; i++)
        dijk(i);

    cout << ans;

    return 0;

}
