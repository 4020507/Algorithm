#include<iostream>
#include<string.h>

using namespace std;

int nextNode[100001];
bool visited1[100001];
bool visited2[100001];
int n;
int cnt;

void dfs(int node)
{
	visited1[node] = true;
	int next = nextNode[node];
	if (!visited1[next])
		dfs(next);
	else if (!visited2[next])
	{
		for (int i = next;i != node;i = nextNode[i])
			cnt++;
		cnt++;
	}
	visited2[node] = true;
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;

	for (int test_case = 1;test_case <= T;test_case++)
	{
		memset(visited1, false, sizeof(visited1));
		memset(visited2, false, sizeof(visited2));
		cin >> n;
		cnt = 0;

		int node;

		for (int i = 1;i <= n;i++)
		{
			cin >> node;
			nextNode[i] = node;
		}

		for (int i = 1;i <= n;i++)
		{
			if (!visited1[i])
				dfs(i);
		}
		cout << n - cnt << endl;
	}
	return 0;
}
