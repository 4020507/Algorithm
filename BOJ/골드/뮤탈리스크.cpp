#include<iostream>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;

int SCV[61][61][61];
int input[3];
int dx[6] = { 1,1,3,3,9,9 };
int dy[6] = { 3,9,1,9,3,1 };
int dz[6] = { 9,3,9,1,1,3 };

int check(int a)
{
	if (a < 0)
		return 0;
	else
		return a;
}
int dfs(int a, int b, int c)
{
	int& result = SCV[a][b][c];
	if (result != -1)
	{
		return SCV[a][b][c];
	}
	if (a <= 0 && b <= 0 && c <= 0)
		return 0;
	
	result = 1e9;
	for (int i = 0;i < 6;i++)
	{
		result = min(result, 1 + dfs(check(a - dx[i]), check(b - dy[i]), check(c - dz[i])));
	}

	return result;
}
int main(int argc, char** argv)
{
	int n;

	cin >> n;
	memset(SCV, -1, sizeof(SCV));
	
	for (int i = 0;i < n;i++)
		cin >> input[i];
	cout << dfs(input[0], input[1], input[2]);

}
