#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;

int city[101][101];

int main(void)
{
	cin >> n >> m;

	for (int i = 0;i < 101;i++)
	{
		for (int j = 0;j < 101;j++)
		{
			if (i != j)
				city[i][j] = 1e9;
			else
				city[i][j] = 0;
		}
	}
	for (int i = 0;i < m;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (c < city[a][b])
		{
			city[a][b] = c;
		}
	}

	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			for (int k = 1;k <= n;k++)
				city[j][k] = min(city[j][k], city[j][i] + city[i][k]);
		}
	}

	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			if (city[i][j] == 1e9)
				cout << 0 << ' ';
			else
				cout << city[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
