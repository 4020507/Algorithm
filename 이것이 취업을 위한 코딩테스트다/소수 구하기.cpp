#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<int> v(1000001, true);
int n, m;

int main(void)
{
	cin >> m >> n;

	for (int i = 2;i <= (int)sqrt(n);i++)
	{
		if (v[i])
		{
			int j = 2;

			while (i*j <= n)
			{
				v[i * j] = false;
				j++;
			}
		}
	}

	v[1] = false;
	for (int i = m;i <= n;i++)
	{
		if (v[i])
		{
			cout << i << '\n';
		}
	}
	
	return 0;
}
