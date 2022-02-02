#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

vector<int> tree[10001];
int population[10001];
int N;
int dp[10001][2];

int DP(int village, int good, int prev)
{
	if (dp[village][good] != -1)
		return dp[village][good];

	int& res = dp[village][good];
	res = 0;

	if (good == 0)
	{
		for (int i = 0;i < tree[village].size();i++)
		{
			int node = tree[village][i];

			if (prev == node)
				continue;
			res += max(DP(node, 0, village), DP(node, 1, village));
		}

		return res;
	}
	else
	{
		for (int i = 0;i < tree[village].size();i++)
		{
			int node = tree[village][i];

			if (prev == node)
				continue;

			res += DP(node, 0, village);
		}
		return res = res + population[village];
	}
}
int main(int argc, char** argv)
{
	cin >> N;

	for (int i = 1;i <= N;i++)
		cin >> population[i];

	for (int i = 0;i < N - 1;i++)
	{
		int a, b;
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	memset(dp, -1, sizeof(dp));
	
	cout << max(DP(1, 1, 0), DP(1, 0, 0));

	return 0;
}
