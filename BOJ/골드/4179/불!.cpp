#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#pragma warning(disable:4996)

using namespace std;

char maze[1000][1000];
int R, C;
pair<int, int>J;
int spread[1000][1000];
bool visited[1000][1000];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> R >> C;

	int i, j;

	queue<pair<int, int>> q;
	memset(spread, 0, sizeof(spread));
	memset(visited, false, sizeof(visited));

	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			cin >> maze[i][j];

			if (maze[i][j] == 'F') {
				q.push({ i,j });
			}
			else if (maze[i][j] == 'J') {
				J = { i,j };
				maze[i][j] = '.';
			}
		}
	}

	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };

	int x, y, nx, ny;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;

		q.pop();

		for (i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				if (spread[nx][ny] == 0 && maze[nx][ny] == '.') {
					spread[nx][ny] = spread[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}

	queue < pair<int, pair<int, int>>> q2;
	q2.push({ 0,{J.first,J.second} });
	visited[J.first][J.second] = true;

	int cnt;

	while (!q2.empty()) {
		cnt = q2.front().first;
		x = q2.front().second.first;
		y = q2.front().second.second;

		q2.pop();

		if (x == R - 1 || y == C - 1 || x == 0 || y == 0) {
			cout << cnt + 1;
			return 0;
		}
		for (i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				if (!visited[nx][ny] && maze[nx][ny] == '.' && (spread[nx][ny] > cnt + 1 || spread[nx][ny] == 0)) {
					q2.push({ cnt + 1,{nx,ny} });
					visited[nx][ny] = true;
				}
			}
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}
