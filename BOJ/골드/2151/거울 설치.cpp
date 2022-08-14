#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#pragma warning(disable:4996)

#define INF 1e9

using namespace std;

int N;
char home[50][50];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int visited[50][50][4];
int cnt;
pair<int, int> start;
void bfs() {

	queue < pair<pair<int, int>, pair<int,int>>>q;

	for (int i = 0; i < 4; i++) {
		q.push({ {start.first,start.second},{0,i} });
		visited[start.first][start.second][i] = 0;
	}

	int x, y, nx, ny, mirrors, dir;

	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		mirrors = q.front().second.first;
		dir = q.front().second.second;

		q.pop();

		if (mirrors >= cnt)
			continue;

		if (home[x][y] == '#' && (x != start.first || y != start.second)) {
			cnt = min(cnt, mirrors);
			continue;
		}

		if (home[x][y] == '.' || home[x][y] == '#') {
			nx = x + dx[dir];
			ny = y + dy[dir];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (visited[nx][ny][dir] > mirrors && home[nx][ny] != '*') {
					visited[nx][ny][dir] = mirrors;
					q.push({ {nx,ny},{mirrors,dir} });
				}
			}
		}
		else if (home[x][y] == '!') {
			for (int i = 0; i < 4; i++) {
				nx = x + dx[i];
				ny = y + dy[i];

				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					if (visited[nx][ny][i] > mirrors && home[nx][ny] != '*') {

						if (i != dir) {
							q.push({ { nx,ny }, { mirrors + 1,i } });
							visited[nx][ny][i] = mirrors + 1;
						}
						else {
							visited[nx][ny][i] = mirrors;
							q.push({{ nx,ny }, { mirrors,dir }});
						}
					}
				}
			}
		}

	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> home[i][j];

			if (home[i][j] == '#') {
				start.first = i;
				start.second = j;
			}

			for (int k = 0; k < 4; k++) {
				visited[i][j][k] = INF;
			}
		}
	}

	cnt = INF;

	bfs();

	cout << cnt;

	return 0;
}
