#include<iostream>
#include<string.h>
#include<queue>
#pragma warning(disable:4996)
using namespace std;

int M, N;
char map[50][50];
bool visited[50][50][1<<6];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int bfs(int x, int y)
{
	memset(visited, false, sizeof(visited));
	queue<pair<pair<int,int>,pair<int,int>>> q;

	q.push({ { x,y }, { 0,0 } });
	visited[x][y][0] = true;
	while (!q.empty())
	{
		int a = q.front().first.first;
		int b = q.front().first.second;
		int key = q.front().second.first;
		int count = q.front().second.second;

		q.pop();
		if (map[a][b] == '1')
			return count;

		for (int i = 0;i < 4;i++)
		{
			int c = a + dx[i];
			int d = b + dy[i];

			if (c >= 0 && c < M && d >= 0 && d < N)
			{
				if (!visited[c][d][key] && map[c][d] != '#')
				{
					if (map[c][d] == '0' || map[c][d] == '.' || map[c][d] == '1')
					{
						q.push({ { c,d }, { key,count + 1 } });
						visited[c][d][key] = true;
					}
					else if (map[c][d] >= 'A' && map[c][d] <= 'F')
					{
						if (key & (1 << ((int)map[c][d] - 65)))
						{
							q.push({ {c,d},{key,count + 1} });
							visited[c][d][key] = true;
						}
					}
					else if (map[c][d] >= 'a' && map[c][d] <= 'f')
					{
						int temp = key | (1 << ((int)map[c][d] - 97));

						if (!visited[c][d][temp])
						{
							q.push({ { c,d }, { temp,count+1 } });
							visited[c][d][temp] = true;
						}
					}
				}
			}
		}
	}

	return -1;
}
int main(int argc, char** argv)
{
	cin >> M >> N;

	int x, y;

	for (int i = 0;i < M;i++)
	{
		for (int j = 0;j < N;j++) {
			cin >> map[i][j];

			if (map[i][j] == '0')
			{
				x = i;
				y = j;
			}
		}
	}

	cout << bfs(x, y);


	return 0;
}
