#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int T;

	for (int test_case = 1; test_case <= 10;test_case++)
	{
		cin >> T;

		int arr[100][100];

		for (int i = 0;i < 100;i++)
			for (int j = 0;j < 100;j++)
				cin >> arr[i][j];
		int sum[202] = { 0, };
		
		for (int i = 0;i < 100;i++)
			for (int j = 0;j < 100;j++)
				sum[i] += arr[i][j];
		for (int j = 0;j < 100;j++)
			for (int i = 0;i < 100;i++)
				sum[j + 100] += arr[i][j];
		for (int i = 0;i < 100;i++)
			sum[200] += arr[i][i];
		for (int j = 0;j < 100;j++)
			sum[201] += arr[j][99 - j];

		int result = 0;
		for (int i = 0;i < 202;i++)
			result = max(result, sum[i]);

		cout << "#" << test_case << " " << result << endl;

	}
}
