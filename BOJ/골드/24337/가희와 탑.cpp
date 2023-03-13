#include<iostream>
#include<deque>
#pragma warning(disable:4996)

using namespace std;


int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, a, b;

	cin >> N >> a >> b;

	deque<int> dq;

	int highest = max(a, b);

	int i;

	for (i = 1; i < a; i++) {
		dq.push_back(i);
	}

	dq.push_back(highest);

	for (i = b - 1; i >= 1; i--) {
		dq.push_back(i);
	}

	if (dq.size() > N) {
		cout << -1;
		return 0;
	}

	int ones = N - dq.size();
	int first = dq.front();
	dq.pop_front();

	for (i = 0; i < ones; i++) {
		dq.push_front(1);
	}

	dq.push_front(first);

	while (!dq.empty()) {
		cout << dq.front() << ' ';
		dq.pop_front();
	}
	return 0;
}
