#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> v[1001];
int n, m;
int dist[1001];
int parent[1001];
int A, B;

void dijkstra() {

    dist[A] = 0;

    queue<pair<int, int>> q;
    q.push({ A,0 });

    int curr, cost, next, sum;

    while (!q.empty()) {
        curr = q.front().first;
        cost = q.front().second;

        q.pop();

        if (dist[curr] < cost)
            continue;

        for (auto a : v[curr]) {
            next = a.first;
            sum = a.second + cost;

            if (dist[next] > sum) {
                dist[next] = sum;
                parent[next] = curr;
                q.push({ next,sum });
            }
        }
    }
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    int a, b, c;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        v[a].push_back({ b,c });
    }

    for (int i = 1; i <= n; i++) {
        fill(dist, dist + n + 1, 1e9);
    }

    cin >> A >> B;
    memset(parent, 0, sizeof(parent));

    dijkstra();

    vector<int> route;

    int curr;
    curr = B;

    route.push_back(B);
    while (parent[curr] != 0) {
        curr = parent[curr];
        route.push_back(curr);
    }

    cout << dist[B] << '\n';
    cout << route.size() << '\n';

    for (int i = route.size() - 1; i >= 0; i--) {
        cout << route[i] << ' ';
    }
    return 0;
}
