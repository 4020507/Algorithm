#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

/*
https://swexpertacademy.com/main/code/problem/problemSubmitHistory.do?contestProbId=AWVl47b6DGMDFAXm
*/
int main(void)
{
	int T;
	scanf("%d", &T);

	
	int stick;
	int answer;
	char bracket[100000];
	bool check;
	for (int test_case = 1;test_case <= T;test_case++)
	{
		
		scanf("%s", bracket);

		check = true;
		answer = 0;
		stick = 0;
		for (register int i = 0;i < strlen(bracket);i++)
		{
			
			if (bracket[i] == '(')
			{
				stick++;
				check = false;
			}
			else if (bracket[i] == ')' && !check)
			{
				stick--;
				answer += stick;
				check = true;
			}
			else if (bracket[i] == ')' && check)
			{
				answer++;
				stick--;
			}
		}
		printf("#%d %d\n",test_case, answer);
	}
	return 0;
}
