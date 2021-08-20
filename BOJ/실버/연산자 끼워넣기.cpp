#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	vector<char> operators;
	int nums[11];
	int N;

	cin >> N;

	for (int i = 0;i < N;i++)
		cin >> nums[i];
	for (int i = 0;i < 4;i++)
	{
		int o;
		cin >> o;
		for (int j = 0;j < o;j++)
		{
			if (i == 0)
				operators.push_back('+');
			else if (i == 1)
				operators.push_back('-');
			else if (i == 2)
				operators.push_back('*');
			else
				operators.push_back('/');
		}
	}

	int mini = 1e9;
	int maxi = -1e9;
	sort(operators.begin(), operators.end());
	do
	{
		int idx = 1;
		int ans = nums[0];
		for (auto o : operators)
		{
			if (o == '+')
			{
				ans += nums[idx];
			}
			else if (o == '-')
			{
				ans -= nums[idx];
			}
			else if (o == '*')
			{
				ans *= nums[idx];
			}
			else
				ans /= nums[idx];
			idx++;
		}
		mini = min(mini, ans);
		maxi = max(maxi, ans);

	} while (next_permutation(operators.begin(), operators.end()));

	cout << maxi << '\n';
	cout << mini;
	return 0;
}
