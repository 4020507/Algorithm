#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int map[16][16];
bool visited[16][16];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };


int bfs()
{
	queue<pair<int, int>> q;
	visited[1][1] = true;
	q.push(make_pair(1, 1));

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int c = a + dx[i];
			int d = b + dy[i];
			
			if (c >= 0 && c < 16 && d >= 0 && d < 16) {
				if (map[c][d] == 3) {
					return 1;
				}
				if (!visited[c][d] && map[c][d] == 0) {
					visited[c][d] = true;
					q.push(make_pair(c, d));
				}
			}
		}
	}
	return 0;
}

int main(void)
{
	int test_case;
	int t;

	for (test_case = 1;test_case <= 10;test_case++) {
		cin >> t;
		memset(visited, false, sizeof(visited));
		for (int i = 0;i < 16;i++) {
			for (int j = 0;j < 16;j++) {
				scanf("%1d", &map[i][j]);
			}
		}
		cout << "#" << test_case << " " << bfs() << endl;
	}
	return 0;
}
