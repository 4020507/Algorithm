#include<iostream>

#pragma warning(disable:4996)

using namespace std;


int nums[50];
int cnt[50];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	double line;

	cin >> N;

	int i, j;

	for (i = 0; i < N; i++) {
		cin >> nums[i];
		cnt[i] = 0;
	}

	double maxi;

	for (i = 0; i < N; i++) {
		maxi = -9999999999;

		for (j = i + 1; j < N; j++) {
			line = (double) (nums[i] - nums[j]) / (i - j);

			if (maxi < line) {
				maxi = line;
				cnt[i]++;
				cnt[j]++;
			}
		}
	}

	int ans = 0;

	for (i = 0; i < N; i++) {
		ans = max(ans, cnt[i]);
	}

	cout << ans;

	return 0;
}
