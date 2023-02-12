#include<iostream>
#include<queue>
#include<vector>
#pragma warning(disable:4996)

using namespace std;

long long cows[50001];
vector<pair<int, long long>> map[50001];

void dijkstra() {

	queue<pair<int, long long>> q;
	q.push({ 1,0 });
	cows[1] = 0;

	int farm, cowCnt, nextFarm;
	long long sum;
	int i;

	while (!q.empty()) {
		farm = q.front().first;
		cowCnt = q.front().second;

		q.pop();

		if (cows[farm] < cowCnt) {
			continue;
		}

		for (i = 0; i < map[farm].size(); i++) {
			nextFarm = map[farm][i].first;
			sum = cowCnt + map[farm][i].second;

			if (sum < cows[nextFarm]) {
				cows[nextFarm] = sum;
				q.push({ nextFarm,sum });
			}
		}
	}
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M, i;

	cin >> N >> M;

	int a, b, c;

	for (i = 0; i < M; i++) {
		cin >> a >> b >> c;

		map[a].push_back({ b,c });
		map[b].push_back({ a,c });
	}
	
	for (i = 1; i <= N; i++) {
		cows[i] = 1e9;
	}

	dijkstra();

	cout << cows[N];

	return 0;
}
