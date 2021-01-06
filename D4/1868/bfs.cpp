#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char map[300][300];
bool visited[300][300];
int dx[8] = { 1,1,1,-1,-1,-1,0,0};
int dy[8] = {1,-1,0,1,-1,0,1,-1};

bool non_dot(int c, int d, int N)
{
	for (int i = 0; i < 8; i++) {
		int nx = c + dx[i];
		int ny = d + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < N) {
			if (map[nx][ny] == '*') {
				return false;
			}
		}
	}
	return true;
}

int bfs(int N)
{
	
	int count = 0;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (!visited[i][j] && map[i][j] == '.' && non_dot(i,j,N)) {
				queue<pair<int, int>> q;
				count++;
				q.push(make_pair(i, j));
				
				while (!q.empty())
				{
					int a = q.front().first;
					int b = q.front().second;
					q.pop();
					visited[a][b] = true;
					for (int i = 0;i < 8;i++)
					{
						int c = a + dx[i];
						int d = b + dy[i];

						if (c >= 0 && c < N && d >= 0 && d < N) {
							if (map[c][d] == '.' && !visited[c][d]) {
								if(non_dot(c,d,N))
									q.push(make_pair(c, d));
								visited[c][d] = true;
							}
						}
					}
				}
			}
		}
	}

	
	return count;
}
int main(void)
{
	int T;
	int N;
	cin >> T;

	for (int test_case = 1;test_case <= T;test_case++) {
		memset(visited, false, sizeof(visited));
		cin >> N;

		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				scanf(" %c", &map[i][j]);
			}
		}
		int count = bfs(N);

		for (int i = 0;i < N;i++)
			for (int j = 0;j < N;j++)
				if (!visited[i][j] && map[i][j] == '.')
					count++;
		cout << "#" << test_case << " " << count << endl;

	}
}
