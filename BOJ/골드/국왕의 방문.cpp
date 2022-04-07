#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

class node {
public:
	int idx;
	int val;
};

struct cmp{

	bool operator()(node & n1, node & n2) {
		return n1.val > n2.val;
	}

};
vector<pair<int, int>> connected[1001];
int road[1001][1001];
int dist[1001];
vector<int> king;
pair<int,int> visitingKing[1001][1001];
int N, M, A, B, K, G;
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> N >> M;
	cin >> A >> B >> K >> G;
	int next;
	for (int i = 0;i < G;i++) {
		cin >> next;
		king.push_back(next);
	}

	int a, b, c;
	for (int i = 0;i < M;i++) {
		cin >> a >> b >> c;
		connected[a].push_back({ b,c });
		connected[b].push_back({ a,c });
		road[a][b] = c;
		road[b][a] = c;
	}

	int start = 0;
	memset(visitingKing, 0, sizeof(visitingKing));
	for (int i = 0;i < king.size() - 1;i++) {
		visitingKing[king[i]][king[i+1]].first = start;
		visitingKing[king[i + 1]][king[i]].first = start;
		start += road[king[i]][king[i + 1]];
		visitingKing[king[i]][king[i+1]].second = start - 1;
		visitingKing[king[i + 1]][king[i]].second = start - 1;
	}

	priority_queue<node,vector<node>,cmp> pq;
	pq.push({ A,K });

	int cost;
	fill(dist, dist + N + 1, 1e9);
	dist[A] = K;
	while (!pq.empty()) {
		next = pq.top().idx;
		cost = pq.top().val;
		pq.pop();

		if (dist[next] < cost)
			continue;

		if (next == B) {
			cout << cost - K;
			break;
		}

		for (int i = 0;i < connected[next].size();i++) {
			a = connected[next][i].first;
			b = connected[next][i].second;
			c = 0;
			if (visitingKing[next][a].first <= cost && visitingKing[next][a].second >= cost) {
				c = visitingKing[next][a].second - cost + 1;
			}

			if (dist[a] > b + c + cost)
			{
				dist[a] = b + c + cost;
				pq.push({ a,dist[a] });
			}
		}
	}
	return 0;
}
