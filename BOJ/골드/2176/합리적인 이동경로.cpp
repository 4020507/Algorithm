#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
#pragma warning(disable:4996)
using namespace std;

vector<pair<int,int>> graph[1001];
bool visited[1001];
int N, M;
int dp[1001];
int dist[1001];

int getAnswer(int node)
{
	int& res = dp[node];

	if (dp[node] != -1)
		return dp[node];

	if (node == 1)
		return 1;
	res = 0;

	for (int i = 0;i < graph[node].size();i++)
	{
		if (dist[node] < dist[graph[node][i].first])
			res += getAnswer(graph[node][i].first);
	}

	return res;
}
int main(int argc, char** argv)
{
	cin >> N >> M;

	for (int i = 0;i < M;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	memset(dp, -1, sizeof(dp));
	memset(visited, false, sizeof(visited));
	fill(dist, dist+N+1,1e9);
	dist[2] = 0;
	queue<int> q;

	q.push(2);

	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		visited[a] = false;

		for (int i = 0;i < graph[a].size();i++)
		{
			int node = graph[a][i].first;
			int d = graph[a][i].second;
			if (dist[node] > dist[a] + d)
			{
				dist[node] = dist[a] + d;

				if (!visited[node]) {
					q.push(node);
					visited[node] = true;
				}
			}
		}
	}

	cout<<getAnswer(2);
	return 0;
}
