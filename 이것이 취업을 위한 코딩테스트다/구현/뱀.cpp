#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;

int N, K, X;
int map[101][101];
vector<pair<int, char>> order;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int dir = 0;
void setDirection(char c)
{
	if (c == 'L')
	{
		if (dir != 0)
			dir--;
		else
			dir = 3;
	}
	else
	{
		dir = (dir + 1) % 4;
	}
}
int main(void)
{
	cin >> N >> K;
	
	memset(map, 0, sizeof(map));
	for (int i = 1;i <= K;i++)
	{
		int a, b;
		cin >> a >> b;

		map[a][b] = 1;
	}

	cin >> X;

	for (int i = 0;i < X;i++)
	{
		int a;
		char c;
		cin >> a >> c;

		order.push_back({ a,c });
	}

	queue<pair<int, int>> q;
	int x = 1;
	int y = 1;
	q.push({ x,y });
	
	int time = 0;
	int idx = 0;

	map[x][y] = 2;
	while (1)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		time++;

		if (nx > 0 && nx <= N && ny > 0 && ny <= N && map[nx][ny] != 2)
		{
			if (map[nx][ny] == 0)
			{				
				int a = q.front().first;
				int b = q.front().second;
				q.pop();
				map[a][b] = 0;
			}
			map[nx][ny] = 2;
			q.push({ nx,ny });
		}
		else
		{
			break;
		}
		x = nx;
		y = ny;

		if (idx < X && time == order[idx].first)
		{
			setDirection(order[idx].second);
			idx++;
		}

	}

	cout << time << '\n';
	return 0;
}
