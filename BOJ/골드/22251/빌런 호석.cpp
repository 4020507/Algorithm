#include<iostream>
#include<string.h>
#include<string>
#pragma warning(disable:4996)

using namespace std;

int N, K, P, X;
int diff[10][10];
string s;

int changeNum(int idx, int p) {

	if (idx == K) {
		int num = stoi(s);
		if (num == X) {
			return 0;
		}
		else if (num <= N && num > 0) {
			return 1;
		}

		return 0;
	}

	int ans = 0;
	int num = s[idx] - '0';

	for (int i = 0; i < 10; i++) {
		if (diff[num][i] <= p) {
			s[idx] = i + '0';
			ans += changeNum(idx + 1, p - diff[num][i]);
			s[idx] = num + '0';
		}
	}

	return ans;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int num[10] = {
		0b1110111,
		0b0010010,
		0b1011101,
		0b1011011,
		0b0111010,
		0b1101011,
		0b1101111,
		0b1010010,
		0b1111111,
		0b1111011
	};

	memset(diff, 0, sizeof(diff));

	cin >> N >> K >> P >> X;

	int bin;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			bin = num[i] ^ num[j];

			while (bin > 0) {
				if ((bin & 1) == 1) {
					diff[i][j]++;
				}
				bin = (bin >> 1);
			}
		}
	}

	s = to_string(X);

	while (s.length() < K) {
		s.insert(s.begin(), '0');
	}

	cout << changeNum(0, P);
	return 0;
}
