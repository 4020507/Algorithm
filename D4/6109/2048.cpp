#include <iostream>

using namespace std;

int main(void)
{
	int T;
	cin >> T;

	int map[20][20];
	int N;
	string push;
	for (int test_case = 1; test_case <= T;test_case++)
	{
		cin >> N >> push;

		int answer[20][20] = { 0, };
		for (int i = 0;i < N;i++)
			for (int j = 0;j < N;j++)
				cin >> map[i][j];
		if (push == "up")
		{
			for (int j = 0;j < N;j++)
			{
				int value = 0;
				int index = 0;
				for (int i = 0;i < N;i++)
				{
					if (value == 0)
						value = map[i][j];
					else if (map[i][j] == value)
					{
						answer[index][j] = value * 2;
						index++;
						value = 0;
					}
					else
					{
						if (map[i][j] != 0)
						{
							answer[index][j] = value;
							index++;
							value = map[i][j];
						}
					}
					if (i == N - 1)
						answer[index][j] = value;
				}
			}
		}
		else if (push == "down")
		{
			for (int j = 0;j < N;j++)
			{
				int value = 0;
				int index = N - 1;
				for (int i = N - 1;i >= 0;i--)
				{
					if (value == 0)
						value = map[i][j];
					else if (value == map[i][j])
					{
						answer[index][j] = value * 2;
						index--;
						value = 0;
					}
					else {
						if (map[i][j] != 0)
						{
							answer[index][j] = value;
							index--;
							value = map[i][j];
						}
					}
					if (i == 0)
						answer[index][j] = value;
				}
			}
		}
		else if (push == "left")
		{
			for (int i = 0;i < N;i++)
			{
				int value = 0;
				int index = 0;
				for (int j = 0;j < N;j++) {
					if (value == 0)
					{
						value = map[i][j];
					}
					else if (value == map[i][j])
					{
						answer[i][index] = value * 2;
						index++;
						value = 0;
					}
					else {
						if (map[i][j] != 0)
						{
							answer[i][index] = value;
							index++;
							value = map[i][j];
						}
					}
					if (j == N - 1)
						answer[i][index] = value;
				}
				
			}
		}
		else if (push == "right")
		{
			for (int i = 0;i < N;i++) {
				int value = 0;
				int index = N - 1;
				for (int j = N - 1;j >= 0;j--)
				{
					if (value == 0)
						value = map[i][j];
					else if (value == map[i][j])
					{
						answer[i][index] = value * 2;
						index--;
						value = 0;
					}
					else
					{
						if (map[i][j] != 0)
						{
							answer[i][index] = value;
							index--;
							value = map[i][j];
						}
					}
					if (j == 0)
						answer[i][index] = value;
				}
			}
		}
		cout << "#" << test_case << endl;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++)
				cout << answer[i][j] << " ";
			cout << endl;
		}
	}
}
