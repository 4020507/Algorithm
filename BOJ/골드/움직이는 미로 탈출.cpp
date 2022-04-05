#include<iostream>
#include<queue>
using namespace std;

char chess[8][8];
int dx[9] = { 0,-1,1,0,-1,1,0,-1,1 };
int dy[9] = { 0,0,0,-1,-1,-1,1,1,1 };
int sharp;
void down() {
	sharp = 0;
	for (int j = 0;j < 8;j++) {
		for (int i = 7;i >= 1;i--) {
			chess[i][j] = chess[i - 1][j];

			if (chess[i][j] == '#')
				sharp++;
		}
		chess[0][j] = '.';
	}
}

bool move() {
	int x, y, nx, ny, i, seconds, curr;
	queue<pair<pair<int, int>,int>> q;
	q.push({ {7,0},0 });
	seconds = 0;
	while (!q.empty()) {
		if (sharp == 0)
			return true;
		x = q.front().first.first;
		y = q.front().first.second;
		curr = q.front().second;
		q.pop();

		if (x == 0 && y == 7)
			return true;

		if (curr > seconds) {
			down();
			seconds = curr;
		}
		for (i = 0;i < 9;i++) {
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
				if (chess[nx][ny] != '#') {
					if (nx > 0 && chess[nx - 1][ny] != '#') {
						q.push({ {nx,ny},curr+1 });
					}
					else if (nx == 0)
						q.push({ {nx,ny},curr+1 });
				}
			}
		}
	}

	return false;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	sharp = 0;
	for (int i = 0;i < 8;i++)
		for (int j = 0;j < 8;j++) {
			cin >> chess[i][j];

			if (chess[i][j] == '#')
				sharp++;
		}

	if (move())
		cout << 1;
	else
		cout << 0;
	return 0;
}
