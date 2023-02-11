#include<iostream>
#include<queue>
#pragma warning(disable:4996)

using namespace std;

int cave[125][125];
int lost[125][125];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;

	cin >> N;

	int i, j;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	int x, y, nx, ny, lose, sum;
	int step = 1;
	queue<pair<int, pair<int,int>>> q;

	while (N != 0) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				cin >> cave[i][j];
				lost[i][j] = 1e9;
			}
		}

		q.push({ cave[0][0],{0,0}});
		lost[0][0] = cave[0][0];

		while (!q.empty()) {
			x = q.front().second.first;
			y = q.front().second.second;
			lose = q.front().first;
			q.pop();

			if (lost[x][y] < lose) {
				continue;
			}

			if (x == N - 1 && y == N - 1) {
				continue;
			}

			for (i = 0; i < 4; i++) {
				nx = x + dx[i];
				ny = y + dy[i];
				
				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					sum = lose + cave[nx][ny];

					if (sum < lost[nx][ny]) {
						lost[nx][ny] = sum;
						q.push({ sum,{nx,ny} });
					}
				}
			}
		}
		cout << "Problem " << step << ": " << lost[N - 1][N - 1] << '\n';
		step++;
		cin >> N;
	}
	

	return 0;
}
