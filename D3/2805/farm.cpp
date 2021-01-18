#include<iostream>
#include<math.h>
using namespace std;


/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7GLXqKAWYDFAXB&categoryId=AV7GLXqKAWYDFAXB&categoryType=CODE
*/
int farm[50][50];
int main(void)
{
	int T;
	cin >> T;

	int N;

	for (int test_case = 1;test_case <= T;test_case++)
	{
		cin >> N;
		int count = 0;

		while (count < N)
		{
			for (int i = 0;i < N;i++)
				scanf("%1d", &farm[count][i]);
			count++;
		}
		float center = floor(N/2);//find the center of the farm
		int init = center;
		int depth = 0;
		int profit = 0;
		int t = 1;
		while (t <= N)
		{
			for (int i = 0;i < t;i++)
				profit += farm[depth][init + i];
			t = t + 2;
			depth++;
			init--;
		}
		init = 0;
		t = t - 4;
		while (t >0)
		{
			init++;
			for (int i = 0;i < t;i++) {
				profit += farm[depth][init + i];
			}
			t = t - 2;
			depth++;
		}
		cout << "#" << test_case << " " << profit << endl;
	}
}
