#include<iostream>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 }; //위, 왼, 아래, 오

class coordinates
{
public:
	int x;
	int y;
};
int main(int argc, char** argv)
{
	int T;
	cin >> T;
	string s;
	for (int test_case = 1;test_case <= T;test_case++)
	{
		cin >> s;
		int min_x = 0;
		int min_y = 0;
		int max_x = 0;
		int max_y = 0;

		int len = s.length();
		int pos = 0;
		coordinates c;
		c.x = 0;
		c.y = 0;

		for (int i = 0;i < len;i++)
		{
			if (s[i] == 'L')
			{
				pos--;
				if (pos == -1)
					pos = 3;
			}
			else if (s[i] == 'R')
			{
				pos = (++pos) % 4;
			}
			else if (s[i] == 'F')
			{
				c.x += dx[pos];
				c.y += dy[pos];
			}
			else if (s[i] == 'B')
			{
				c.x -= dx[pos];
				c.y -= dy[pos];
			}
			min_x = min(min_x, c.x);
			min_y = min(min_y, c.y);
			max_x = max(max_x, c.x);
			max_y = max(max_y, c.y);
		}

		cout << (max_x - min_x) * (max_y - min_y) << '\n';
	}
	return 0;
}
