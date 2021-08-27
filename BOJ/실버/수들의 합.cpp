#pragma warning(disable:4996)
#include<iostream>

using namespace std;


int main(void)
{
	long long S;
	cin >> S;
	long long N = 1;
	long long sum = 0;

	while (sum < S)
	{
		sum += N++;
	}

	if (sum == S)
		cout << --N;
	else
		cout << N - 2;

	return 0;
}
