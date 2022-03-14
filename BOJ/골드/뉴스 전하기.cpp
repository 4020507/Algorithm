#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<int,int>> tree[51];
int N;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	return a.first > b.first;
}
int dfs(int curr)
{
	int child;
	for (int i = 0;i < tree[curr].size();i++)
	{
		child = tree[curr][i].second;

		tree[curr][i].first = dfs(child) + 1;
	}

	sort(tree[curr].begin(), tree[curr].end(),cmp);

	int res = 0;
	for (int i = 0;i < tree[curr].size();i++)
	{
		res = max(res, i + tree[curr][i].first);
	}

	return res;
}
int main(int argc, char** argv)
{
	cin >> N;
	int parent;
	for (int i = 0;i < N;i++)
	{
		cin >> parent;

		if (parent != -1)
			tree[parent].push_back({ 0,i });
	}

	cout << dfs(0);
	return 0;
}
