#pragma warning(disable:4996)
#include<iostream>

using namespace std;

int main(void)
{
	int N, K;
	cin >> N >> K;

	int q;
	int find = 0;
	for (int i = 1;i <= N;i++)
	{
		if (N % i == 0)
		{
			q = i;
			find++;

			if (find == K)
			{
				cout << q;
				return 0;
			}
		}
	}

	cout << 0;
	return 0;
}
