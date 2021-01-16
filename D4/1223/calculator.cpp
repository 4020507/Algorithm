#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;

/*
make a postfix calculator.
This calculator accepts +, *, 0~9 only.
You need to convert the equation to postfix, then calcualte the result

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14nnAaAFACFAYD&categoryId=AV14nnAaAFACFAYD&categoryType=CODE
*/
int main(void)
{
	int N;
	string temp;
	for (int test_case = 1;test_case <= 10;test_case++)
	{
		cin >> N;
		cin >> temp;
		
		vector<char> v;
		stack<char> s;

		for (int i = 0;i < N;i++) {
			if (temp[i] >= '0' && temp[i] <= '9')
			{
				v.push_back(temp[i]);
			}
			else if (s.empty() || temp[i] == '*')
				s.push(temp[i]);
			else if (temp[i] == '+')
			{
				while (!s.empty() && s.top() == '*') {
					v.push_back(s.top());
					s.pop();
				}
				s.push(temp[i]);
			}
		}
		while (!s.empty()) {
			v.push_back(s.top());
			s.pop();
		}
		int length = v.size();
		stack<int>result;
		for (int i = 0;i < length;i++)
		{
			if (v[i] >= '0' && v[i] <= '9')
			{
				result.push(v[i] - '0');
			}
			else if (v[i] == '+') {
				int first = result.top();
				result.pop();
				int second = result.top();
				result.pop();
				result.push(first + second);
			}
			else if (v[i] == '*')
			{
				int first = result.top();
				result.pop();
				int second = result.top();
				result.pop();
				result.push(first * second);
			}
		}
		cout << "#" << test_case << " " << result.top() << endl;
	}

	return 0;
}
