#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>
#pragma warning(disable:4996)

#define INF 1e9

using namespace std;

int p[1001];
int n[1001];
int dp[10001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T, K;

	cin >> T >> K;

	for (int i = 0; i < K; i++) {
		cin >> p[i] >> n[i];
	}

	dp[0] = 1;
	for (int i = 0; i < K; i++) {
		for (int j = T; j >= 0; j--) {
			for (int k = 1; k <= n[i] && j - k * p[i] >= 0; k++) {
				dp[j] += dp[j - k * p[i]];
			}
		}
	}

	cout << dp[T];

	return 0;
}
