#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1001
int matrix[MAX][MAX];
int dp[MAX][MAX];
int main(void)
{
    int n, m;
    cin >> n >> m;

    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
            scanf("%1d", &matrix[i][j]);
    }
    int cnt = 0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
        {
            if (matrix[i][j] == 1)
            {
                dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
                cnt = max(cnt, dp[i][j] * dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }

    cout << cnt;
    return 0;

}
