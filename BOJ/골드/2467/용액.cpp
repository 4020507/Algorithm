#include<iostream>
#include<algorithm>
#include<math.h>
#pragma warning(disable:4996)

#define INF 100000

using namespace std;

int arr[100000];
int N;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int left = 0;
	int right = N - 1;

	int small = 0;
	int big = N - 1;
	int ans = 2000000001;
	int sum;

	while (left < right) {

		if (ans == 0)
			break;

		sum = arr[left] + arr[right];

		if (abs(sum) < ans) {
			ans = abs(sum);

			small = left;
			big = right;
		}

		if (sum > 0) {
			right--;
		}
		else {
			left++;
		}
	}

	cout << arr[small] << ' ' << arr[big];

	return 0;
}
