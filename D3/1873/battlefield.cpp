#include <iostream>
#include <cstring>

using namespace std;

/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AV5LyE7KD2ADFAXc&categoryId=AV5LyE7KD2ADFAXc&categoryType=CODE&problemTitle=&orderBy=INQUERY_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=3
*/
int main(void)
{
	int T;
	cin >> T;

	int H, W;
	char map[20][20];
	int tank_h;
	int tank_w;
	int order;
	char action;
	for (int test_case = 1;test_case <= T;test_case++)
	{
		cin >> H >> W;
		memset(map, '0', sizeof(map));
		for (int i = 0;i < H;i++)
			for (int j = 0;j < W;j++) {
				cin >> map[i][j];
				if (map[i][j] == '^' || map[i][j] == '<' || map[i][j] == '>' || map[i][j] == 'v')
				{
					tank_h = i;
					tank_w = j;
				}
			}
		cin >> order;

		for (int i = 0;i < order;i++)
		{
			cin >> action;
			if (action == 'U')
			{
				if (map[tank_h - 1][tank_w] == '.')
				{
					map[tank_h - 1][tank_w] = '^';
					map[tank_h][tank_w] = '.';
					tank_h -= 1;
				}
				else
				{
					map[tank_h][tank_w] = '^';
				}
			}
			else if (action == 'D')
			{
				if (map[tank_h + 1][tank_w] == '.')
				{
					map[tank_h + 1][tank_w] = 'v';
					map[tank_h][tank_w] = '.';
					tank_h += 1;
				}
				else
					map[tank_h][tank_w] = 'v';
			}
			else if (action == 'L')
			{
				if (map[tank_h][tank_w-1] == '.')
				{
					map[tank_h][tank_w-1] = '<';
					map[tank_h][tank_w] = '.';
					tank_w -= 1;
				}
				else
					map[tank_h][tank_w] = '<';
			}
			else if (action == 'R')
			{
				if (map[tank_h][tank_w + 1] == '.')
				{
					map[tank_h][tank_w + 1] = '>';
					map[tank_h][tank_w] = '.';
					tank_w += 1;
				}
				else
					map[tank_h][tank_w] = '>';
			
			}
			else if (action == 'S')
			{
				if (map[tank_h][tank_w] == '^')
				{
					for (int i = tank_h - 1;i >= 0;i--)
					{
						if (map[i][tank_w] == '*') {
							map[i][tank_w] = '.';
							break;
						}
						else if (map[i][tank_w] == '#')
							break;
					}
				}
				else if (map[tank_h][tank_w] == 'v')
				{
					for (int i = tank_h + 1;i < H;i++)
					{
						if (map[i][tank_w] == '*') {
							map[i][tank_w] = '.';
							break;
						}
						else if (map[i][tank_w] == '#')
							break;
					}
				}
				else if (map[tank_h][tank_w] == '>')
				{
					for (int j = tank_w + 1;j < W;j++)
					{
						if (map[tank_h][j] == '*') {
							map[tank_h][j] = '.';
							break;
						}
						else if (map[tank_h][j] == '#')
							break;
					}
				}
				else if (map[tank_h][tank_w] == '<')
				{
					for (int j = tank_w-1;j >=0;j--)
					{
						if (map[tank_h][j] == '*') {
							map[tank_h][j] = '.';
							break;
						}
						else if (map[tank_h][j] == '#')
							break;
					}
				}
			}
		}
		cout << "#" << test_case << " ";
		for (int i = 0;i < H;i++) {
			for (int j = 0;j < W;j++)
				cout << map[i][j];
			cout << endl;
		}
	}
	return 0;
}
