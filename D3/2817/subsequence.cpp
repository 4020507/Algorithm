#include <iostream>
#include <cstring>


using namespace std;

int ans;
bool visited[20];
int N;
int K;
int num[20];

void dfs(int curr, int temp)
{
	if (temp == K)
	{
		ans++;
		return;
	}
	if (temp > K)
		return;

	for (int i = curr + 1;i < N;i++)
	{
			dfs(i, temp + num[i]);
	}
}
int main(void)
{
	int T;
	cin >> T;

	
	
	for (int test_case = 1;test_case <= T;test_case++)
	{
		cin >> N >> K;
		ans = 0;
		memset(visited, false, sizeof(visited));

		for (int i = 0;i < N;i++)
			cin >> num[i];
		dfs(-1, 0);

		cout << "#" << test_case << " " << ans << endl;
	}

	return 0;
}
