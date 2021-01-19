#include <iostream>
#include <stack>
#include <stdio.h>
#include <cstring>
using namespace std;

/*
There are N^2 rooms in NxN matrix
Each room has a different number.
Let assume that a person can go to a room in any ways which are top,left, right or bottom, only if the next room has one more bigger number 
Find a room that can go as much as possiple.
The output should be a number that the room has, and the number of the room you can go
If the answer can be more than one, the answer should be the room that has the smallest number 

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LtJYKDzsDFAXc
*/
int matrix[1000][1000];
bool visited[1000][1000];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int count;
int N;
int answer;
int pos;

void dfs(int i,int j,int max,int start)
{
	stack<pair<int,int>>s;
	s.push(make_pair(i, j));
	while (!s.empty())
	{
		int a = s.top().first;
		int b = s.top().second;
		s.pop();
		for (int i = 0;i < 4;i++)
		{
			int c = a + dx[i];
			int d = b + dy[i];

			if (c >= 0 && c < N && d >= 0 && d < N)
			{
				if (matrix[a][b] + 1 == matrix[c][d])
				{
					max++;
					visited[c][d] = true;
					s.push(make_pair(c, d));
					break;
				}
			}
		}
	}

	if (answer < max)
	{
		answer = max;
		pos = start;
	}
	else if (answer == max && start < pos)
	{
		pos = start;
	}

}
int main(void)
{
	int T;
	scanf("%d", &T);

	for (int test_case = 1;test_case <= T;test_case++)
	{
		scanf("%d", &N);//size of N

		memset(visited, false, sizeof(visited));
		answer = 1;
		pos = 10001;
		for (int i = 0;i < N;i++)
			for (int j = 0;j < N;j++)
				scanf(" %d", &matrix[i][j]);

		for (int i = 0;i < N;i++)
			for (int j = 0;j < N;j++) {
				if (!visited[i][j]) {//no need to visit again a room that already has been visited
					visited[i][j] = true;
					dfs(i, j, 1, matrix[i][j]);
				}
			}

		cout << "#" << test_case << " " << pos<<" "<<answer << endl;
	}

	return 0;
}
