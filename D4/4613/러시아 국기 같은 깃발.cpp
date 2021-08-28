#include <iostream>
#include <cstring>
using namespace std;

int N;
int M;
char flag[50][50];

int color[50][3];
int result;
void dfs(int curr, int column, int count, int up[])
{
	if (curr == N - 1)
	{
		if (up[0] == 0 || up[1] == 0 || up[2] == 0)
			return;
		if (result > count)
			result = count;
		return;
	}

	for (int i = column;i <= column + 1 && i<3;i++) {
		int check = 0;
		if (up[i] == 0)
		{
			check = 1;
			up[i] = 1;
		}
		dfs(curr + 1, i, count + color[curr + 1][i], up);
		if (check == 1)
		{
			up[i] = 0;
			check = 0;
		}
	}
}

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int test_case = 1;test_case <= T;test_case++)
	{
		cin >> N >> M;

		for (int i = 0;i < N;i++)
			for (int j = 0;j < M;j++)
				cin >> flag[i][j];
		result = N * M;
		memset(color, 0, sizeof(color));

		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				if (i == 0 && flag[i][j] != 'W')
					color[i][0]++;
				else if (i == N - 1 && flag[i][j] != 'R')
					color[i][2]++;
				else if (i == N - 2)
				{
					if (flag[i][j] != 'R')
						color[i][2]++;
					if (flag[i][j] != 'B')
						color[i][1]++;
				}
				else {
					if (flag[i][j] != 'W')
						color[i][0]++;
					if (flag[i][j] != 'B')
						color[i][1]++;
					if (flag[i][j] != 'R')
						color[i][2]++;
				}
			}
		}
		int upper[3] = { 1,0,0 };
		dfs(0, 0, color[0][0], upper);

		cout << "#" << test_case << " " << result << endl;
	}

	return 0;
}
