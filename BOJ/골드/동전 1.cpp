#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
using namespace std;


int N;
int target;
int coins[100];
int dp[10001];
int main(void)
{
	
	cin >> N >> target;
	
	for (int i = 0;i < N;i++) {
		cin >> coins[i];
	}
	sort(coins, coins + N);
	dp[0] = 1;
	for (int i = 0;i < N;i++)
	{
		for (int j = coins[i];j <= target;j++)
		{
			dp[j] = dp[j] + dp[j - coins[i]];
		}
	}

	cout << dp[target];
	return 0;
}
