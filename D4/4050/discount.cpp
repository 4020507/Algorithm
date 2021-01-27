#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIseXoKEUcDFAWN&categoryId=AWIseXoKEUcDFAWN&categoryType=CODE
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

	for (int test_case = 1; test_case <= T;test_case++)
	{
		cin >> N;
		vector<int> cloth;
		int cost;
		for (int i = 0;i < N;i++)
		{
			scanf("%d", &cost);
			cloth.push_back(cost);
		}
		sort(cloth.begin(), cloth.end(),cmp);
		//to maximize the highest discount rate, pick the most expensive 3 clothes
		int sum = 0;
		for (int i = 0;i < cloth.size();i++)
		{
			if (i % 3 != 2)
				sum += cloth.at(i);
		}
		cout << "#" << test_case << " " << sum << endl;

	}
}
