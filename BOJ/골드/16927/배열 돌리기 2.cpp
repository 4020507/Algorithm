#include<iostream>
#include<string.h>
#include<algorithm>

#pragma warning(disable:4996)

#define INF 1e9

using namespace std;

int N, M, R;
int arr[300][300];

void rotate() {

	int x1 = 0;
	int y1 = 0;
	int x2 = N - 1;
	int y2 = 0;
	int x3 = N - 1;
	int y3 = M - 1;
	int x4 = 0;
	int y4 = M - 1;

	int i, r;

	while (x1 < x2 && y1 < y4) {
		r = R % ((x2 - x1) * 2 + (y4 - y1) * 2);
		while (r--) {
			int  temp = arr[x1][y1];

			for (i = y1; i < y4; i++) {
				arr[x1][i] = arr[x1][i + 1];
			}

			for (i = x4; i < x3; i++) {
				arr[i][y4] = arr[i + 1][y4];
			}

			for (i = y3; i > y2; i--) {
				arr[x3][i] = arr[x3][i - 1];
			}

			for (i = x2; i > x1; i--) {
				arr[i][y2] = arr[i - 1][y2];
			}

			arr[x1 + 1][y1] = temp;
		}

		x1++;
		y1++;

		x2--;
		y2++;

		x3--;
		y3--;

		x4++;
		y4--;
	}
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	
	cin >> N >> M >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	rotate();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << ' ';
		}

		cout << '\n';
	}

	return 0;
}16
