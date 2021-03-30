#include <iostream>
#include <cstring>
using namespace std;

int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
int dy[8] = { 1,-1,0,1,-1,1,0,-1 };
int main(void)
{
	int T;
	cin >> T;

	int N;
	int M;
	int map[8][8];
	int a, b, p;

	for (int test_case = 1;test_case <= T;test_case++)
	{
		cin >> N >> M;
		memset(map, 0, sizeof(map));
		map[N / 2 - 1][N / 2 - 1] = 2;
		map[N / 2 - 1][N / 2] = 1;
		map[N / 2][N / 2 - 1] = 1;
		map[N / 2][N / 2] = 2;

		for (int i = 0;i < M;i++)
		{
			cin >> b>> a>>p;
			map[a - 1][b - 1] = p;
			a--;
			b--;
			for (int i = 0;i < 8;i++)
			{
				bool flag = false;
				for (int j = 1;j < 8;j++) {
					int c = a + dx[i] * j;
					int d = b + dy[i] * j;

					if (c < 0 || c >= N || d < 0 || d >= N || map[c][d] == 0 || (map[c][d] == p && !flag))
						break;
					if (map[c][d] != 0 && map[c][d] != p)
						flag = true;
					if (map[c][d] == p)
					{
						while (1)
						{
							if (a == c && b == d) break;
							c = c - dx[i];
							d = d - dy[i];
							map[c][d] = p;
						}
						break;
					}
				}
			}
		}
		int black = 0;
		int white = 0;
		for(int i = 0;i<N;i++)
			for (int j = 0;j < N;j++)
			{
				if (map[i][j] == 2)
					white++;
				else if (map[i][j] == 1)
					black++;
			}
		cout << "#" << test_case << " " << black << " " << white << endl;
		
	}
	return 0;

}
