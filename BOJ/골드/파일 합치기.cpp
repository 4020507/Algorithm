#include<iostream>
#include<string.h>
#include<algorithm>

#pragma warning(disable:4996)
using namespace std;
int N;
int nums[501];
int dp[501][501];
int sum[501];
int calc(int start, int end)
{
	if (dp[start][end] != 1e9)
		return dp[start][end];
	if (start + 1 == end)
		return dp[start][end] = nums[start] + nums[end];
	if (start == end)
		return dp[start][end] = 0;
	for (int i = start;i < end;i++)
	{
		dp[start][end] = min(dp[start][end], calc(start, i) + calc(i + 1, end));
	}

	return dp[start][end] += sum[end] - sum[start - 1];
}
int main(int argc, char** argv)
{
	int T;
	cin >> T;

	for (int test_case = 0;test_case < T;test_case++)
	{
		cin >> N;

		for (int i = 1;i <= N;i++) {
			cin >> nums[i];
			sum[i] = sum[i - 1] + nums[i];
		}

		for(int i = 0;i<=N;i++)
			fill(dp[i], dp[i] + N + 1, 1e9);
		cout << calc(1, N) << '\n';

	}
	return 0;
}
