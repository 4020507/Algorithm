#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int T;
	cin >> T;

	int N, M, K;
	int person[100];
	for (int test_case = 1;test_case <= T;test_case++)
	{
		cin >> N >> M >> K;

		for (int i = 0;i < N;i++)
			cin >> person[i];
		sort(person, person + N);
		int ans;
		bool possible = true;
		for (int i = 0;i < N;i++)
		{
			ans = K * (person[i]/M) - i - 1;
			if (ans < 0)
			{
				possible = false;
				break;
			}

		}
		if (possible)
			cout << "#" << test_case << " Possible" << endl;
		else
			cout << "#" << test_case << " Impossible" << endl;
	}

	return 0;
}
