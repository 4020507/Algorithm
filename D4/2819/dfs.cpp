#include <iostream>

using namespace std;

int map[4][4];
int visited[10000000];
int cases;

void dfs(int i, int j, int depth, int case_num) {
	if (depth == 7) {
		if (!visited[case_num]) {//increase cases if the case_num is a new number
			visited[case_num] = true;
			cases++;
		}
		return;
	}

	case_num *= 10;
	case_num += map[i][j];

	if (i + 1 < 4)
		dfs(i + 1, j, depth + 1, case_num);
	if (i - 1 >= 0)
		dfs(i - 1, j, depth + 1, case_num);
	if (j + 1 < 4)
		dfs(i, j + 1, depth + 1, case_num);
	if (j - 1 >= 0)
		dfs(i, j - 1, depth + 1, case_num);
}

int main(void)
{
	int T;
	cin >> T;//input the number of cases wants to test

	for (int tcn = 1;tcn <= T;tcn++) {
		cases = 0;
		for (int i = 0;i < 10000000;i++)//initialize cases and visited
			visited[i] = false;
		for (int i = 0;i < 4;i++)
			for (int j = 0;j < 4;j++)//input random numbers between 0 to 9
				cin >> map[i][j];
		for (int i = 0;i < 4;i++)
			for (int j = 0;j < 4;j++)
				dfs(i, j, 0, 0);
		cout << "#" << tcn << " " << cases << endl;
	}

	return 0;
}
