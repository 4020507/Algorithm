#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=4&contestProbId=AWd7sgDatsMDFAUh&categoryId=AWd7sgDatsMDFAUh&categoryType=CODE&problemTitle=&orderBy=INQUERY_COUNT&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=4
*/

bool cmp(int a, int b)
{
	return a > b;
}

int main(void)
{
	int T;
	cin >> T;

	int N;
	int K;
	double ability;
	double result;
	double lecture[200];
	for (int test_case = 1;test_case <= T;test_case++)
	{
		cin >> N >> K;
		ability = 0;
		vector<double> v;

		for (int i = 0;i < N;i++) {
			double value;
			cin >> value;
			v.push_back(value);
		}

		sort(v.begin(), v.end(), cmp);

		for (int i = K - 1;i >= 0;i--)
		{
			ability = (ability + v.at(i)) / 2;
		}

		cout << "#" << test_case << " " << ability << endl;
	}

	return 0;
}
