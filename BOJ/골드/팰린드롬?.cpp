#include<iostream>

#pragma warning(disable:4996)
using namespace std;
int N, M;
int nums[2001];
bool dp[2001][2001];

int main(int argc, char** argv)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 1;i <= N;i++) {
		cin >> nums[i];
		dp[i][i] = true;
	}

	for (int i = 1;i <= N - 1;i++)
	{
		if (nums[i] == nums[i + 1])
			dp[i][i + 1] = true;
	}

	for (int i = N - 2;i >= 1;i--)
	{
		for (int j = i + 2;j <= N;j++)
		{
			if (nums[i] == nums[j] && dp[i + 1][j - 1])
				dp[i][j] = true;
		}
	}
	cin >> M;

	int a, b;
	for (int i = 0;i < M;i++)
	{
		cin >> a >> b;

		cout << dp[a][b] << '\n';
	}
	return 0;
}
