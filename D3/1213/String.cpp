#include <iostream>
#include <string>

using namespace std;

/*
Input some characters and a sentence
Count a number that the number of these characters in the sentence

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14P0c6AAUCFAYi
*/
int main(void)
{
	int T;
	string find;
	string sentence;
	int count;

	for (int test_case = 1;test_case <=10;test_case++)
	{
		cin >> T;//testcase number
		cin >> find;//characters
		cin >> sentence;//sentence

		count = 0;
		
		for (int i = 0;i < sentence.size() - find.size() + 1;i++)
		{
			string partial = "";
			for (int j = i;j < i + find.size();j++)
			{
				partial += sentence[j];
			}
			if (find == partial)
				count++;
		}
		cout << "#" << test_case << " " << count << endl;
	}
}
