#pragma warning(disable:4996)
#include<iostream>

using namespace std;

char board[50][50];
int N;
int count_column()
{
	int count;
	int ans = 0;
	for (int i = 0;i < N;i++)
	{
		count = 1;
		for (int j = 0;j < N - 1;j++)
		{
			if (board[i][j] == board[i][j + 1])
				count++;
			else
			{
				ans = max(ans, count);
				count = 1;
			}
		}
		ans = max(ans, count);
	}

	return ans;
}

int count_row()
{
	int count;
	int ans = 0;

	for (int j = 0;j < N;j++)
	{
		count = 1;
		for (int i = 0;i < N - 1;i++)
		{
			if (board[i][j] == board[i + 1][j])
			{
				count++;
			}
			else
			{
				ans = max(ans, count);
				count = 1;
			}
		}
		ans = max(ans, count);
	}

	return ans;
}
int main(void)
{
	
	cin >> N;
	
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
			cin >> board[i][j];
	}

	int tmp;
	int ans = 0;
	for (int i = 0;i < N;i++)
	{
		tmp = 0;
		for (int j = 0;j < N-1;j++)
		{
			if (board[i][j] != board[i][j + 1])
			{
				swap(board[i][j], board[i][j + 1]);
				tmp = max(tmp, max(count_column(), count_row()));
				swap(board[i][j], board[i][j + 1]);
			}

			if (board[j][i] != board[j + 1][i])
			{
				swap(board[j][i], board[j + 1][i]);
				tmp = max(tmp, max(count_column(), count_row()));
				swap(board[j][i], board[j + 1][i]);
			}
		}
		ans = max(ans, tmp);
	}

	cout << ans;

	return 0;
}
