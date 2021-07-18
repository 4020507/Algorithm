#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

int parent[100001];

int findParent(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = findParent(parent[x]);
}

void Union(int a, int b)
{
	a = findParent(a);
	b = findParent(b);

	parent[a] = min(a, b);
	parent[b] = parent[a];
}


int main(void)
{
	int N;
	cin >> N;
	
	for (int i = 1;i <= N;i++)
		parent[i] = i;

	vector<pair<int, int>> x;
	vector<pair<int, int>> y;
	vector<pair<int, int>> z;

	for (int i = 1;i <= N;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		x.push_back({a,i});
		y.push_back({ b,i });
		z.push_back({ c,i });
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());
	vector<pair<int, pair<int,int>>> cost;

	for (int i = 0;i <= N-2;i++)
	{
		cost.push_back({ abs(x[i].first - x[i + 1].first) ,{x[i].second,x[i + 1].second} });
		cost.push_back({ abs(y[i].first - y[i + 1].first) ,{y[i].second,y[i + 1].second} });
		cost.push_back({ abs(z[i].first - z[i + 1].first) ,{z[i].second,z[i + 1].second} });
	}

	sort(cost.begin(), cost.end());

	int ans = 0;
	for (auto c : cost)
	{
		int dist = c.first;
		int a = c.second.first;
		int b = c.second.second;

		if (findParent(a) != findParent(b))
		{
			Union(a, b);
			ans += dist;
		}
	}

	cout << ans << endl;
	return 0;
}
