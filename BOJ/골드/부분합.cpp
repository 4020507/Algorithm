#pragma warning(disable:4996)
#include<iostream>

using namespace std;

long long N, S;
long long nums[100000];

int main(void)
{
	cin >> N >> S;

	for (int i = 0;i < N;i++)
		cin >> nums[i];
	int start = 0;
	int end = 0;
	int total = nums[0];
	int ans = 1e9;
	while (end < N && start<=end)
	{
		while (total < S && end < N)
		{
			total += nums[++end];
		}

		if (S <= total)
		{
			ans = min(ans, end - start + 1);
			total -= nums[start++];
		}
	}
	
	if (ans != 1e9)
		cout << ans;
	else
		cout << 0;
	return 0;
}
