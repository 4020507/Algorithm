#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int dist[801];
vector<pair<int, int>> v[801];
int N, E;
void dijkstra(int start) {

	queue<pair<int, int>> q;

	q.push({ 0,start });

	for (int i = 1; i <= N; i++) {
		dist[i] = 987654321;
	}

	dist[start] = 0;

	int curr, d, sum, node;

	while (!q.empty()) {
		d = q.front().first;
		curr = q.front().second;

		q.pop();

		for (auto i : v[curr]) {
			node = i.first;
			sum = i.second + d;

			if (dist[node] > sum) {
				dist[node] = sum;
				q.push({ dist[node],node });
			}
		}
	}
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	
	cin >> N >> E;

	int a, b, c;

	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;

		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	int v1, v2;

	cin >> v1 >> v2;
	dijkstra(1);

	int oneToV1 = dist[v1];
	int oneToV2 = dist[v2];

	dijkstra(v1);

	int v1Tov2 = dist[v2];
	int v1ToN = dist[N];

	dijkstra(v2);

	int v2ToN = dist[N];

	int ans =  min(oneToV1 + v1Tov2 + v2ToN, oneToV2 + v1Tov2 + v1ToN);

	if (v1Tov2 >= 987654321 || ans >= 987654321) {
		cout << -1;
	}
	else {
		cout << ans;
	}

	return 0;
}
