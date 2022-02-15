#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int count = 0;
bool visited[20];
int result;

void dfs(int curr, int count, vector <int> v[])
{
	if (count > result)
		result = count;

	visited[curr] = true;

	for (int i = 0;i < v[curr].size();i++)
	{
		int next = v[curr][i];
		if (!visited[next])
			dfs(next, count + 1, v);
			
	}
	visited[curr] = false;
}
int main(void)
{
	int T;
	cin >> T;

	int N;
	int M;
	int a;
	int b;
	for (int test_case = 1;test_case <= T;test_case++)
	{
		cin >> N >> M;

		vector<int> v[20];
		result = 0;
		
		for (int i = 0;i < M;i++)
		{
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int k = 1;k <= N;k++) {
			memset(visited, false, sizeof(visited));
			dfs(k, 1, v);
		}

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;
}
