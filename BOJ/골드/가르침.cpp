#pragma warning(disable:4996)
#include<iostream>
#include<string>
using namespace std;

int N, K;
string words[50];
bool alpha[26];
int ans = 0;
void dfs(int idx, int count)
{
	if (count == K)
	{
		if (!alpha['a' - 'a'] || !alpha['n' - 'a'] || !alpha['t' - 'a'] || !alpha['i' - 'a'] || !alpha['c' - 'a'])
			return;
		int t = 0;

		for (int i = 0;i < N;i++)
		{
			int len = words[i].length();
			bool learned = true;
			for (int j = 0;j < len;j++)
			{
				if (!alpha[words[i][j]-'a'])
				{
					learned = false;
					break;
				}
			}

			if (learned)
				t++;
		}
		ans = max(ans, t);
		return;
	}

	for (int i = idx;i < 26;i++)
	{
		if (!alpha[i])
		{
			alpha[i] = true;
			dfs(i+1, count+1);
			alpha[i] = false;
		}
	}
}
int main(void)
{
	cin >> N >> K;

	for (int i = 0;i < N;i++)
	{
		cin >> words[i];
	}

	if (K == 26)
		ans = N;
	else if (K < 5)
		ans = 0;
	else {
		ans = 0;
		dfs(0, 0);
	}

	cout << ans;

	return 0;
}
