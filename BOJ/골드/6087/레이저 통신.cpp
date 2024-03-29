#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string.h>
#pragma warning(disable:4996)

#define INF 1e9

using namespace std;

char map[100][100];
int W, H;
int dist[100][100][4];
int startX, startY, endX, endY;

int dx[4] = { 0 ,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


void bfs() {

	queue<pair<pair<int, int>, pair<int, int>>> q;

	//x,y,mirror,dir
	int i;

	for (int i = 0; i < 4; i++) {
		q.push({ { startX,startY }, { 0,i } });
		dist[startX][startY][i] = 0;
	}

	int x, y, mirrors, dir;
	int nx, ny;

	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		mirrors = q.front().second.first;
		dir = q.front().second.second;

		q.pop();

		if (x == endX && y == endY)
			continue;

		for (i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
				if (map[nx][ny] != '*') {

					if (i != dir) {
						if (dist[nx][ny][i] > mirrors + 1) {
							dist[nx][ny][i] = mirrors + 1;
							q.push({ {nx,ny},{dist[nx][ny][i],i}});
						}
					}
					else {
						if (dist[nx][ny][i] > mirrors) {
							dist[nx][ny][i] = mirrors;
							q.push({ {nx,ny},{dist[nx][ny][i],i}});
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

	cin >> W >> H;

	int cnt = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'C' && cnt == 0) {
				startX = i;
				startY = j;
				cnt++;
			}
			else if (map[i][j] == 'C' && cnt == 1) {
				endX = i;
				endY = j;
			}

			dist[i][j][0] = INF;
			dist[i][j][1] = INF;
			dist[i][j][2] = INF;
			dist[i][j][3] = INF;
		}
	}


	bfs();

	cout << min(dist[endX][endY][0],min(dist[endX][endY][1],min(dist[endX][endY][2],dist[endX][endY][3])));

	return 0;
}
