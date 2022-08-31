#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#pragma warning(disable:4996)

#define INF 100000

using namespace std;

vector<pair<int, int>> v;
int N;
int dp[101];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	int a, b;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;

		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());
	fill(dp, dp + N, 1);

	int ans = 0;

	for (int i = 1; i < N; i++) {

		for (int j = 0; j < i; j++) {

			if (v[i].second > v[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		ans = max(ans, dp[i]);
	}

	cout << N - ans;

	return 0;
}
