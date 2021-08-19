#pragma warning(disable:4996)
#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	int T;
	cin >> T;

	for (int test_case = 1;test_case <= T;test_case++)
	{
		string n = "";
		int num;
		cin >> num;

		while (num > 0)
		{
			if (num % 2 == 1)
			{
				n += '1';
			}
			else
				n += '0';
			num /= 2;
		}

		for (int i = 0;i < n.length();i++)
		{
			if (n[i] == '1')
				cout << i << ' ';
		}

		cout << '\n';
	}
	return 0;
}
