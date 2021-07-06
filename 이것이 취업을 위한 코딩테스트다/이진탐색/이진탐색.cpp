#pragma warning(disable:4996)
#include<iostream>
#include<vector>
using namespace std;



int main(void)
{
	int N, target;

	cin >> N >> target;

	vector<int> v;

	for (int i = 0;i < N;i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	int left = 0;
	int right = N - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (v[mid] == target)
		{
			cout << mid << endl;
			return 0;
		}

		if (v[mid] > target)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return 0;
}
