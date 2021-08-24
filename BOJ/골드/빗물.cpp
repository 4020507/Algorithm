#pragma warning(disable:4996)
#include<iostream>

using namespace std;

int blocks[500];
int left_most[500];
int right_most[500];
int main(void)
{
	int H, W;
	cin >> H >> W;

	for (int i = 0;i < W;i++)
		cin >> blocks[i];
	left_most[0] = blocks[0];

	for (int i = 1;i < W;i++)
		left_most[i] = max(left_most[i - 1], blocks[i]);

	right_most[W - 1] = blocks[W - 1];

	for (int i = W - 2;i >= 0;i--)
		right_most[i] = max(right_most[i + 1], blocks[i]);

	int ans = 0;

	for (int i = 1;i < W-1;i++)
		ans += min(left_most[i], right_most[i]) - blocks[i];

	cout << ans;

	return 0;
}
