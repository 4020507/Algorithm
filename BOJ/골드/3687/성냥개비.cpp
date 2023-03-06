#include<iostream>

#pragma warning(disable:4996)

using namespace std;

string maxNum[101];
long long minNum[101];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T, N, i;
	cin >> T;

	//최대값
	string num;
	int temp;

	for (i = 2; i <= 100; i++) {
		temp = i;

		if (i % 2 == 0) {
			num = "";
			while (temp > 0) {
				num += "1";
				temp -= 2;
			}
			maxNum[i] = num;
		}
		else {
			num = "7";
			temp -= 3;

			while (temp > 0) {
				num += "1";
				temp -= 2;
			}

			maxNum[i] = num;
		}
	}

	//최소값

	int j;

	minNum[0] = 9;
	minNum[1] = 9;

	minNum[2] = 1;
	minNum[3] = 7;
	minNum[4] = 4;
	minNum[5] = 2;
	minNum[6] = 6;
	minNum[7] = 8;
	minNum[8] = 10;

	int nums[8] = { 0,0,1,7,4,2,0,8 };
	for (i = 9; i < 101; i++) {
		minNum[i] = 888888888888888;

		for (j = 2; j <= 7; j++) {
			minNum[i] = min(minNum[i], minNum[i - j] * 10 + nums[j]);
		}
	}

	for (int t = 0; t < T; t++) {
		cin >> N;

		cout << minNum[N] << ' ' << maxNum[N] << '\n';
	}
	return 0;
}
