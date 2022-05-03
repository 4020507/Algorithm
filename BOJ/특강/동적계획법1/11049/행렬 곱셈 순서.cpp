#include<iostream>
#include<string.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int matrix[501][2];
int N;
int dp[501][501];

int calc(int a, int b)
{
	if (a == b)
		return 0;
	int& value = dp[a][b];
	if (value != -1)
		return value;

	value = 1e9;
	for (int i = a;i < b;i++)
	{
		value = min(value, calc(a,i) + calc(i+1,b) + matrix[a][0] * matrix[i][1] * matrix[b][1]);
	}
	
	return value;
}
int main(int argc, char** argv)
{
	cin >> N;

	for (int i = 0;i < N;i++)
	{
		cin >> matrix[i][0] >> matrix[i][1];
	}

	memset(dp, -1, sizeof(dp));

	cout << calc(0, N - 1);
}
