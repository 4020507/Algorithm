#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main(void)
{
	int N,M;

	cin >> N>>M;

	vector<int> cake;
	
	for (int i = 0;i < N;i++)
	{
		int len;
		cin >> len;
		cake.push_back(len);
	}
	sort(cake.begin(), cake.end());

	int start = cake[0];
	int end = cake[N - 1];
	int ans = 0;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		int sum = 0;

		for (int i = N - 1;i >= 0;i--)
		{
			int len = cake[i] - mid;
			if (len <= 0)
				break;
			sum += len;
		}

		if (sum == M)
		{
			ans = mid;
			break;
		}
		if (sum > M)
		{
			start = mid + 1;
			ans = mid;
		}
		else
			end = mid - 1;
	}

	cout << ans << endl;
	return 0;
}
