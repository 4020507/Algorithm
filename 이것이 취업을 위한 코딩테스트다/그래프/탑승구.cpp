#pragma warning(disable:4996)
#include<iostream>
#include<vector>
using namespace std;

int parent[100001];

int findParent(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = findParent(parent[x]);
}

void Union(int x, int y)
{
	x = findParent(x);
	y = findParent(y);

	if (x > y)
		parent[x] = y;
	else
		parent[y] = x;
}

int main(void)
{
	int G, P;
	cin >> G >> P;

	for (int i = 1;i <= G;i++)
		parent[i] = i;

	vector<int> v;
	for (int i = 0;i < P;i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	int count = 0;
	for (int i = 0;i < v.size();i++)
	{
		int a = v[i];

		int p = findParent(a);

		if (p == 0)
			break;

		Union(p, p - 1);
		count++;
	}

	cout << count << endl;

	return 0;
}
