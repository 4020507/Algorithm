#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
using namespace std;

int edit[5001][5001];
int main(void)
{
	string s1, s2;
	
	cin >> s1 >> s2;

	for (int i = 0;i <= s1.length();i++)
		edit[i][0] = i;
	for (int i = 0;i <= s2.length();i++)
		edit[0][i] = i;
	
	for (int i = 1;i <= s1.length();i++)
	{
		for (int j = 1;j <= s2.length();j++)
		{
			if (s1[i] == s2[j]) {
				edit[i][j] = edit[i - 1][j - 1];
				continue;
			}
			edit[i][j] =  1 + min(edit[i - 1][j - 1], min(edit[i][j - 1], edit[i - 1][j]));
		}
	}

	cout << edit[s1.length()][s2.length()] << endl;

	return 0;
}
