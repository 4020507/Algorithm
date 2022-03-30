#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;

char cave[101][101];
bool visited[101][101];
bool visited2[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int R, C, N;
int stick;
vector<pair<int, int>> clusters;


void down() {
	memset(visited2, false, sizeof(visited2));
	int x, y;
	for (int i = 0;i < clusters.size();i++) {
		x = clusters[i].first;
		y = clusters[i].second;

		if (x == R)
			return;

		cave[x][y] = '.';
		visited[x][y] = false;
	}

	for (int i = 0;i < clusters.size();i++) {
		x = clusters[i].first;
		y = clusters[i].second;

		cave[x + 1][y] = 'x';
		visited[x + 1][y] = true;
		visited2[x + 1][y] = true;
		clusters[i].first++;
	}

	for (int i = 0;i < clusters.size();i++) {
		x = clusters[i].first;
		y = clusters[i].second;

		if (x == R)
			return;
		if (cave[x + 1][y] == 'x' && !visited2[x + 1][y])
			return;
	}

	down();
}

void makeCluster(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	clusters.push_back({ x,y });

	int nx, ny;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++) {
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx >= 1 && nx <= R && ny >= 1 && ny <= C) {
				if (cave[nx][ny] == 'x' && !visited[nx][ny]) {
					q.push({ nx,ny });
					visited[nx][ny] = true;
					clusters.push_back({ nx,ny });
				}
			}
		}
	}
}
void findCluster() {
	for (int i = R;i >= 1;i--) {
		for (int j = 1;j <= C;j++) {
			if (cave[i][j] == 'x' && !visited[i][j]) {
				visited[i][j] = true;
				clusters.clear();
				makeCluster(i, j);
				down();
			}
		}
	}
}
bool throwLeft(int height) {
	for(int i = 1;i<=C;i++)
		if (cave[height][i] == 'x') {
			cave[height][i] = '.';
			return true;
		}
	return false;
}

bool throwRight(int height) {
	for (int i = C;i >= 1;i--) {
		if (cave[height][i] == 'x') {
			cave[height][i] = '.';
			return true;
		}
	}

	return false;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin >> R >> C;

	for (int i = 1;i <= R;i++)
		for (int j = 1;j <= C;j++)
			cin >> cave[i][j];

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> stick;
		stick = R - stick + 1;
		if (i % 2 == 0) {
			if (throwLeft(stick)) {
				memset(visited, false, sizeof(visited));
				findCluster();
			}
		}
		else {
			if (throwRight(stick)) {
				memset(visited, false, sizeof(visited));
				findCluster();
			}
		}
	}

	for (int i = 1;i <= R;i++) {
		for (int j = 1;j <= C;j++)
			cout << cave[i][j];
		cout << '\n';
	}
	return 0;
}
