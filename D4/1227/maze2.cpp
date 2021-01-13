#include<iostream>
#include<stack>
#include<cstring>

using namespace std;
/*
there is a 100x100 map
2 is an departure coordinate, and 3 is an arrival coordinate
You can't go to a place that is 1, instead, you can go '0'
If the maze can reach at the arrival coordinate, return 1, not return 0

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14wL9KAGkCFAYD
*/
int map[100][100];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
bool visited[100][100];

int dfs(int i, int j)
{
	stack<pair<int, int>> s;
	s.push(make_pair(i, j));
	visited[i][j] = true;

	while (!s.empty())
	{
		int a = s.top().first;
		int b = s.top().second;
		s.pop();
		for (int k = 0;k < 4;k++)
		{
			int c = a + dx[k];
			int d = b + dy[k];

			if (c >= 0 && c < 100 && d >= 0 && d < 100) {
				if (map[c][d] == 3)
					return 1;
				if (!visited[c][d] && map[c][d] == 0) {
					visited[c][d] = true;
					s.push(make_pair(c, d));
				}
			}
		}
	}
	return 0;
}
int main(void)
{
	int T;

	for (int test_case = 1;test_case <= 10;test_case++)
	{
		cin >> T;
		int start_i;
		int start_j;
		memset(visited, false, sizeof(visited));
		for (int i = 0;i < 100;i++)
			for (int j = 0;j < 100;j++) {
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 2) {//save the starting point
					start_i = i;
					start_j = j;
				}
			}

		cout << "#" << test_case << " " << dfs(start_i,start_j) << endl;
	}
}
