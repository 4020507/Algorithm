#include<iostream>
#include<string.h>
#include<algorithm>

#pragma warning(disable:4996)

#define INF 1e9

using namespace std;


int N;
int RGB[1001][3];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
	}

	int ans = INF;

	for (int i = 0; i < 3; i++) {
		int dp[1001][3];

		for (int j = 0; j < 3; j++) {
			if (i != j) {
				dp[0][j] = INF;
			}
			else {
				dp[0][j] = RGB[0][j];
			}
		}

		for (int j = 1; j < N; j++) {
			dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + RGB[j][0];
			dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + RGB[j][1];
			dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + RGB[j][2];
		}

		for (int j = 0; j < 3; j++) {
			if (i != j) {
				ans = min(ans, dp[N - 1][j]);
			}
		}
	}


	cout << ans;

	return 0;
}
