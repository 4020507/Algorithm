#include<iostream>
#include<algorithm>

#pragma warning(disable:4996)

#define INF 2000000000

using namespace std;

int N, M;
int A[100000];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A, A + N);

	int start = 0;
	int end = 0;
	int ans = INF;

	while (start < N && end < N) {

		if (A[end] - A[start] >= M) {

			ans = min(ans, A[end] - A[start++]);
		}
		else {
			end++;
		}
	}

	cout << ans;


	return 0;
}
