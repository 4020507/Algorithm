#include <iostream>

using namespace std;

/*
make a calculator for power of N using a reucrsive call method
T is for testcase number
N is the base number
M is the power 
*/

int recursive(int N, int M)
{
	if (M == 0)
		return 0;
	else if (M == 1)
		return N;
	else {
		return N * recursive(N, M - 1);
	}
}
int main(void)
{
	int T;
	int N;
	int M;

	for (int test_case = 1;test_case <= 10;test_case++)
	{
		cin >> T;
		cin >> N;
		cin >> M;

		int result = recursive(N, M);

		cout << "#" << test_case << " " << result << endl;
	}
}
