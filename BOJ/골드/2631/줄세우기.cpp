#include<iostream>

#pragma warning(disable:4996)

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int childeren[201];
	int dp[201];
	int N;

	cin >> N;

	int i, j;

	for (i = 0; i < N; i++) {
		cin >> childeren[i];
		dp[i] = 1;
	}

	int ans = 1;

	for (i = 0; i < N; i++) {
		for (j = i - 1; j >= 0; j--) {
			if (childeren[i] > childeren[j] && dp[i] <= dp[j]) {
				dp[i] = dp[j] + 1;
			}
		}

		ans = max(ans, dp[i]);
	}

	cout << N - ans;

	return 0;
}
