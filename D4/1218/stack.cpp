#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;
/*
check there are pairs for '[]','{}",'<>', and '()'
print 1 for yes, 0 for no

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14eWb6AAkCFAYD
*/
int main()
{
	
	int num;
	int bracket1;// number of (
	int bracket1_pair;// )
	int bracket2;// [
	int bracket2_pair;// ]
	int bracket3;// {
	int bracket3_pair;// }
	int bracket4;// <
	int bracket4_pair;// >
	for (int test_case = 1; test_case <= 10; test_case++)
	{
		cin >> num;//input the number of characters

		stack<char>bracket;
		char input;
		bracket1 = 0;
		bracket1_pair = 0;
		bracket2 = 0;
		bracket2_pair = 0;
		bracket3 = 0;
		bracket3_pair = 0;
		bracket4 = 0;
		bracket4_pair = 0;

		for (int i = 0;i < num;i++)
		{
			cin >> input;
			bracket.push(input);//save the character in the stack
		}

		while (!bracket.empty())
		{
			char c = bracket.top();//take out the character, and count its number
			bracket.pop();

			if (c == '(')
				bracket1++;
			else if (c == ')')
				bracket1_pair++;
			else if (c == '[')
				bracket2++;
			else if (c == ']')
				bracket2_pair++;
			else if (c == '{')
				bracket3++;
			else if (c == '}')
				bracket3_pair++;
			else if (c == '<')
				bracket4++;
			else if (c == '>')
				bracket4_pair++;
		}
		cout << "#" << test_case << " ";
		if (bracket1 == bracket1_pair &&
			bracket2 == bracket2_pair &&
			bracket3 == bracket3_pair &&
			bracket4 == bracket4_pair)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
}
