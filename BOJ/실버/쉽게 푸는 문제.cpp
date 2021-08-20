#pragma warning(disable:4996)
#include<iostream>

using namespace std;

int main(void)
{
	int less, bigger;

	cin >> less >> bigger;

	if (less > bigger)
		swap(less, bigger);
	int num[1000];
	int start = 1;
	int idx = 1;
	for (int i = 0;i <= bigger-1;i++)
	{
		num[i] = start;

		if (i == idx - 1)
		{
			start++;
			idx += start;
		}
	}

	int ans = 0;

	for (int i = less-1;i <= bigger-1;i++)
	{
		ans += num[i];
	}

	cout << ans;
	return 0;
}
