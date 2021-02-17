#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(void)
{
	int T;
	scanf("%d", &T);

	string temp1[1000];
	string temp2[1000];
	int N;
	for (int test_case = 1;test_case <= T;test_case++)
	{
		scanf("%d", &N);

		int count1 = 0;
		int count2 = 0;
		for (int i = 0;i < N;i++)
		{
			if (N % 2 == 0) {
				if (i < N / 2) {
					cin >> temp1[count1];
					count1++;
				}
				else {
					cin >> temp2[count2];
					count2++;
				}
			}
			else
			{
				if (i < N / 2+1) {
					cin >> temp1[count1];
					count1++;
				}
				else {
					cin >> temp2[count2];
					count2++;
				}
			}
		}
		cout << "#" << test_case << " ";
		int count3 = 0;
		int count4 = 0;
		for (int i = 0;i < N;i++)
		{
			if (i % 2 == 0) {
				cout << temp1[count3] << " ";
				count3++;
			}
			else
			{
				cout << temp2[count4] << " ";
				count4++;
			}
		}
		
		cout << endl;

	}
	return 0;
}
