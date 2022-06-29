#include<iostream>

#pragma warning(disable:4996)
using namespace std;

int N, K;
int dp[1001][100001];
int value[1001][2];

int main(int argc, char** argv)
{
    cin >> N >> K;
    
    for (int i = 1;i <= N;i++) {
        cin >> value[i][0] >> value[i][1];
    }

    for (int i = 1;i <= N;i++)
    {
        for (int j = 1;j <= K;j++)
        {
            if (j >= value[i][0])
                dp[i][j] = max(dp[i-1][j], dp[i - 1][j - value[i][0]] + value[i][1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout<<dp[N][K];
    
    return 0;
}
