#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int dx[4] = { 1,0,-1,0};
int dy[4] = { 0,-1,0,1 };
int map[100][100];
bool visited[100][100];
int dp[100][100];

void bfs(int num)
{
	visited[0][0] = true;//start at [0][0]

	queue <pair< int, int >> q;
	q.push(make_pair(0, 0));

	while(!q.empty()){
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int i = 0;i < 4;i++) {
			int c = a + dx[i];
			int d = b + dy[i];
			if (c >= 0 && c < num && d >= 0 && d < num) {//two values, c and d should be less than num
				if (!visited[c][d] || dp[c][d] > map[c][d] + dp[a][b]) {//case if the route is new or the new way is shorter
					visited[c][d] = true;
					dp[c][d] = map[c][d] + dp[a][b];
					q.push(make_pair(c, d));
				}
			}
		}

	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int num;

	cin >> T;//input the number how many times you want to test
	

	for (test_case = 1;test_case <= T;++test_case) {
		memset(dp, 0, sizeof(dp));
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));

		cin >> num;//size of map

		for (int i = 0;i < num;i++)
			for (int j = 0;j < num;j++)
				scanf("%1d", &map[i][j]);//accept one number
		bfs(num);
		cout << "#" << test_case << " " << dp[num-1][num-1] << endl;
	}

	return 0;
}
