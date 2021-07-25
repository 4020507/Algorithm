#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> v;

int main(void)
{
	int N;
	cin >> N;

	int total = 0;
	for (int i = 0;i < N;i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
		total += a;
	}

	sort(v.begin(), v.end());

	int start = 1;
	for (int i = 0;i < v.size();i++)
	{
		if (start < v[i])
		{
			cout << start << endl;
			return 0;
		}
		start += v[i];
	}

	cout << total + 1 << endl;
	return 0;
}
