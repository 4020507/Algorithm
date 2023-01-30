#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


vector<pair<int, int>> cables[1001];
int dist[1001];
int N;

int dijkstra(int K, int mid) {
    queue<pair<int,int>> q;

    q.push({ 1,0 });

    int curr, d, i, next, sum;

    while (!q.empty()) {
        curr = q.front().first;
        d = q.front().second;

        q.pop();

        if (dist[curr] < d) {
            continue;
        }

        for (i = 0; i < cables[curr].size(); i++) {
            sum = d + (cables[curr][i].second > mid);
            next = cables[curr][i].first;

            if (dist[next] > sum) {
                dist[next] = sum;
                q.push({ next,sum });
            }
        }
    }

    return dist[N] <= K;
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int P, K;

    cin >> N >> P >> K;

    int a, b, c, i;
    int left = 0;
    int right = 0;

    for (i = 0; i < P; i++) {
        cin >> a >> b >> c;

        cables[a].push_back({ b,c });
        cables[b].push_back({ a,c });

        right = max(right, c);
    }

    int mid;
    int ans = -1;

    while (left <= right) {
        mid = (left + right) / 2;

        dist[1] = 0;
        for (i = 2; i <= N; i++) {
            dist[i] = 1e9;
        }

        if (dijkstra(K,mid)) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}
