#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
	int N, M, K;

	cin >> N >> M >> K;

	int num[1000];

	for (int i = 0;i < N;i++)
		cin >> num[i];

	sort(num, num + N);

	int pattern = (num[N - 1] * K + num[N - 2]) * (M / (K + 1)) + num[N - 1] * (M % (K + 1));

	cout << pattern << endl;
	return 0;
}
