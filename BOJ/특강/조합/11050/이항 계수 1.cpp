#pragma warning(disable:4996)
#include <iostream>

using namespace std;

int main(void)
{
    std::ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    int dp[11];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2;i <= N;i++)
        dp[i] = dp[i - 1] * i;

    cout << dp[N] / (dp[K] * dp[N - K]);
    return 0;

}
