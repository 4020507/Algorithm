#pragma warning(disable:4996)
#include<iostream>
#include<queue>
using namespace std;

int N, M;
int buses[1001];
vector<pair<int,int>> graph[1001];
int table[1001];
int depart, arrive;

int main(void)
{
	cin >> N >> M;

	for (int i = 0;i < M;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ c,b });
	}

	cin >> depart >> arrive;

	priority_queue<pair<int,int>> q;
	q.push({ 0, depart });

	fill(table, table + 1001, 1e9);
	table[depart] = 0;
	int ans;
	while (!q.empty())
	{
		int cost = q.top().first;
		int node = q.top().second;
		q.pop();
		if (table[node] < -cost)
		{
			continue;
		}

		for (auto v : graph[node])
		{
			int dist = -cost + v.first;
			if (table[v.second] > dist)
			{
				q.push({ -dist,v.second });
				table[v.second] = dist;
			}
			
		}
	}

	cout << table[arrive];

	return 0;
}
