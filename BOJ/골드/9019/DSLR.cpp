#include<iostream>
#include<string>
#include<string.h>
#include<queue>
#pragma warning(disable:4996)

using namespace std;

bool check[10000];


int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	int T;

	cin >> T;

	int A, B;
	string s;
	int temp;

	for (int t = 0; t < T; t++) {
		cin >> A >> B;

		memset(check, false, sizeof(check));

		queue<pair<int, string>> q;
		q.push({ A,"" });
		check[A] = true;

		while (!q.empty()) {
			A = q.front().first;
			s = q.front().second;

			q.pop();

			if (A == B) {
				cout << s << '\n';
				break;
			}

			temp = A * 2;

			if (temp > 9999) {
				temp %= 10000;
			}

			if (!check[temp]) {
				check[temp] = true;
				q.push({ temp,s + "D" });
			}

			temp = A - 1;
			
			if (temp < 0) {
				temp = 9999;
			}

			if (!check[temp]) {
				check[temp] = true;
				q.push({ temp,s + "S" });
			}

			temp = (A % 1000) * 10 + (A / 1000);

			if (!check[temp]) {
				check[temp] = true;
				q.push({ temp,s + "L" });
			}

			temp = A / 10 + A % 10 * 1000;

			if (!check[temp]) {
				check[temp] = true;
				q.push({ temp,s + "R" });
			}
		}
	}
	return 0;
}
