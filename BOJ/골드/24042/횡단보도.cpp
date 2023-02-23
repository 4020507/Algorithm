#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
#pragma warning(disable:4996)

using namespace std;

long long N, M;
long long dist[100001];
vector<pair<int, long long>> v[100001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	int a, b;

	for (int i = 1; i <= N; i++) {
		dist[i] = 700001 * N;
	}
	for (long long i = 0; i < M; i++) {
		cin >> a >> b;

		v[a].push_back({ b,i });
		v[b].push_back({ a,i });
	}

	dist[1] = 0;
	queue<pair<int, long long>>q;
	q.push({ 1,0 });
	int node, i, next;
	long long cycle;
	long long minutes;
	long long tmp;

	while (!q.empty()) {
		node = q.front().first;
		minutes = q.front().second;

		q.pop();

		if (node == N || dist[node] < minutes)
			continue;

		for (i = 0; i < v[node].size(); i++) {
			next = v[node][i].first;
			cycle = v[node][i].second;

			if (minutes >= cycle) {
				tmp = (minutes - cycle) / M;

				if ((minutes - cycle) % M != 0) {
					tmp++;
				}
				tmp = tmp * M + cycle + 1;
			}
			else {
				tmp = cycle + 1;
			}

			if (dist[next] > tmp) {
				dist[next] = tmp;
				q.push({ next,tmp });
			}
		}
	}

	cout << dist[N];

	return 0;
}
