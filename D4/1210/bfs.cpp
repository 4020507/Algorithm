#include<iostream>
#include<stdio.h>
#include<cstring>

using namespace std;

int data[100][100];
int dx[3] = { 0,0,-1 };
int dy[3] = { 1,-1,0 };

bool visited[100][100];
int result;

void bfs(int x, int y)
{
	if (x == 0) {
		result = y;
		return;
	}


	for (int i = 0;i < 3;i++) {
		int c = x + dx[i];
		int d = y + dy[i];
		if (c >= 0 && c < 100 && d >= 0 && d < 100) {
			if (data[c][d] == 1 && visited[c][d] == false) {
				visited[c][d] = true;
				bfs(c, d);
				return;
			}
		}
	}

}

int main(void)
{

	int column;

	for (int test_case = 1;test_case <= 10;test_case++)
	{
		int T;
		cin >> T;
		memset(visited, false, sizeof(visited));
		for (int i = 0;i < 100;i++)
			for (int j = 0;j < 100; j++) {
				scanf("%d", &data[i][j]);
				if (data[i][j] == 2) {
					column = j;
				}
			}

		bfs(99, column);

		printf("#%d %d\n", test_case, result);

	}
}
