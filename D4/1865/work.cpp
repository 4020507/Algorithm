#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

bool visited[16];
double rate[100][16];
double result;
int N;
void dfs(double percentage, int count)
{
	if (percentage * 100 <= result)
		return;
	if (count == N)
	{
		if (percentage * 100 > result)
			result = percentage * 100;
		return;
	}

	for (int i = 0;i < N;i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			dfs(percentage * rate[count][i], count+1);
			visited[i] = false;
		}
	}

}
int main(void)
{
	int T;
	cin >> T;

	

	for (int test_case = 1;test_case <= T;test_case++)
	{
		cin >> N;
		memset(visited, false, sizeof(visited));

		for (int i = 0;i < N;i++)
			for (int j = 0;j < N;j++) {
				scanf("%lf", &rate[i][j]);
				rate[i][j] /= 100;
			}
		result = 0.0;
		dfs(1.0, 0);
		printf("#%d %.6lf\n", test_case, result);
	}
	return 0;
}
