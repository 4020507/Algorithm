#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
using namespace std;

int trip[501][501];
int plan[500];
int parent[501];
int findParent(int num)
{
	if (parent[num] == num)
		return num;
	return parent[num] = findParent(parent[num]);
}

void Union(int a, int b)
{
	parent[a] = min(parent[a], parent[b]);
	parent[b] = parent[a];
}
int main(void)
{
	int N,M;
	cin >> N >> M;

	for (int i = 1;i <= N;i++)
		parent[i] = i;

	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			cin >> trip[i][j];

			if (trip[i][j] == 1)
			{
				Union(i+1,j+1);
			}
		}
	}

	for (int i = 0;i < M;i++)
		cin >> plan[i];

	int init = plan[0];

	for (int i = 1;i < M;i++)
	{
		if (findParent(init) != findParent(plan[i])) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	return 0;
}
