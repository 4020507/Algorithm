#include<iostream>
#include<string.h>
#include<queue>

#pragma warning(disable:4996)

#define INF 1e9

using namespace std;

bool visited[1501][1501];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int A, B, C;

	cin >> A >> B >> C;

	if ((A + B + C) % 3 != 0) {
		cout << 0;
		return 0;
	}
	int sum = A + B + C;

	memset(visited, false, sizeof(visited));

	queue<pair<int, int>> q;

	q.push({ A,B });
	visited[A][B] = true;
	int num[3];

	int i, j;
	int a, b;
	while (!q.empty()) {
		a = q.front().first;
		b = q.front().second;

		q.pop();

		num[0] = a;
		num[1] = b;
		num[2] = sum - a - b;

		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if (num[i] < num[j]) {
					a = num[i] * 2;
					b = num[j] - num[i];

					if (!visited[a][b]) {
						visited[a][b] = true;
						q.push({ a,b });
					}
				}
			}
		}
	}
	
	cout << visited[sum / 3][sum / 3];

	return 0;
}
