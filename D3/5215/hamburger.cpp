#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
int N;
int L;
int result;
int save[20][2];
void dfs(int curr, int score,int kal)
{
	if (kal > L)
		return;
	if (result < score)
		result = score;

	for (int i = curr + 1;i < N;i++)
	{
		dfs(i, score + save[i][0], kal + save[i][1]);
	}
}
int main(void)
{
	int T;
	scanf("%d", &T);

	
	int t;
	int K;
	for (int test_case = 1;test_case <= T;test_case++)
	{
		scanf("%d%d", &N, &L);

		result = 0;
		for (int i = 0;i < N;i++)
		{
			scanf("%d%d", &save[i][0], &save[i][1]);
		}

		dfs(-1,0,0);

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;
}
