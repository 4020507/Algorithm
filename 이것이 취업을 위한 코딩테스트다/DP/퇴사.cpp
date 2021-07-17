#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;


int main(void)
{
	int N;
	cin >> N;

	int day[15][2];
	int dp[15] = { 0, };
	for (int i = 0;i < N;i++)
	{
		cin >> day[i][0] >> day[i][1];
	}

	int maxi = 0;
	for (int i = N - 1;i >= 0;i--)
	{
		if (i + day[i][0] <= N)
		{
			dp[i] = max(dp[i + day[i][0]] + day[i][1], maxi);
			maxi = dp[i];
		}
		else
		{
			dp[i] = maxi;
		}
	}

	cout << maxi << endl;

	return 0;
}
