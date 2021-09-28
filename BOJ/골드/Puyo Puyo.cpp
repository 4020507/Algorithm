#include<iostream>
#include<vector>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;

char map[12][6];
bool visited[12][6];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
//R,G,B,P,Y

vector<pair<int, int>> coordinates;

void dfs(int x, int y,char c)
{
	for (int i = 0;i < 4;i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < 12 && ny >= 0 && ny < 6)
		{
			if (!visited[nx][ny])
			{
				if (map[nx][ny] == c)
				{
					coordinates.push_back({ nx,ny });
					visited[nx][ny] = true;
					dfs(nx, ny, c);
				}
			}
		}
	}
}
int main(int argc, char** argv)
{
	for (int i = 0;i < 12;i++)
	{
		for (int j = 0;j < 6;j++)
			cin >> map[i][j];
	}
	int ans = 0;
	while (1)
	{
		memset(visited, false, sizeof(visited));

		bool check = false;
		for (int i = 0;i < 12;i++)
		{
			for (int j = 0;j < 6;j++)
			{
				if (map[i][j] != '.' && !visited[i][j])
				{
					coordinates.push_back({ i,j });
					visited[i][j] = true;
					dfs(i, j, map[i][j]);
					if (coordinates.size() > 3)
					{
						for (auto v : coordinates)
						{
							map[v.first][v.second] = 'c';
							check = true;
						}
					}
					coordinates.clear();
				}
			}
		}

		if (!check)
			break;
		ans++;

		int j = 0;

		while (j < 6)
		{
			int i = 11;
			int k = 11;
			char save[12];
			fill(save, save + 12, 'c');

			while (i >= 0)
			{
				if (map[i][j] != 'c')
				{
					save[k] = map[i][j];
					k--;
				}
				i--;
			}
			for (int i = 0;i < 12;i++)
			{
				if (save[i] != 'c')
					map[i][j] = save[i];
				else
					map[i][j] = '.';
			}
			j++;
		}
	}

	cout << ans;
	return 0;
}
