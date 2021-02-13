#include <iostream>
#include <cstring>
using namespace std;

bool visited[1000][1000];
int dx[4] = { 0,0,2,-2 };
int dy[4] = { 2,-2,0,0 };
int main(void)
{
	int T;
	cin >> T;

	int N, M;
	int a, b,ans;
	for (int test_case = 1;test_case <= T;test_case++)
	{
		cin >> M >> N;
		memset(visited, false, sizeof(visited));
		ans = 0;
		for (int i = 0;i < N;i++)
		{
			
			for (int j = 0;j < M;j++)
			{
				bool check = false;
				for (int k = 0;k < 4;k++)
				{
					a = i + dx[k];
					b = j + dy[k];

					if (a >= 0 && a < N && b >= 0 && b < M)
					{
						if (visited[a][b])
						{
							check = true;
							break;
						}
					}
				}
				if (!check)
				{
					visited[i][j] = true;
					ans++;
				}
			}
		}
		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;
}
