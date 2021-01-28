#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
int N;
int count;
int weight[20];
bool visited[20];
int val;
int factorial[] = { 0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
int exponential[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=4&contestProbId=AWAe7XSKfUUDFAUw&categoryId=AWAe7XSKfUUDFAUw&categoryType=CODE&problemTitle=&orderBy=INQUERY_COUNT&selectCodeLang=ALL&select-1=4&pageSize=10&pageIndex=3
*/
void dfs(int curr,int left,int right)
{
	if (curr == N)
	{
		count++;
		return;
	}
	if (left >= val - left)
	{
		count += factorial[N - curr] * exponential[N - curr];
		return;

	}
	for (int i = 0;i < N;i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			dfs(curr + 1, left + weight[i], right);
			if (left >= right + weight[i])
			{
				dfs(curr + 1, left, right + weight[i]);
			}
			visited[i] = false;
		}
	}
}
int main(void)
{
	int T;
	cin >> T;

	for (int test_case = 1;test_case <= T;test_case++)
	{
		cin >> N;
		memset(visited, false, sizeof(visited));
		count = 0;
		val = 0;

		for (int i = 0;i < N;i++) {
			cin >> weight[i];
			val += weight[i];
		}
		dfs(0,0,0);

		cout << "#" << test_case << " " << count << endl;
	}
}
