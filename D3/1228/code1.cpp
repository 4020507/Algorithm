#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14w-rKAHACFAYD&categoryId=AV14w-rKAHACFAYD&categoryType=CODE
*/
int main(void)
{
	int N;
	int code[20];
	int temp[10];
	int temp2[10];
	for (int test_case = 1;test_case <= 10;test_case++)
	{
		scanf("%d", &N);
		for (int i = 0;i < N;i++)
			scanf("%d", &code[i]);
		
		int count;
		string order;
		int place;
		int size;

		scanf("%d", &count);
		memset(temp2, 0, sizeof(temp2));
		for (int i = 0;i < count;i++)
		{
			cin >> order >> place >> size;
			for (int j = 0;j < size;j++)
				scanf("%d", &temp[j]);
			if (place > 9)
				continue;

			int temp2_size = 0;
			for (int k = place;k < 10;k++) {
				temp2[temp2_size] = code[k];
				temp2_size++;
			}
			int temp_curr = 0;
			for (int k = place;k < size + place && k<10;k++)
			{
				code[k] = temp[temp_curr];
				temp_curr++;
			}
			int curr = 0;
			for (int i = size + place;i < 10;i++)
				if (curr < temp2_size) {
					code[i] = temp2[curr];
					curr++;
				}
				else
					break;
		}

		cout << "#" << test_case << " ";
		for (int i = 0;i < 10;i++)
			cout << code[i] << " ";
		cout << endl;
	}
}
