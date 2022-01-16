#include<iostream>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;

int N;
int dp[1500000];
int wage[1500000][2];
int main(int argc, char** argv)
{
    cin >> N;

    for (int i = 0;i < N;i++)
    {
        cin >> wage[i][0] >> wage[i][1];
    }

    int maxi = 0;
    memset(dp, 0, sizeof(dp));
    for (int i = 0;i <= N;i++)
    {
        maxi = max(maxi, dp[i]);
        if (i + wage[i][0] < N + 1)
        {
            dp[i + wage[i][0]] = max(maxi + wage[i][1], dp[i + wage[i][0]]);
        }
    }

    cout << maxi;

    return 0;
}
