#include<iostream>
#include<algorithm>
#include<string.h>

#pragma warning(disable:4996)
using namespace std;
int r, c;
char board[20][20];

class coins
{
public:
	int x1;
	int y1;
	int x2;
	int y2;

	bool operator<(const coins& rhs) const {
		return x1 < rhs.x1;

	}
};

coins coin;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int ans;

void move(int count)
{
	if (count > 10)
		return;

	int remains = 0;
	
	if (coin.x1 < 0 || coin.x1 >= r || coin.y1 < 0 || coin.y1 >= c)
	{
		remains++;
	}

	if (coin.x2 < 0 || coin.x2 >= r || coin.y2 < 0 || coin.y2 >= c)
	{
		remains++;
	}

	if (remains == 1)
	{
		ans = min(ans, count);
		return;
	}

	if (remains == 2)
		return;

	bool check[2];
	int change[4];
	memset(check, false, sizeof(check));
	for (int i = 0;i < 4;i++)
	{
		change[0] = coin.x1 + dx[i];
		change[1] = coin.y1 + dy[i];
		change[2] = coin.x2 + dx[i];
		change[3] = coin.y2 + dy[i];
		
		if (change[0] >= 0 && change[0] < r && change[1] >= 0 && change[1] < c)
		{
			if (board[change[0]][change[1]] != '#')
			{
				coin.x1 = change[0];
				coin.y1 = change[1];
				check[0] = true;
			}
		}
		else
		{
			coin.x1 = change[0];
			coin.y1 = change[1];
			check[0] = true;
		}

		if (change[2] >= 0 && change[2] < r && change[3] >= 0 && change[3] < c)
		{
			if (board[change[2]][change[3]] != '#')
			{
				coin.x2 = change[2];
				coin.y2 = change[3];
				check[1] = true;
			}
		}
		else
		{
			coin.x2 = change[2];
			coin.y2 = change[3];
			check[1] = true;
		}

		if(check[0] || check[1])
			move(count + 1);

		if (check[0]) {
			coin.x1 -= dx[i];
			coin.y1 -= dy[i];
			check[0] = false;
		}

		if (check[1]) {
			coin.x2 -= dx[i];
			coin.y2 -= dy[i];
			check[1] = false;
		}

	}
}
int main(int argc, char** argv)
{
	cin >> r >> c;
	int count = 0;


	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < c;j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'o')
			{
				if (count == 0)
				{
					coin.x1 = i;
					coin.y1 = j;
					count++;
				}
				else
				{
					coin.x2 = i;
					coin.y2 = j;
				}
			}
		}
	}
	ans = 1e9;
	move(0);

	if (ans == 1e9)
		cout << -1;
	else
		cout << ans;
	return 0;
}
