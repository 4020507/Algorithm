#include<iostream>
#include<vector>
#include<string.h>
#pragma warning(disable:4996)

using namespace std;

int dp[50001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int i, j, k, N;

	int v, cnt;
	vector<pair<int, int>> coins;
	int sum;

	for (int t = 0; t < 3; t++) {
		cin >> N;
		coins.clear();
		sum = 0;
		memset(dp, 0, sizeof(dp));

		for (i = 0; i < N; i++) {
			cin >> v >> cnt;

			coins.push_back({ v,cnt });

			sum += (v * cnt);
		}

		if (sum % 2 == 1) {
			cout << 0 << '\n';
			continue;
		}

		sum /= 2;

		dp[0] = 1;

		for (i = 0; i < N; i++) {
			for (j = 50000; j >= coins[i].first; j--) {
				if (dp[j - coins[i].first] == 1) {
					for (k = 0; k < coins[i].second && k * coins[i].first + j <= 50000; k++) {
						dp[j + k * coins[i].first] = 1;
					}
				}
			}
		}

		if (dp[sum]) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}

	return 0;
}
