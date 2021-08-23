#pragma warning(disable:4996)
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(void)
{
	string s;
	cin >> s;

	int ans = 0;
	int mul = 1;
	int len = s.length();
	bool complete = true;
	stack<char> st;

	for (int i = 0;i < len;i++)
	{
		if (s[i] == '[')
		{
			st.push(s[i]);
			mul *= 3;
		}
		else if (s[i] == '(')
		{
			st.push(s[i]);
			mul *= 2;
		}
		else if (s[i] == ']')
		{
			if (st.empty())
			{
				complete = false;
				break;
			}
			if (st.top() == '[')
			{
				if (s[i - 1] == '[')
					ans += mul;
				st.pop();
				mul /= 3;
			}
			else
			{
				complete = false;
				break;
			}
		}
		else if (s[i] == ')')
		{
			if (st.empty())
			{
				complete = false;
				break;
			}
			if (st.top() == '(')
			{
				if (s[i - 1] == '(')
					ans += mul;
				st.pop();
				mul /= 2;
			}
			else
			{
				complete = false;
				break;
			}
		}
	}

	if (complete && st.empty())
		cout << ans;
	else
		cout << 0;
	return 0;
}
