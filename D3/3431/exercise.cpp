#include <iostream>

using namespace std;

/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWE_ZXcqAAMDFAV2&categoryId=AWE_ZXcqAAMDFAV2&categoryType=CODE
*/
int main(void)
{
	int T;
	cin >> T;

	int min;
	int max;
	int actual;
	for (int test_case = 1;test_case <= T;test_case++)
	{
		scanf("%d%d%d", &min, &max, &actual);

		cout << "#" << test_case << " ";
		if (actual > max)
			cout << -1;
		else if (actual > min)
			cout << 0;
		else
			cout << min - actual;
		cout << endl;
	}

	return 0;
}
