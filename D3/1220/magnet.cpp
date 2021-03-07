#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{
	setbuf(stdout, NULL);
	int map[100][100];
	int N;
	for (int test_case = 1;test_case <= 10;test_case++)
	{
		cin >> N;
		for (int i = 0;i < N;i++)
			for (int j = 0;j < N;j++)
				cin >> map[i][j];
		
		int connect = 0;

		for (int j = 0;j < N;j++) {
			int N_exist = 0;
			int identify = 0;
			for (int k = 0;k < N;k++)
			{
				if (map[k][j] == 0)
					continue;
				else if (map[k][j] == 1)
				{
					N_exist = 1;
					identify = 1;
				}
				else if (map[k][j] == 2)
				{
					if (identify != 2 && N_exist == 1)
						connect++;
					
					identify = 2;
				}
			}
		}

		cout << "#" << test_case << " " << connect << endl;
	}

	return 0;
}
