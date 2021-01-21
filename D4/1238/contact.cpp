#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15B1cKAKwCFAYD
*/
int main(void)
{
	setbuf(stdout, NULL);

	int N;
	int start;
	bool connected[101][101];
	bool visited[101];
	int answer;

	for (int test_case = 1;test_case <= 10;test_case++)
	{
		answer = 0;
		memset(connected, false, sizeof(connected));
		memset(visited, false, sizeof(visited));

		cin >> N >> start;

		int a;
		int b;

		for (int i = 0;i < N/2;i++)
		{
			cin >> a >> b;
			connected[a][b] = true;
		}

		queue<int> q;
		queue<int> possible_ans;

		q.push(start);
		visited[start] = true;

		while (!q.empty())
		{
			while (!possible_ans.empty())
				possible_ans.pop();
			
			int size = q.size();

			for (int i = 0;i < size;i++)
			{
				int front = q.front();
				for (int j = 1;j < 101;j++)
				{
					if (connected[front][j] && !visited[j])
					{
						visited[j] = true;
						q.push(j);
					}
				}
				possible_ans.push(front);
				q.pop();
			}
		}

		while (!possible_ans.empty())
		{
			int t = possible_ans.front();
			possible_ans.pop();
			if (answer < t)
				answer = t;
		}
		cout << "#" << test_case << " "<< answer << endl;
	}
}
