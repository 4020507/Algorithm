#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(void)
{
	int T;
	cin >> T;

	char string1[10];
	char string2[10];
	int decode1[10];
	int decode2[10];
	bool ans;
	for (int test_case = 1;test_case <= T;test_case++)
	{
		scanf("%s %s", string1, string2);
		int length1 = strlen(string1);
		int length2 = strlen(string2);
		ans = true;

		if (length1 == length2) {
			for (int i = 0;i < length1;i++)
			{

				if (string1[i] == 'C' || string1[i] == 'E' || string1[i] == 'F' || string1[i] == 'G' || string1[i] == 'H' || string1[i] == 'I' ||
					string1[i] == 'J' || string1[i] == 'K' || string1[i] == 'L' || string1[i] == 'M' || string1[i] == 'N' || string1[i] == 'S' ||
					string1[i] == 'T' || string1[i] == 'U' || string1[i] == 'V' || string1[i] == 'W' || string1[i] == 'X' || string1[i] == 'Y' ||
					string1[i] == 'Z')
				{
					decode1[i] = 1;
				}
				else if (string1[i] == 'A' || string1[i] == 'D' || string1[i] == 'O' || string1[i] == 'P' || string1[i] == 'Q' || string1[i] == 'R')
				{
					decode1[i] = 2;
				}
				else if (string1[i] == 'B')
					decode1[i] = 3;
			}

			for (int i = 0;i < length2;i++)
			{
				if (string2[i] == 'C' || string2[i] == 'E' || string2[i] == 'F' || string2[i] == 'G' || string2[i] == 'H' || string2[i] == 'I' ||
					string2[i] == 'J' || string2[i] == 'K' || string2[i] == 'L' || string2[i] == 'M' || string2[i] == 'N' || string2[i] == 'S' ||
					string2[i] == 'T' || string2[i] == 'U' || string2[i] == 'V' || string2[i] == 'W' || string2[i] == 'X' || string2[i] == 'Y' ||
					string2[i] == 'Z')
				{
					if (decode1[i] != 1)
					{
						ans = false;
						break;
					}
				}
				else if (string2[i] == 'A' || string2[i] == 'D' || string2[i] == 'O' || string2[i] == 'P' || string2[i] == 'Q' || string2[i] == 'R')
				{
					if (decode1[i] != 2)
					{
						ans = false;
						break;
					}
				}
				else if (string2[i] == 'B')
				{
					if (decode1[i] != 3)
					{
						ans = false;
						break;
					}
				}

			}
		}
		else
			ans = false;

		printf("#%d ", test_case);
		if (ans)
			printf("SAME\n");
		else
			printf("DIFF\n");
	}
	return 0;
}
