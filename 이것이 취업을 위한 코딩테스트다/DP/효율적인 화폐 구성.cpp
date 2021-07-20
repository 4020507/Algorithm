#pragma warning(disable:4996)
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;

	int coin[101];
	int dp[10001];

	fill(dp, dp + 10001, 10001);

	for (int i = 0;i < N;i++) {
		cin >> coin[i];
		dp[coin[i]] = 1;
	}
	sort(coin, coin + N);

	for (int i = coin[0] + 1;i <= M;i++)
	{
		for (int j = 1;j < i;j++)
		{
			if(dp[j] != 10001 && dp[i-j] != 10001)
				dp[i] = min(dp[i], dp[j] + dp[i - j]);
		}

	}
	
	if (dp[M] == 10001)
		cout << -1 << endl;
	else
		cout << dp[M] << endl;
	return 0;
}
