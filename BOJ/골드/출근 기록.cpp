#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
#pragma warning(disable:4996)
using namespace std;
string ans;
bool visited[51][51][51][3][3];
void check(int a, int b, int c, int check1, int check2, string s)
{
	if (ans != "")
		return;
	if (visited[a][b][c][check1][check2])
		return;
	if (a == 0 && b == 0 && c == 0)
	{
		ans = s;
		return;
	}
	int len = s.length();

	visited[a][b][c][check1][check2] = true;

	if (a > 0) {
		check(a - 1, b, c,check2,0, s + 'A');
	}
	if (b > 0)
	{
		if (check2 != 1)
		{
			check(a, b - 1, c, check2, 1, s + 'B');
		}
	}
	if (c > 0)
	{
		if (check1 != 2 && check2 != 2)
		{
			check(a, b, c - 1, check2, 2, s + 'C');
		}
	}
	
}
int main(int argc, char** argv)
{
	string s;
	cin >> s;
	int a = 0, b = 0, c = 0;
	for (int i = 0;i < s.length();i++)
	{
		if (s[i] == 'A')
			a++;
		else if (s[i] == 'B')
			b++;
		else if (s[i] == 'C')
			c++;
	}

	ans = "";
	if (c > 0)
	{
		check(a, b, c - 1, 0,2,"C");
	}
	if (b > 0)
	{
		check(a, b - 1, c, 0,1,"B");
	}
	if (a > 0) {
		check(a - 1, b, c, 0,0,"A");
	}

	if (ans == "")
		cout << -1;
	else
		cout << ans;
	return 0;
}
