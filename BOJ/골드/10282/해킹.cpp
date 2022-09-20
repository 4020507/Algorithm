#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>

#define INF 1000000000
using namespace std;

vector<pair<int, int>> computers[10001];
int dist[10001];
int n, d, c;

void dijkstra() {

    queue<pair<int, int>> q;
    q.push({ c,0 });
    int ans = 0;

    int curr, next, taken, sum;

    while (!q.empty()) {
        curr = q.front().first;
        taken = q.front().second;

        q.pop();

        if (dist[curr] < taken) {
            continue;
        }

        for (auto com : computers[curr]) {
            next = com.first;
            sum = com.second + taken;

            if (sum < dist[next]) {
                dist[next] = sum;
                q.push({ next,sum });
            }
        }
    }
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, i, j;
    int a, b, s;
    int ans, cnt;

    cin >> T;

    for (i = 0; i < T; i++) {
        cin >> n >> d >> c;

        for (j = 1; j <= n; j++) {
            dist[j] = INF;
            computers[j].clear();
        }
        
        for (j = 0; j < d; j++) {
            cin >> a >> b >> s;

            computers[b].push_back({ a,s });
        }

        dist[c] = 0;
        dijkstra();
        ans = 0;
        cnt = 0;

        for (j = 1; j <= n; j++) {
            if (dist[j] != INF) {
                ans = max(ans, dist[j]);
                cnt++;
            }
        }

        cout << cnt<<' '<< ans << '\n';
    }

    return 0;
}
