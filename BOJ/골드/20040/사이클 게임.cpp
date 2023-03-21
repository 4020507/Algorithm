#include<iostream>
#pragma warning(disable:4996)

using namespace std;

int N, M;
int parent[500001];

int findParent(int a) {
	if (a == parent[a]) {
		return a;
	}

	return parent[a] = findParent(parent[a]);
}

void Union(int p1, int p2) {
	p1 = findParent(p1);
	p2 = findParent(p2);

	if (p1 < p2) {
		parent[p2] = p1;
	}
	else {
		parent[p1] = p2;
	}
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	int a, b;

	int i;

	for (i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (i = 1; i <= M; i++) {
		cin >> a >> b;

		if (findParent(a) != findParent(b)) {
			Union(a, b);
		}
		else {
			cout << i;
			return 0;
		}
	}

	cout << 0;


	return 0;
}
