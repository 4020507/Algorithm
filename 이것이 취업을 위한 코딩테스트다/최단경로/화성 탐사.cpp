#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int map[126][126];
int N;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int find(int x, int y)
{
	int visited[126][126];
	
	for (int i = 0;i < N;i++)
		fill(visited[i], visited[i] + N, 1e9);

	priority_queue < pair<int,pair<int, int>>> pq;
	pq.push({ -map[x][y],{x,y} });
	visited[x][y] = map[x][y];
	int result = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		x = pq.top().second.first;
		y = pq.top().second.second;

		pq.pop();
		if (x == N - 1 && y == N - 1)
		{
			result = cost;
			break;
		}
		if (visited[x][y] < cost)
			continue;

		for (int i = 0;i < 4;i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			{
				int c = cost + map[nx][ny];

				if (visited[nx][ny] > c)
				{
					visited[nx][ny] = c;
					pq.push({ -c,{nx,ny} });
				}
			}
		}
	}

	return result;
}
int main(void)
{
	int T;
	cin >> T;

	for (int test_case = 1;test_case <= T;test_case++)
	{
		cin >> N;

		for (int i = 0;i < N;i++)
		{
			for (int j = 0;j < N;j++)
				cin >> map[i][j];
		}
		cout << find(0, 0) << endl;
	}

	

	return 0;
}
