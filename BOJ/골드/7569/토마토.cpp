#include<iostream>
#include<queue>

#pragma warning(disable:4996)

using namespace std;

int box[100][100][100];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int dh[2] = { -1,1 };
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M, H;

	cin >> M >> N >> H;

	int i, j, k;
	queue < pair<pair<int,int>, pair<int, int>>> q;

	for (i = 0; i < H; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < M; k++) {
				cin >> box[i][j][k];

				if (box[i][j][k] == 1) {
					q.push({ {0,i},{j,k}});
				}
			}
		}
	}

	int x, y, h, t;
	int z, w;
	int ans = 0;

	while (!q.empty()) {
		t = q.front().first.first;
		i = q.front().first.second;
		j = q.front().second.first;
		k = q.front().second.second;

		q.pop();

		ans = max(t, ans);

		for (z = 0; z < 2; z++) {
			h = i + dh[z];

			if (h >= 0 && h < H) {
				if (box[h][j][k] == 0) {
					q.push({ {t + 1,h},{j,k} });
					box[h][j][k] = 1;
				}
			}
		}

		for (w = 0; w < 4; w++) {
			x = j + dx[w];
			y = k + dy[w];

			if (x >= 0 && x < N && y >= 0 && y < M && box[i][x][y] == 0) {
				q.push({ {t + 1,i},{x,y} });
				box[i][x][y] = 1;
			}
		}
	}

	for (i = 0; i < H; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < M; k++) {
				if (box[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << ans;

	return 0;
}
