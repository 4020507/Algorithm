#include<iostream>
#include<string.h>
#include<algorithm>

#pragma warning(disable:4996)

#define INF 1e9

using namespace std;

int N;
int visited;
int W[16][16];
int dp[16][1 << 16];

int DP(int visited, int city) {

	int& res = dp[city][visited];

	if (res != -1) {
		return res;
	}

	if (visited == (1 << N) - 1) {

		if (W[city][0] != 0) {
			return W[city][0];
		}
		else {
			return INF;
		}
	}

	res = INF;

	for (int i = 0; i < N; i++) {

		if (W[city][i] == 0 || (visited & (1 << i))) {
			continue;
		}

		res = min(res, DP(visited | (1 << i),i) + W[city][i]);
	}

	return res;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << DP(1, 0);


	return 0;
}
