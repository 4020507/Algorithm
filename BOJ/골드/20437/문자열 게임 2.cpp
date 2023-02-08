#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#pragma warning(disable:4996)

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T, K, i, j;
	string W;
	vector<int> alphabet[26];
	int shortest, longest;

	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> W;
		cin >> K;
		shortest = 1e9;
		longest = 0;

		for (i = 0; i < 26; i++) {
			alphabet[i].clear();
		}

		for (i = 0; i < W.length(); i++) {
			alphabet[W[i] - 'a'].push_back(i);
		}

		for (i = 0; i < 26; i++) {
			if (alphabet[i].size() >= K) {
				for (j = 0; j <= alphabet[i].size() - K; j++) {
					shortest = min(shortest, alphabet[i][j + K - 1] - alphabet[i][j] + 1);
					longest = max(longest, alphabet[i][j + K - 1] - alphabet[i][j] + 1);
				}
			}
		}

		if (shortest != 1e9 && longest != 0) {
			cout << shortest << ' ' << longest << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}

	return 0;
}
