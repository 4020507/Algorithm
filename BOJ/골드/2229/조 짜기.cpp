#include<iostream>
#include<string.h>
#include<algorithm>

#pragma warning(disable:4996)

#define INF 1e9

using namespace std;

int dp[1000][1000];
int N;
int num[1000];

int DP(int start, int end) {
	
	if (start == end)
		return 0;

	int& res = dp[start][end];

	if (res != -1) {
		return res;
	}

	res = num[start] >= num[end] ? num[start] - num[end] : num[end] - num[start];

	for (int i = start; i < end; i++) {
		res = max(res, DP(start, i) + DP(i + 1, end));
	}

	return res;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	memset(dp, -1, sizeof(dp));

	cout << DP(0, N - 1);

	return 0;
}
