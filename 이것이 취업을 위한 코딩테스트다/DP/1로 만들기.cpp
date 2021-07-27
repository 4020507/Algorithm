#pragma warning(disable:4996)
#include<iostream>

using namespace std;

int dp[30001];

int main(void)
{
	int N;
	cin >> N;

	dp[1] = 0;
	for (int i = 2;i <= N;i++)
	{
		dp[i] = dp[i - 1] + 1;

		if (i % 5 == 0)
			dp[i] = min(dp[i], dp[i / 5] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
	}
	
	cout << dp[N] << endl;
	return 0;
}
