#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int dp[10001];
int coins[100];
int main(int argc, char** argv)
{
    cin >> n >> k;

    fill(dp, dp + k + 1, 1e9);
    dp[0] = 0;

    for (int i = 0;i < n;i++)
        cin >> coins[i];
    sort(coins, coins + n);

    for (int i = 0;i < n;i++)
    {
        for (int j = coins[i];j <= k;j++)
        {
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }

    if (dp[k] == 1e9)
        cout << -1;
    else
        cout << dp[k];
    return 0;
}
