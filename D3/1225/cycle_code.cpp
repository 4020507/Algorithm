#include<iostream>
#include <stdio.h>

using namespace std;

/*
8 numbers are inputed
Cycle1 -> The first number is subtracted by one, and shift it to the last, so the second number becomes the first number.
Cycle2 -> the first number which was the second is subtracted by two, and shift it to the last... and so on.
This process continues until one of any subtracted numbers become 0.
If the result of subtraction is below 0, let it be 0.

There are up to 5 cycles. If the current cycle is 5, and need to go to the next, the next cycle is Cycle1

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14uWl6AF0CFAYD
*/
int main(void)
{
	int code[8];
	int T;
	for (int test_case = 1;test_case <= 10;test_case++)
	{
		scanf("%d", &T);//test_case numer
		int c;
		for (int i = 0;i < 8;i++) {
			cin >> c;//input code
			code[i] = c;
		}
		int cycle = 1;
		int result = 1;
		while (result > 0)//repeat until result becomes 0
		{
			result = code[0] - cycle;//subtract the frontmost code
			for (int i = 0;i < 7;i++) {
				code[i] = code[i + 1];//shift numbers
			}
			if (result > 0)
				code[7] = result;//the result goes to the last
			else
				code[7] = 0;
			cycle++;//go to the next cycle
			if (cycle > 5)
				cycle = 1;
		}
		cout << "#" << test_case;
		for (int i = 0;i < 8;i++)
			cout << " " << code[i];
		cout << endl;
	}
}
