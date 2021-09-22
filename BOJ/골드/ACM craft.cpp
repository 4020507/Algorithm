#include<iostream>
#include<queue>
#include<string.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int N, K;
int buildings[1001];
int graph[1001][1001];
int indegree[1001];
int purpose;
int result[1001];
int main(int argc, char** argv)
{
	int T;
	cin >> T;

	for (int test_case = 1;test_case <= T;test_case++)
	{
		cin >> N >> K;
		memset(graph, 0, sizeof(graph));
		memset(indegree, 0, sizeof(indegree));
		memset(result, 0, sizeof(result));

		for (int i = 1;i <= N;i++)
			cin >> buildings[i];

		for (int i = 0;i < K;i++)
		{
			int a, b;
			cin >> a >> b;
			graph[a][b] = 1;
			indegree[b]++;
		}
		cin >> purpose;
		queue<int> q;

		for (int i = 1;i <= N;i++)
		{
			if (indegree[i] == 0) {
				q.push(i);
				result[i] = buildings[i];
			}
		}

		while (!q.empty())
		{
			int a = q.front();
			q.pop();

			for (int i = 1;i <= N;i++)
			{
				if (graph[a][i] == 1)
				{
					indegree[i]--;
					result[i] = max(result[i], result[a] + buildings[i]);
					if (indegree[i] == 0)
					{
						q.push(i);
					}
				}
			}
		}

		cout << result[purpose] << '\n';

	}
	
	return 0;
}
