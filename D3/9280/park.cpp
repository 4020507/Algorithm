#include <iostream>
#include <cstring>
#pragma warning(disable: 4996)

/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AW9j74FacD0DFAUY&categoryId=AW9j74FacD0DFAUY&categoryType=CODE&problemTitle=&orderBy=INQUERY_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=2
*/
using namespace std;

int main(void)
{
	int T;
	cin >> T;

	int n;
	int m;
	int w_i[2000];
	int r_i[100];
	int park[100];
	int wait[2000];
	for (int test_case = 1;test_case <= T; test_case++)
	{
		cin >> n >> m;

		for (int i = 0;i < n;i++)
			cin >> r_i[i];
		for (int i = 0;i < m;i++)
			cin >> w_i[i];

		int car;
		memset(park, 0, sizeof(park));
		int full = false;
		int wait_count = 0;
		int rate = 0;
		int check = true;

		for (int i = 0;i < m * 2;i++)
		{
			scanf("%d", &car);

			if (car > 0)
			{
				if (!full) {
					for (int i = 0;i < n;i++)
					{
						if (park[i] == 0)
						{
							park[i] = car;
							break;
						}
						if (i == n-1)
							check = false;
					}
					if (check == false)
					{
						full = true;
						wait[wait_count] = car;
						wait_count++;
					}

				}
				else
				{
					wait[wait_count] = car;
					wait_count++;
				}
			}
			else if (car < 0)
			{
				check = true;
				
				for (int i = 0;i < n;i++)
				{
					if (park[i] == -car) {
						rate += r_i[i] * w_i[(-car) - 1];
						park[i] = 0;
						break;
					}
				}

				if (full)
				{
					int num = wait[0];
					for (int i = 0;i < n;i++)
					{
						if (park[i] == 0)
						{
							park[i] = num;
							break;
						}
					}
					for (int i = 1;i < wait_count;i++)
					{
						wait[i-1] = wait[i];
					}
					wait_count--;
					if(wait_count == 0)
						full = false;
				}
				
			}
		}

		cout << "#" << test_case << " " << rate << endl;
	}

	return 0;
}
