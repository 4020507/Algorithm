#include <iostream>
#include <string>
using namespace std;
//#pragma warning(disable: 4996)
int main(void)
{
	int num;

	string password;
	int count;
	for (int test_case = 1;test_case <= 10;test_case++)
	{
		cin >> num >> password;
		count = 0;

		for (int i = 1;i < password.length();i++)
		{
			while (password[i - 1] == password[i]) {
				password.erase(i - 1, 2);
				i -= 1;
			}
		}
		
		
		cout << "#" << test_case << " " << password << endl;
	}
	return 0;
}
