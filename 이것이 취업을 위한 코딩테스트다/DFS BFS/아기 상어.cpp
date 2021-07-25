#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>

using namespace std;

int space[21][21];
int visited[21][21];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int N;
int ans = 0;
class shark {
public:
	int x;
	int y;
	int size;
	int eat_count;
};

bool find(shark& s)
{
	queue<pair<int, int>> q;

	memset(visited, -1, sizeof(visited));

	q.push({ s.x,s.y });
	visited[s.x][s.y] = 0;

	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		if (space[a][b] != 0 && space[a][b] < s.size && space[a][b] != 9)
			continue;

		for (int i = 0;i < 4;i++)
		{
			int c = a + dx[i];
			int d = b + dy[i];

			if (c >= 0 && c < N && d >= 0 && d < N && visited[c][d] == -1 && space[c][d] <= s.size)
			{
				visited[c][d] = visited[a][b] + 1;
				q.push({ c,d });
			}
		}
	}

	int x = 100;
	int y = 100;
	int dist = 401;

	for (int i = N - 1;i >= 0;i--)
	{
		for (int j = N - 1;j >= 0;j--)
		{
			if (space[i][j] != 0 && space[i][j] != 9 && space[i][j] < s.size && visited[i][j] != -1 && visited[i][j] <= dist)
			{
				x = i;
				y = j;
				dist = visited[i][j];
			}
		}
	}

	if (dist == 401)
		return false;
	space[s.x][s.y] = 0;
	s.x = x;
	s.y = y;
	s.eat_count++;
	if (s.eat_count == s.size)
	{
		s.eat_count = 0;
		s.size++;
	}
	space[x][y] = 9;
	ans += dist;
	return true;
}
int main(void)
{
	cin >> N;

	shark s;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			cin >> space[i][j];

			if (space[i][j] == 9)
			{
				s.x = i;
				s.y = j;
				s.size = 2;
				s.eat_count = 0;
			}
		}
			
	}

	while (1)
	{
		if (find(s))
		{
			continue;
		}
		else
			break;
	}

	cout << ans << '\n';
	return 0;
}
