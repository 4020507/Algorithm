#pragma warning(disable:4996)
#include<iostream>

using namespace std;

int dp[1001];

int main(void) 
{
	int n;
	cin >> n;
	
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3;i <= n;i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] * 2)%796796;
	}

	cout << dp[n] << endl;
	return 0;
}
