#include<iostream>
#include<queue>
#include<string.h>
#include<algorithm>
#include<queue>
#pragma warning(disable:4996)
using namespace std;

int K, M, P;
int rivers[1001][1001];
int indegree[1001];

int main(int argc, char** argv)
{
	int T;
	cin >> T;

	for (int test_case = 1;test_case <= T;test_case++)
	{
		cin >> K >> M >> P;
		memset(indegree, 0, sizeof(indegree));
		memset(rivers, 0, sizeof(rivers));
		queue<int> q;
		priority_queue<int> pq[1001];
		for (int i = 0;i < P;i++)
		{
			int A, B;
			cin >> A >> B;
			rivers[A][B] = 1;
			indegree[B]++;
		}
		int ans = 0;
		for (int i = 1;i <= M;i++)
		{
			if (indegree[i] == 0) {
				q.push(i);
				pq[i].push(1);
				ans = 1;
			}
		}
		bool visited[1001];
		memset(visited, false, sizeof(visited));

		while (!q.empty())
		{
			int a = q.front();
			q.pop();

			if (visited[a])
				continue;

			visited[a] = true;
			int count = pq[a].top();
			if (pq[a].size() > 1)
			{
				pq[a].pop();
				if (count == pq[a].top())
					count++;
			}
			for (int i = 1;i <= M;i++)
			{
				if (rivers[a][i] == 1)
				{
					indegree[i]--;
					
					if (indegree[i] == 0)
					{
						q.push(i);
					}
					pq[i].push(count);
				}
			}
			ans = max(count, ans);
		}

		cout << test_case << " " << ans << '\n';
	}
	
	return 0;
}
