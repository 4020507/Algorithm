#include<iostream>
#include<queue>
#include<string.h>
#include<string>
#include<vector>
#include<set>
#pragma warning(disable:4996)

#define INF 1e9

using namespace std;

int N, M;
char map[1000][1000];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int moved[1000][1000];
int visited[1000][1000];

void bfs(int x, int y, int num) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> wall;

	q.push({ x,y });
	visited[x][y] = num;

	int nx, ny, i;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		wall.push_back({ x,y });
		q.pop();

		for (i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (visited[nx][ny]  == -1 && map[nx][ny] == '0') {
					visited[nx][ny] = num;
					q.push({ nx,ny });
				}
			}
		}
	}

	int cnt = wall.size();

	for (auto w : wall) {
		moved[w.first][w.second] = cnt;
	}
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	string s;
	int i, j, k;

	for (i = 0; i < N; i++) {
		cin >> s;

		for (j = 0; j < M; j++) {
			map[i][j] = s[j];
		}
	}

	memset(moved, 0, sizeof(moved));
	memset(visited, -1, sizeof(visited));

	int num = 1;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (visited[i][j] == -1 && map[i][j] == '0') {
				bfs(i, j, num);
				num++;
			}
		}
	}

	int nx, ny;
	int total;
	set<int> duplicate;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (map[i][j] == '1') {
				total = 0;
				duplicate.clear();
				for (k = 0; k < 4; k++) {
					nx = i + dx[k];
					ny = j + dy[k];

					if (nx >= 0 && nx < N && ny >= 0 && ny < M) {

						if (duplicate.find(visited[nx][ny]) == duplicate.end()) {
							total += moved[nx][ny];
							duplicate.insert(visited[nx][ny]);
						}
						
					}
				}

				map[i][j] = ((total + 1) % 10) + '0';
			}
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cout << map[i][j];
		}

		cout << '\n';
	}
	return 0;
}
