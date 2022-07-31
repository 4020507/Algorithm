#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int N;
int points[51];
int friends[51][51];
int conn[51][51];
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	int a, b;
	a = b = 0;

	for (int i = 1; i <= N; i++) {
		fill(friends[i], friends[i] + N + 1, 1e9);
		friends[i][i] = 0;
	}
	while (1) {
		cin >> a >> b;

		if (a == -1 && b == -1) {
			break;
		}

		friends[a][b] = 1;
		friends[b][a] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				friends[i][j] = min(friends[i][j], friends[i][k] + friends[k][j]);
			}
		}
	}

	int val, mini;
	mini = 1e9;
	vector<int> v;
	for (int i = 1; i <= N; i++) {
		val = 0;
		for (int j = 1; j <= N; j++) {
			if (i != j)
				val = max(val, friends[i][j]);
		}

		if (mini > val) {
			mini = val;
			v.clear();
			v.push_back(i);
		}
		else if (mini == val) {
			v.push_back(i);
		}
	}

	cout << mini << ' ' << v.size() << '\n';

	for (auto i : v)
		cout << i << ' ';

	return 0;
}
