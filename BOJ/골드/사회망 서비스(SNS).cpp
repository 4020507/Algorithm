#include<iostream>
#include<vector>
#include<string.h>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;

vector<int> connected[1000001];
vector<int> tree[1000001];
bool visited[1000001];
int dp[1000001][2];
int N;

void make_tree(int node)
{
	visited[node] = true;
	for (auto t : connected[node])
	{
		if (!visited[t]) {
			tree[node].push_back(t);
			make_tree(t);
		}
	}
}

int getAnswer(int node, int state)
{
	if (dp[node][state] != -1)
		return dp[node][state];

	if (state == 0)
	{
		dp[node][state] = 1;
		for (auto t : tree[node])
		{
			dp[node][state] += min(getAnswer(t, 0), getAnswer(t, 1));
		}
	}
	else
	{
		dp[node][state] = 0;
		for (auto t : tree[node])
		{
			dp[node][state] += getAnswer(t, 0);
		}
	}

	return dp[node][state];
}
int main(int argc, char** argv)
{
	cin >> N;

	for (int i = 0;i < N - 1;i++)
	{
		int a, b;
		cin >> a >> b;
		connected[a].push_back(b);
		connected[b].push_back(a);
	}
	memset(visited, false, sizeof(visited));
	make_tree(1);
	memset(dp, -1, sizeof(dp));
	cout << min(getAnswer(1, 0), getAnswer(1, 1));
	return 0;
}
