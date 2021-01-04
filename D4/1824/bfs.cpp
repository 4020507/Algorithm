#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

/*
T: number of cases you want to test
R: row
C: column
map: input any characters which could be <,>,v,^,_,|,@,+,-,.
<,>,v,^ are nothing but directions which are left, right, down and up
_ check memory if it is 0, goes right, if not left
| check memory if it is 0, goes down if not up
?, you can go any direction
., do nothing
@ stop the program
0~9 -> becomes memory number
+,- -> add or subtract memory by one, if it is larger than 15, becomes 0, if it is smaller than 0, becomes 15

if you are at the rightmost place, but need to go right, go to the leftmost, vice versa
This rule applies for up and down as well

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4yLUiKDUoDFAUx&categoryId=AV4yLUiKDUoDFAUx&categoryType=CODE
*/

bool visited[21][21][4][16];//x,y,direction,memory
int dx[4] = { 0,0,1,-1};//down, up, left, right
int dy[4] = { 1,-1,0,0};
char map[21][21];

string bfs(int R, int C)
{
	visited[0][0][0][0] = true;

	queue < pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;

		if (map[x][y] == '@')
			return "YES";
		int direction = q.front().second.first;
		int memory = q.front().second.second;

		q.pop();

		switch (map[x][y])
		{
		case '<':direction = 1; break;
		case '>':direction = 0; break;
		case '^':direction = 3; break;
		case 'v':direction = 2; break;
		case '_':direction = memory == 0 ? 0 : 1; break;
		case '|':direction = memory == 0 ? 2 : 3; break;
		case '+':memory = memory == 15 ? 0 : memory + 1; break;
		case '-':memory = memory == 0 ? 15 : memory - 1; break;
		case '?':
			for (int i = 0;i < 4;i++) {
				int c = x + dx[i];
				int d = y + dy[i];
				if (c < 0)
					c = R - 1;
				else if (c > R - 1)
					c = 0;
				if (d < 0)
					d = C - 1;
				else if (d > C - 1)
					d = 0;
				if (!visited[c][d][i][memory]) {
					visited[c][d][i][memory] = true;
					q.push(make_pair(make_pair(c, d), make_pair(i, memory)));
				}
			}
			break;
		}
		if (map[x][y] != '?') {
			if (map[x][y] >= '0' && map[x][y] <= '9')
				memory = map[x][y] - '0';
			int c = x + dx[direction];
			int d = y + dy[direction];
			if (c < 0)
				c = R - 1;
			else if (c > R - 1)
				c = 0;
			if (d < 0)
				d = C - 1;
			else if (d > C - 1)
				d = 0;
			if (!visited[c][d][direction][memory]) {
				visited[c][d][direction][memory] = true;
				q.push(make_pair(make_pair(c, d), make_pair(direction, memory)));
			}
		}

	}
	return "NO";
}

int main()
{
	int test_case;
	int T;
	int R;
	int C;
	string result;

	cin >> T;

	for (test_case = 1;test_case <= T;test_case++) {
		memset(visited, false, sizeof(visited));
		cin >> R >> C;

		for (int i = 0;i < R;i++)
			for (int j = 0;j < C;j++)
				cin>>map[i][j];
		result = bfs(R,C);
		cout << "#" << test_case << " " << result << endl;
	}
}
