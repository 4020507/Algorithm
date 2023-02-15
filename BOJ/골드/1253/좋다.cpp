#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long nums[2000];
	int N;

	cin >> N;

	int i;

	for (i = 0; i < N; i++) {
		cin >> nums[i];
	}

	sort(nums, nums + N);
	
	int left, right;
	long long sum;
	int ans = 0;

	for (i = 0; i < N; i++) {
		left = 0;
		right = N - 1;

		left = 0;
		right = N - 1;
		while (left < right) {

			sum = nums[left] + nums[right];

			if (sum > nums[i]) {
				right--;
			}
			else if (sum < nums[i]) {
				left++;
			}
			else {
				if (right == i) {
					right--;
				}
				else if (left == i) {
					left++;
				}
				else {
					ans++;
					break;
				}
			}
		}
	}

	cout << ans;

	return 0;
}
