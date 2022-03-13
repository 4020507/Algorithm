#include<iostream>
#include<algorithm>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;

int n, m;
int names[1001];
int dp[1001][1001];

int notes(int row, int col)
{
    if (row >= n)
        return 0;
    int& res = dp[row][col];

    if (res != -1)
        return res;

    res = (m - col + 1) * (m - col + 1) + notes(row + 1, names[row] + 1);

    if (col + names[row] <= m)
        res = min(res, notes(row + 1, col + names[row] + 1));

    return res;
}
int main(int argc, char** argv)
{
    cin >> n >> m;

    for (int i = 0;i < n;i++)
        cin >> names[i];
    memset(dp, -1, sizeof(dp));
    cout << notes(0, 0) << endl;

    return 0;
}
