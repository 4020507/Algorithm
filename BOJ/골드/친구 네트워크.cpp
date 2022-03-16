#include<iostream>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

int parent[200020];
int network[200020];
int index;
int findParent(int p)
{
	if (parent[p] == p)
		return p;
	return parent[p] = findParent(parent[p]);
}

void Union(int a, int b)
{
	a = findParent(a);
	b = findParent(b);

	if (a != b)
	{
		parent[a] = b;
		network[b] += network[a];
		network[a] = 0;
	}
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int T;
	cin >> T;
	int F, p1, p2, i;
	string name1, name2;
	map<string, int> m;
	for (int test_case = 1;test_case <= T;test_case++)
	{
		cin >> F;

		m.clear();
		index = 1;

		for (i = 0;i < F * 2;i++) {
			parent[i] = i;
			network[i] = 1;
		}

		for (i = 0;i < F;i++)
		{
			cin >> name1 >> name2;

			if (m.count(name1) == 0)
				m[name1] = index++;

			if (m.count(name2) == 0)
				m[name2] = index++;
			p1 = findParent(m[name1]);
			p2 = findParent(m[name2]);

			if (p1 != p2)
				Union(p1, p2);
			
			cout << network[p2] << '\n';
		}
	}
	return 0;
}
