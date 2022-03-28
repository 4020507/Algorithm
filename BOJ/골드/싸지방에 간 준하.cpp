#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;

int N;
int computers[100001];
bool filled[100001];
pair<int, int > range[100001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin >> N;
	int a, b;
	int i;
	for (i = 0;i < N;i++) {
		cin >> a >> b;
		range[i].first = a;
		range[i].second = b;
	}

	sort(range, range + N);
	priority_queue<pair<int,int>> pq;
	i = 1;
	int start;
	int curr;
	pq.push({ -range[0].second,1 });
	curr = range[0].second;
	memset(filled, false, sizeof(filled));
	computers[1]++;
	filled[1] = true;
	int used = 1;
	int j;
	while (i < N) {
		start = range[i].first;

		if (pq.empty())
			curr = 1e9;
		else
			curr = -pq.top().first;
		if (start < curr) {
			for (j = 1;j <= 100000;j++) {
				if (!filled[j]) {
					filled[j] = true;
					computers[j]++;
					pq.push({ -range[i].second,j });
					break;
				}
			}
		}
		else {
			while (start >= curr) {
				filled[pq.top().second] = false;
				pq.pop();

				if (pq.empty())
					break;
				curr = -pq.top().first;
			}

			for (j = 1;j <= 100000;j++) {
				if (!filled[j]) {
					filled[j] = true;
					computers[j]++;
					pq.push({ -range[i].second,j });
					break;
				}
			}
		}
		used = used < j ? j : used;
		i++;
	}

	cout << used << '\n';

	for (i = 1;i <= used;i++) {
		cout << computers[i] << ' ';
	}
	return 0;
}
