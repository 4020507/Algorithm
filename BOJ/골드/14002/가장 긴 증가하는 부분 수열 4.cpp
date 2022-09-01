#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#pragma warning(disable:4996)

#define INF 100000

using namespace std;

int N;
int dp[1000];
int nums[1000];
vector<int> v[1000];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	int i, j;

	for (i = 0; i < N; i++) {
		cin >> nums[i];
	}

	int ans = 1;
	int idx = 0;

	fill(dp, dp + N, 1);
	v[0].push_back(nums[0]);

	for (i = 1; i < N; i++) {

		for (j = 0; j < i; j++) {
			if (nums[j] < nums[i]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					v[i] = v[j];
				}
			}
		}

		if (ans < dp[i]) {
			ans = dp[i];
			idx = i;
		}

		v[i].push_back(nums[i]);
	}

	cout << ans << '\n';

	for (auto a : v[idx]) {
		cout << a << ' ';
	}

	return 0;
}
