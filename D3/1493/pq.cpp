#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int T;

	cin >> T;

	vector<pair<int, int>> v;

	int a = 1;
	int b = 1;

	for (int i = 0;i < 10000;i++)
	{
		v.push_back(make_pair(a, b));
		b += 1;
		if (b > a) {
			a += 1;
			b = 1;
		}
	}

	int first, second;

	for (int test_case = 1;test_case <= T;test_case++)
	{
		cin >> first>> second;
		int p_i = v[first - 1].first;
		int p_j = v[first - 1].second;
		int q_i = v[second - 1].first;
		int q_j = v[second - 1].second;

		int pq_i = p_i + q_i;
		int pq_j = p_j + q_j;

		int ans = 0;

		for (int i = 1;i <= pq_i;i++)
			ans += i;
		ans += pq_j;

		cout << "#" << test_case << " " << ans << endl;

	}

	return 0;
}
