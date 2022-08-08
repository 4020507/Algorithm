#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string.h>
#pragma warning(disable:4996)

#define INF 1e9

using namespace std;

int dist[2001];
int gDist[2001];
int hDist[2001];
int sDist[2001];

vector<pair<int, int>> v[2001];
vector<int> arrival;
vector<int> ans;

int n, m, t;
int s, g, h;

void dijkstra(int start) {
	queue<pair<int, int>>q;
	q.push({ start,0 });

	int i;

	for (i = 1; i <= n; i++) {
		dist[i] = INF;
	}

	dist[start] = 0;

	int curr, d, sum, next;

	while (!q.empty()) {
		curr = q.front().first;
		d = q.front().second;

		q.pop();

		for (i = 0; i < v[curr].size(); i++) {
			next = v[curr][i].second;
			sum = v[curr][i].first + d;

			if (dist[next] > sum) {
				dist[next] = sum;
				q.push({ next,sum });
			}
		}
	}
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T, i, a, b, d;
	cin >> T;

	int sTog, sToh, gh;


	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		ans.clear();
		arrival.clear();

		for (i = 1; i <= n; i++) {
			v[i].clear();
		}

		for (i = 0; i < m; i++) {
			cin >> a >> b >> d;

			v[a].push_back({ d,b });
			v[b].push_back({ d,a });
		}

		gh = sTog = sToh = 0;

		for (i = 0; i < v[g].size(); i++) {
			if (v[g][i].second == h) {
				gh = v[g][i].first;
				break;
			}
		}
		for (i = 0; i < t; i++) {
			cin >> a;
			arrival.push_back(a);
		}

		dijkstra(s);
		sTog = dist[g];
		sToh = dist[h];

		for (i = 1; i <= n; i++) {
			sDist[i] = dist[i];
		}
		dijkstra(g);

		for (i = 1; i <= n; i++) {
			gDist[i] = dist[i];
		}

		dijkstra(h);
		

		for (i = 1; i <= n; i++) {
			hDist[i] = dist[i];
		}

		for (i = 0; i < t; i++) {
			d = arrival[i];

			if (sDist[d] == gh + sTog + hDist[d]) {
				ans.push_back(d);
			}
			else if (sDist[d] == gh + sToh + gDist[d]) {
				ans.push_back(d);
			}
		}

		sort(ans.begin(), ans.end());

		for (i = 0; i < ans.size(); i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';

	}

	return 0;
}
