#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int indegree[501];
int graph[501][501];

int main(void)
{
	int N, M;
	cin >> N >> M;

	for (int i = 0;i <= N;i++)
		fill(graph[i], graph[i] + (N + 1), 1e9);

	for (int i = 1;i <= N;i++)
		graph[i][i] = 0;

	for (int i = 0;i < M;i++)
	{
		int a, b;
		cin >> a >> b;

		graph[a][b] = 1;
	}

	for (int k = 1;k <= N;k++)
	{
		for (int i = 1;i <= N;i++)
		{
			for (int j = 1;j <= N;j++)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	int count = 0;
	for (int i = 1;i <= N;i++)
	{
		bool possible = true;
		for (int j = 1;j <= N;j++)
		{
			if (graph[i][j] == 1e9 && graph[j][i] == 1e9)
			{
				possible = false;
				break;
			}
		}

		if (possible)
			count++;
	}

	cout << count << endl;

	return 0;
}
