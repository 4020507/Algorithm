#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>

/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14BgD6AEECFAYh
*/

using namespace std;

int dx[3] = { 0,0,1 };
int dy[3] = { 1,-1,0 };

int map[100][100];
int start[100];
bool visited[100][100];
vector<pair<int, int>> c;

void bfs(int x, int y,int count,int start_point)
{
	if (x == 99) {
		c.push_back(make_pair(count, start_point));
		return;
	}

	for (int i = 0;i < 3;i++) {
		int a = x + dx[i];
		int b = y + dy[i];
		if (a >= 0 && a < 100 && b >= 0 && b < 100) {
			if (map[a][b] == 1 && !visited[a][b]) {
				count++;
				visited[a][b] = true;
				bfs(a, b, count, start_point);
				return;
			}
		}
	}
}

int main(void)
{
	int T;
	for (int test_case = 1;test_case <= 10;test_case++)
	{
		cin >> T;
		memset(start, 0, sizeof(start));
		
		int count = 0;

		for (int i = 0;i < 100;i++) {
			for (int j = 0;j < 100;j++) {
				scanf("%d", &map[i][j]);
				if (i == 0 && map[0][j] == 1) {
					start[j] = 1;//save the starting coordinate
				}
			}
		}
		
		for (int k = 0;k < 100;k++) {
			if (start[k] == 1) {
				memset(visited, false, sizeof(visited));
				visited[0][k] = true;
				bfs(0, k, 0, k);//calculate the distance to reach at arrival point
			}
		}
		
		sort(c.begin(), c.end());//sort in ascending order

		int path_count = c[0].first;
		int answer = c[0].second;
		
		for (int l = 1;l < c.size();l++) {
			if (path_count == c[l].second)//the answer should be the shortest way. If there are more than one answer, the answer should be the biggest coordinate
				answer = c[l].second;
			else
				break;
		}
		cout << "#" << test_case << " " << answer << endl;
		c.clear();
		
	}
}
