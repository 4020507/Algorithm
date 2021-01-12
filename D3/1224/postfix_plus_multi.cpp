#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

/*
make a postfix calculator.
This calculator accepts +, *, 0~9 only.
You need to convert the equation into postfix, then calcualte the result

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14tDX6AFgCFAYD&categoryId=AV14tDX6AFgCFAYD&categoryType=CODE
*/
int main(void)
{
	string input;
	int length;
	for (int test_case = 1;test_case <= 10;test_case++)
	{
		cin >> length;//length of the equation
		cin >> input;//input the equation

		vector<char> v;
		stack<char> s;

		for (int i = 0;i < length;i++)
		{
			if (input[i] >= '0' && input[i] <= '9')//put the character in the vector if it is number
				v.push_back(input[i]);
			else if (s.empty() || input[i] == '(')//put the character if it is ( or stack is empty
				s.push(input[i]);
			else if (input[i] == ')')//if the next character is ), pop the stack and put it in the vector until ( is found
			{
				while (!s.empty() && s.top() != '(') {
					v.push_back(s.top());
					s.pop();
				}
				s.pop();
			}
			else
			{
				if (input[i] == '*')//if the character is *, push the stack
					s.push(input[i]);
				else {
					while (!s.empty() && s.top() == '*')//if top of the stack is equal to *, and the current character is something else, pop the stack first then push the current character
					{
						v.push_back(s.top());
						s.pop();
					}
					s.push(input[i]);
				}
			}
		}
		while (!s.empty()) {
			v.push_back(s.top());
			s.pop();
		}
		int length = v.size();
		stack<int>result;
		for (int i = 0;i < length;i++)//calculate postfix
		{
			if (v[i] >= '0' && v[i] <= '9')
				result.push(v[i] - '0');
			else if (v[i] == '*')
			{
				int first = result.top();
				result.pop();
				int second = result.top();
				result.pop();
				result.push(first * second);
			}
			else if(v[i] == '+')
			{
				int first = result.top();
				result.pop();
				int second = result.top();
				result.pop();
				result.push(first + second);
			}
		}
		cout << "#" << test_case << " " << result.top() << endl;
	}
	return 0;
}
