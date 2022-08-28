#include<iostream>
#include<queue>
#include<string>
#include<string.h>
#pragma warning(disable:4996)

#define INF 100000

using namespace std;

bool used[201][201];

string s1, s2, s3;

void bfs() {

	memset(used, false, sizeof(used));

	queue<pair<int, pair<int,int>>>q;

	q.push({ 0,{0,0} });
	used[0][0] = true;

	int index, a, b;
	int len = s3.size();

	while (!q.empty()) {

		index = q.front().first;
		a = q.front().second.first;
		b = q.front().second.second;

		q.pop();

		if (index == len)
			return;

		if (s3[index] == s1[a] && !used[a+1][b]) {

			q.push({ index + 1,{a + 1,b} });
			used[a + 1][b] = true;
		}

		if (s3[index] == s2[b] && !used[a][b + 1]) {
			q.push({ index + 1,{a,b + 1} });
			used[a][b + 1] = true;
		}
	}
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;

	cin >> T;

	
	for (int i = 1; i <= T; i++) {

		cin >> s1 >> s2 >> s3;

		bfs();

		cout << "Data set " << i << ": ";

		if (used[s1.size()][s2.size()]) {
			cout<<"yes";
		}
		else {
			cout<<"no";
		}

		cout << '\n';
	}

	return 0;
}
