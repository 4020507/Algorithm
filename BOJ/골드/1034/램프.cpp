#include<iostream>
#include<string>
#pragma warning(disable:4996)
using namespace std;

int N, M;
string lamp[50];
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> lamp[i];
	}
	int K;

	cin >> K;

	int zeroes;
	int ans = 0;
	int sum;
	for (int i = 0; i < N; i++) {
		zeroes = 0;

		for (int j = 0; j < M; j++) {
			if (lamp[i][j] == '0') {
				zeroes++;
			}
		}

		if (zeroes <= K && K % 2 == zeroes % 2) {
			sum = 0;
			for (int j = 0; j < N; j++) {
				if (lamp[i] == lamp[j]) {
					sum++;
				}
			}
			ans = max(ans, sum);
		}
	}

	cout << ans;

	return 0;
}
