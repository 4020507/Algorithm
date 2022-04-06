#pragma warning(disable:4996)
#include <iostream>

using namespace std;

#define MOD 10007
int dp[1001][1001];
int main(void)
{
    int N, K;
    cin >> N >> K;
    
    for (int i = 1;i <= N;i++)
    {
        dp[i][i] = 1;
        dp[i][1] = i;
        dp[i][0] = 1;
    }

    for (int i = 2;i <= N;i++)
    {
        for (int j = 2;j <i;j++)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i-1][j]) % MOD;
    }

    cout << dp[N][K];

    return 0;

}
