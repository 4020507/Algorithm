#pragma warning(disable:4996)
#include<iostream>

using namespace std;



int main(void)
{
	int N;

	cin >> N;

	int store[101];

	for (int i = 0;i < N;i++)
		cin >> store[i];

	int dp[101] = { 0, };
	dp[0] = store[0];
	dp[1] = max(store[0],store[1]);

	for (int i = 2;i < N;i++)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + store[i]);
	}

	cout << dp[N - 1] << endl;

	return 0;
}
