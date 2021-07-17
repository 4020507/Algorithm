#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int triangle[500][500];
int dp[500][500];

int main(void)
{
	int N;
	cin >> N;

	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j <= i;j++)
		{
			cin >> triangle[i][j];
		}
	}

	
	memset(dp, 0, sizeof(dp));

	dp[0][0] = triangle[0][0];

	for (int i = 1;i < N;i++)
	{
		for (int j = 0;j <= i;j++)
		{
			dp[i][j] = max(triangle[i][j] + dp[i - 1][j - 1], max(triangle[i][j] + dp[i - 1][j], dp[i][j]));
		}
	}

	int ans = 0;

	for (int i = 0;i < N;i++)
	{
		ans = max(dp[N - 1][i], ans);
	}

	cout << ans << endl;

	return 0;
}
