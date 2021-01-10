#include <iostream>
#include <cstring>
#include <stdio.h>
#include <math.h>

using namespace std;

/*
You can build a building in the land.
The size of land is at most 1000, you are not building at first two places and last two places.
It means that you can build buildings between 2 to 998 if the size is 1000
Count the number of households that can have a view.
Let's say that the households have a view when both sides have a view around distance two.
For example, __'3''5''2''4''10__
The number indicates the height of the building
There is only one household that has a view in the height 5 building, since the highest building around distance two is 4.
6 households have a view in the height 10 building, becuase the highest building is 4.
Therefore, the answer is 7 households have a view in this land
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV134DPqAA8CFAYh
*/

int main(void)
{
	int building[1000];
	int num;

	for (int test_case = 1; test_case <= 10;test_case++)
	{
		cin >> num;//size of land
		for (int i = 0;i < num;i++)
			scanf("%d", &building[i]);//input the height

		int count = 0;

		for (int i = 2;i < num - 2;i++)
		{
			if (building[i] > building[i - 2] && //if the 'i'th building is highest near here
				building[i] > building[i - 1] &&
				building[i] > building[i+1] &&
				building[i] > building[i+2]) {
				int height = max(building[i - 2], max(building[i - 1], max(building[i + 1], building[i + 2])));//pick the highest building
				count += building[i] - height;//count number of household having a view
			}
		}

		cout << "#" << test_case << " " << count << endl;
	}
}
