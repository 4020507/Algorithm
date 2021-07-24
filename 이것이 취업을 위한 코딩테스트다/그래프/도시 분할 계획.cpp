#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
int parent[100001];
vector<pair<int,pair<int, int>>> v;
int findParent(int a)
{
	if (parent[a] == a)
		return a;
	return parent[a] = findParent(parent[a]);
}

void Union(int a, int b)
{
	a = findParent(a);
	b = findParent(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}
int main(void)
{
	cin >> N >> M;

	for (int i = 1;i <= N;i++)
		parent[i] = i;

	for (int i = 0;i < M;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		v.push_back({ c,{a,b} });
	}

	sort(v.begin(), v.end());

	int minus = 0;

	vector<int> route;
	for (auto i : v)
	{
		int cost = i.first;
		int start = i.second.first;
		int end = i.second.second;

		if (findParent(start) != findParent(end))
		{
			Union(start, end);
			route.push_back(cost);
		}
	}

	for (int i = 0;i < route.size() - 1;i++)
		minus += route[i];

	cout << minus << '\n';
	return 0;
}
