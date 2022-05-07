#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int aliquot[1000001];
int num[10];
void create(int a, int b,int digits,int desired)
{
	if (b > digits || desired<a)
		return;
	if (a > 0)
		aliquot[a] = b;
	for (int i = 0;i < 10;i++)
	{
		if (num[i] == 1) {
			create(a * 10 + i, b + 1, digits, desired);
		}
	}
}
int main(void)
{
	int T;
	cin >> T;

	int desired;
	for (int test_case = 1;test_case <= T;test_case++)
	{
		memset(aliquot, 0, sizeof(aliquot));
		memset(num, 0, sizeof(num));
		for (int i = 0;i < 10;i++)
			scanf("%d", &num[i]);
		scanf("%d", &desired);
		
		int temp = desired;
		int digits = 0;
		while (temp > 0)
		{
			temp /= 10;
			digits++;
		}
		create(0, 0,digits,desired);
		
		if (num[1] == 1 && desired == 1) {
			printf("#%d %d\n", test_case, 2);
			continue;
		}
		temp = desired;
		int count = 0;
		for (int i = desired;i > 1;i--)
		{
			while (aliquot[i] > 0)
			{
				if (temp % i == 0)
				{
					count += 1 + aliquot[i];
					temp /= i;
				}
				else
					break;
			}
			if (temp == 1)
				break;
		}
		printf("#%d %d\n", test_case, temp != 1 ? -1 : count);
	}
}
