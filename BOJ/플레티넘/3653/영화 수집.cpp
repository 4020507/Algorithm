#include<iostream>
#include<vector>
#include<math.h>
#pragma warning(disable:4996)

#define INF 100000

using namespace std;

int arr[INF * 2 + 1];
int loc[INF];

long long init(vector<long long>& tree, int node, int start, int end) {

	if (start == end) {
		return tree[node] = arr[start];
	}

	return tree[node] = init(tree, node * 2, start, (start + end) / 2) + init(tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

long long sum(vector<long long>& tree, int node, int start, int end, int left, int right) {

	if (left > end || right < start) {
		return 0;
	}

	if (left <= start && end <= right) {
		return tree[node];
	}

	return sum(tree, node * 2, start, (start + end)/2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector<long long>& tree, int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) {
		return;
	}

	tree[node] += diff;

	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T, i, n, m, curr, next, num;

	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> n >> m;

		for (i = 0; i <= n + m; i++)
			arr[i] = 0;

		for (i = 1; i <= n; i++) {
			arr[i] = 1;
			loc[i] = n - i + 1;
		}

		int size = ceil(log2(n + m)) + 1;
		size = (1 << size);

		vector<long long> tree(size);
		init(tree, 1, 1, n + m);

		for (i = 1; i <= m; i++) {
			cin >> num;

			curr = loc[num];
			next = i + n;
			loc[num] = next;

			update(tree, 1, 1, n + m, curr, -1);
			update(tree, 1, 1, n + m, next, 1);

			cout << sum(tree, 1, 1, n + m, curr, next - 1) << ' ';
		}

		cout << '\n';
	}

	return 0;
}
