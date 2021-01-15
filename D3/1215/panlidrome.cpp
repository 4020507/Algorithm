#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

/*
Count panlidrome.
There is 10 cases with the 8x8 matirx
There is only 3 characters A,B,C
Apply for width and height only
You need to input the number to define 'range'
If the 'range' is 4, compare with 4 letters.
For example, ABBABABB -> 'ABBA'BABB -> 'ABBA', this is a panidrome
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14QpAaAAwCFAYi&categoryId=AV14QpAaAAwCFAYi&categoryType=CODE
*/
int main(void)
{
	double circular;
	char matrix[8][8];
	for(int test_case = 1; test_case<=10;test_case++)
	{
		cin >> circular;

		for (int i = 0;i < 8;i++)
			for (int j = 0;j < 8;j++)
				cin >> matrix[i][j];
		string s1 = "";
		string s2 = "";
		int count = 0;
		int row = 0;
		while (row < 8) {
			for (int i = 0;i < 8 - circular + 1;i++)
			{
				for (int j = i;j < i + floor(circular / 2);j++)
					s1 +=matrix[row][j];
				for (int k = ceil(circular / 2) + i;k < i + circular;k++)
					s2 +=matrix[row][k];
				reverse(s2.begin(), s2.end());
				if (s1 == s2)
					count++;
				s1 = "";
				s2 = "";
			}
			row++;
		}
		int column = 0;
		while (column < 8) {
			for (int j = 0;j < 8 - circular + 1;j++)
			{
				for (int l = j; l < j + floor(circular / 2);l++)
					s1 += matrix[l][column];
				for (int k = ceil(circular / 2) + j;k < j + circular;k++)
					s2 +=matrix[k][column];
				reverse(s2.begin(), s2.end());
				if (s1 == s2)
					count++;
				s1 = "";
				s2 = "";
			}
			column++;
		}

		cout << "#" << test_case << " "<< count << endl;

	}
}
