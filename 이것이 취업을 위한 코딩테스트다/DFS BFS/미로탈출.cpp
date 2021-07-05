#pragma warning(disable:4996)
#include<iostream>
#include<queue>
#include<string.h>
#include<stdio.h>
using namespace std;


int N, M;
int shape[1000][1000];
bool visited[1000][1000];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int bfs()
{
	queue<pair<int, pair<int,int>>> q;
	q.push(make_pair(0, make_pair(0,1)));
	visited[0][0] = true;
	int count = 0;
	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second.first;
		int step = q.front().second.second;
		
		
		if (a == N - 1 && b == M - 1)
		{
			return step;
		}
		q.pop();
		for (int i = 0;i < 4;i++)
		{
			int c = a + dx[i];
			int d = b + dy[i];

			if (c >= 0 && c < N && d >= 0 && d < M)
			{
				if (!visited[c][d] && shape[c][d] == 1)
				{
					visited[c][d] = true;
					q.push(make_pair(c, make_pair(d,step+1)));
				}
			}
		}
	}

	return -1;
}
int main(void)
{
	cin >> N >> M;

	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			int c;
			scanf("%1d", &c);
			shape[i][j] = c;
		}
	}

	memset(visited, false, sizeof(visited));

	cout << bfs() << endl;
	return 0;
}
