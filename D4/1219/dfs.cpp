#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

/*

https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14geLqABQCFAYD&categoryId=AV14geLqABQCFAYD&categoryType=CODE
*/
int main()
{
	bool visited[100];
	int tc;
	int num;
	int result;

	for (int test_case = 1;test_case <= 10;test_case++)
	{
		cin >> tc >> num;//tc is nothing but test_case, and num is the number of length

		memset(visited, false, sizeof(visited));
		vector<int>size[100];
		result = 0;

		for (int i = 0;i < num;i++) {
			int a;
			int b;//a is connected to b
			cin >> a >> b;
			size[a].push_back(b);
		}
		queue<int> q;
		q.push(0);
		visited[0] = true;

		while (!q.empty())
		{
			int pos = q.front();
			q.pop();
			if (pos == 99) {//find the way that is connected to 99
				result = 1;
				break;
			}
			int curr_size = size[pos].size();

			for (int i = 0;i < curr_size;i++)
			{
				int next = size[pos][i];
				if (!visited[next]) {
					visited[next] = true;
					q.push(next);
				}
			}
		}

		cout << "#" << test_case << " " << result << endl;//if the way exists, result is 1, not 0
	}
}
