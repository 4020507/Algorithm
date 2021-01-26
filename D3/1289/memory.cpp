#include <iostream>

using namespace std;

/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV19AcoKI9sCFAZN&categoryId=AV19AcoKI9sCFAZN&categoryType=CODE
*/
int main(void)
{
	int T;
	string code;
	string init;
	cin >> T;

	for (int test_case = 1;test_case <= T;test_case++)
	{
		cin >> code;
		init = "";
		for (int i = 0;i < code.size();i++)
			init += "0";

		int curr = 0;
		int count = 0;
		while (code != init)
		{
			if (code[curr] != init[curr])
			{
				count++;
				if (code[curr] == '0')
				{
					for (int i = curr;i < code.size();i++)
						init[i] = '0';
				}
				else
					for (int i = curr;i < code.size();i++)
						init[i] = '1';
				
			}
			curr++;
			
		}
		cout << "#" << test_case << " " << count << endl;
	}
	return 0;
}
