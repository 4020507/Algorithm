#include<iostream>
#include<vector>
#include<map>
#pragma warning(disable:4996)

using namespace std;


int nums[100000];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, i;

	cin >> N;

	for (i = 0; i < N; i++) {
		cin >> nums[i];
	}
	
	long long ans = 0;
	
	map<int, int> m;
	int j = 0;
	for (i = 0; i < N; i++) {

		while (j < N) {
			if (m[nums[j]] == 0) {
				m[nums[j]]++;
				j++;
			}
			else {
				break;
			}
		}

		ans += (j - i);
		m[nums[i]]--;
	}

	cout << ans;

	return 0;
}
