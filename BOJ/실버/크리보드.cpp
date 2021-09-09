#include<iostream>
#include<string.h>

#pragma warning(disable:4996)
using namespace std;

int N;
long long dp[101];
int main(int argc, char** argv)
{
    cin >> N;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 5;

    for (int i = 6;i <= N;i++)
    {
        dp[i] = i;
        for (int j = 1;j <= i - 3;j++)
        {
            dp[i] = max(dp[i], dp[j] * (i - j - 1));
        }
    }

    cout << dp[N];
    return 0;
}
