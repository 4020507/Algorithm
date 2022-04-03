#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;


int arr[102][102];
int i, j, k, idx, SIZE;
int row, col;
vector<pair<int, int>> v;
int cnt[101];

void R() {
	
	for (i = 1;i <= row;i++) {
		v.clear();
		memset(cnt, 0, sizeof(cnt));

		for (j = 1;j <= col;j++) {
			if (arr[i][j] != 0) {
				cnt[arr[i][j]]++;
			}
		}

		for (idx = 1;idx <= 100;idx++) {
			if (cnt[idx] != 0) {
				v.push_back({ cnt[idx],idx });
			}
		}
		sort(v.begin(), v.end());
		idx = 1;
		
		for (auto a : v) {
			if (idx >= 100)
				break;
			arr[i][idx++] = a.second;
			arr[i][idx++] = a.first;
		}
		idx--;
		col = col > idx ? col : idx;
		idx++;
		for (;idx <= 100;idx++)
			arr[i][idx] = 0;
	}
}

void L() {

	for (j = 1;j <= col;j++) {
		v.clear();
		memset(cnt, 0, sizeof(cnt));

		for (i = 1;i <= row;i++) {
			if (arr[i][j] != 0) {
				cnt[arr[i][j]]++;
			}
		}

		for (idx = 1;idx <= 100;idx++) {
			if (cnt[idx] != 0) {
				v.push_back({ cnt[idx],idx });
			}
		}
		sort(v.begin(), v.end());
		idx = 1;

		for (auto a : v) {
			if (idx >= 100)
				break;
			arr[idx++][j] = a.second;
			arr[idx++][j] = a.first;
		}
		idx--;
		row = row < idx ? idx : row;
		idx++;
		for (idx;idx <= 100;idx++)
			arr[idx][j] = 0;
	}
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int r, c, k;

	cin >> r >> c >> k;

	row = col = 3;
	memset(arr, 0, sizeof(arr));
	for (i = 1;i <= 3;i++) {
		for (j = 1;j <= 3;j++) {
			cin >> arr[i][j];
		}
	}

	for (int seconds = 0;seconds <= 100;seconds++) {
		if (arr[r][c] == k) {
			cout << seconds;
			return 0;
		}

		if (row >= col)
			R();
		else
			L();
	}

	cout << -1;
	return 0;
}
