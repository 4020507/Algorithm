#include <iostream>
#include <cstring>
using namespace std;
int chocolate[51][51];
int dp[51][51][51][51];
int sum[51][51];

int solve(int a, int b, int c, int d)
{
	if (a == c && b == d)
		return 0;
	if (dp[a][b][c][d] != -1)
		return dp[a][b][c][d];

	int count = sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1];

	int maximum = 1000000000;

	for (int i = a;i < c;i++)
	{
		int temp = solve(a, b, i, d) + solve(i + 1, b, c, d);
		if (maximum > temp + count)
			maximum = temp + count;
	}

	for (int i = b;i < d;i++)
	{
		int temp = solve(a, b, c, i) + solve(a, i + 1, c, d);
		if (maximum > temp + count)
			maximum = temp + count;
	}

	return dp[a][b][c][d] = maximum;
}

int main(void)
{
	int T;
	cin >> T;

	int m;
	int n;

	for (int test_case = 1;test_case <= T;test_case++)
	{
		memset(dp, -1, sizeof(dp));
		cin >> n >> m;

		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				cin >> chocolate[i][j];

		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + chocolate[i][j];

		int answer = solve(1, 1, n, m);
		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}
