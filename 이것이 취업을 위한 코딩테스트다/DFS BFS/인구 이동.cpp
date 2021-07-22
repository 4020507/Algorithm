#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;

int N, L, R;
int arr[50][50];
int temp[50][50];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y, int idx)
{
	queue<pair<int, int>> q;

	q.push({ x,y });

	vector<pair<int, int>> v;

	int count = 1;
	int sum = arr[x][y];
	temp[x][y] = idx;

	v.push_back({ x,y });
	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0;i < 4;i++)
		{
			int c = a + dx[i];
			int d = b + dy[i];

			if (c >= 0 && c < N && d >= 0 && d < N && temp[c][d] == -1)
			{
				int calc = abs(arr[c][d] - arr[a][b]);
				if (calc >= L && calc <= R)
				{
					q.push({ c,d });
					v.push_back({ c,d });
					temp[c][d] = idx;
					sum += arr[c][d];
					count++;
				}
			}
		}
	}

	for (auto i : v)
	{
		arr[i.first][i.second] = sum / count;
	}
}
int main(void)
{
	cin >> N >> L >> R;

	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++)
			cin >> arr[i][j];

	int count = 0;
	while (1)
	{
		memset(temp, -1, sizeof(temp));

		int idx = 0;
		for (int i = 0;i < N;i++)
		{
			for (int j = 0;j < N;j++)
			{
				if (temp[i][j] == -1)
				{
					dfs(i, j, idx);
					idx++;
				}
				
			}
		}

		if (idx == N * N)
			break;
		count++;
	}

	cout << count << endl;

	return 0;
}
