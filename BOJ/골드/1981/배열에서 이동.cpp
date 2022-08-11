#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>
#pragma warning(disable:4996)

#define INF 1e9

using namespace std;
int N;
int arr[100][100];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visited[100][100];

int bfs(int minVal, int maxVal) {

	queue <pair<int,int>> q;

	memset(visited, false, sizeof(visited));

	q.push({0,0});

	visited[0][0] = true;

	int x, y, nx, ny;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;

		q.pop();

		if (x == N - 1 && y == N - 1) {
			return true;
		}

		

		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {

				if (!visited[nx][ny] && arr[nx][ny] <= maxVal && arr[nx][ny] >= minVal) {
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}

	return false;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	int maxi = 0;
	int mini = INF;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];

			if (mini > arr[i][j]) {
				mini = arr[i][j];
			}

			if (maxi < arr[i][j]) {
				maxi = arr[i][j];
			}
		}
	}
	
	
	bool returnVal;
	int diff = INF;
	int left = 0;
	int right = maxi - mini;
	int mid, i;

	while (left <= right) {
		mid = (left + right) / 2;
		returnVal = false;

		for (i = mini; i <= maxi; i++) {

			if (arr[0][0] >= i && arr[0][0] <= i + mid) {
				if (bfs(i, i + mid)) {
					returnVal = true;
					break;
				}
			}
		}

		if (returnVal) {
			diff = min(diff, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}


	cout << diff;
	return 0;
}
