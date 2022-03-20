#include<iostream>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;

int N, M, H;
int ladder[31][11];
int changed;

bool down()
{
	int i;
	for (int y = 1;y <= N;y++)
	{
		i = y;
		for (int x = 1;x <= H;x++)
		{
			if (ladder[x][i] == 1) i++;
			else if (ladder[x][i - 1] == 1)i--;
		}

		if (i != y)
			return false;
	}

	return true;
}

void dfs(int x, int y, int cnt)
{
	if (changed <= cnt)
		return;
	if (down())
	{
		changed = cnt;
		return;
	}

	if (cnt == 3) return;

	for (int i = x;i <= H;i++)
	{
		for (int j = y;j <= N;j++)
		{
			if (ladder[i][j] == 0 && ladder[i][j - 1] == 0 && ladder[i][j + 1] == 0) {
				ladder[i][j] = 1;
				dfs(i, j, cnt + 1);
				ladder[i][j] = 0;
			}
		}
		y = 1;
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin >> N >> M >> H;

	memset(ladder, 0, sizeof(ladder));
	changed = 4;

	int x, y;
	for (int i = 0;i < M;i++)
	{
		cin >> x >> y;
		ladder[x][y] = 1;
	}

	dfs(1, 1, 0);

	if (changed == 4)
		cout << -1;
	else
		cout << changed;
	return 0;
}
