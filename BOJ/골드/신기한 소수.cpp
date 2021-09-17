#include<iostream>

#pragma warning(disable:4996)
using namespace std;
int N;

bool check(int num)
{
	for (int i = 2;i*i <= num;i++)
	{
		if (num % i == 0)
			return false;
	}

	return true;
}
void find(int num, int n)
{
	if (n == N)
	{
		cout << num << '\n';
		return;
	}
	n++;
	num *= 10;
	for (int i = 1;i < 10;i += 2) {
		if (check(num + i))
			find(num + i, n);
	}
}

int main(int argc, char** argv)
{
	cin >> N;

	find(2, 1);
	find(3, 1);
	find(5, 1);
	find(7, 1);

	return 0;
}
