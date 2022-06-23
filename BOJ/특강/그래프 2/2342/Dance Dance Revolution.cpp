#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <math.h>
using namespace std;
int dp[5][5][100001];
int cnt;
vector<int> v;

int cal(int a, int b) {
	if (a == 0 || b == 0) return 2;

	int dif = abs(a - b);
	if (dif == 0) return 1;
	else if (dif == 1 || dif == 3) return 3;
	else if (dif == 2) return 4;
}

int dfs(int left, int right, int idx) {
	if (idx == cnt) return 0;
	if (dp[left][right][idx] != -1) return dp[left][right][idx];
	int tmpLeft = dfs(v[idx], right, idx + 1) + cal(v[idx], left);
	int tmpRight = dfs(left, v[idx], idx + 1) + cal(v[idx], right);
	return dp[left][right][idx] = min(tmpLeft, tmpRight);
}

int main()
{
	int num;
	while (true) {
		cin >> num;
		if (num == 0) break;
		v.push_back(num);
	}
	memset(dp, -1, sizeof(dp));
	cnt = v.size();
	cout << dfs(0,0,0);
}
