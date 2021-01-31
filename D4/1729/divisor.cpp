#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=4&contestProbId=AWtInr3auH0DFASy&categoryId=AWtInr3auH0DFASy&categoryType=CODE&problemTitle=&orderBy=INQUERY_COUNT&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=4
*/
int main(void)
{
	int T;
	cin >> T;

	int num;
	int divisor;
	for (int test_case = 1;test_case <= T;test_case++)
	{
		cin >> num;
		vector<int> v;
		for (int i = 0;i < num;i++) {
			cin >> divisor;
			v.push_back(divisor);
		}

		sort(v.begin(),v.end());
		int result = v[0] * v[num - 1];

		cout << "#" << test_case << " " << result << endl;
	}

	return 0;
}
