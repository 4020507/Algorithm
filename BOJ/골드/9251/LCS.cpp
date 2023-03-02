#include<iostream>
#include<string>
#include<string.h>
#pragma warning(disable:4996)

using namespace std;

int dp[1002][1002];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s1, s2;

	cin >> s1 >> s2;

	memset(dp, 0, sizeof(dp));

	int i, j;

	for (i = 1; i <= s1.length(); i++) {
		for (j = 1; j <= s2.length(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = max(dp[i][j - 1], max(dp[i-1][j],dp[i - 1][j - 1] + 1));
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	cout << dp[s1.length()][s2.length()];


	return 0;
}
