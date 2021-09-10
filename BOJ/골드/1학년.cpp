#include<iostream>

#pragma warning(disable:4996)
using namespace std;

int N;
long long dp[101][21];
int nums[101];
int main(int argc, char** argv)
{
    cin >> N;
    
    for (int i = 1;i <= N;i++)
        cin >> nums[i];

    int ans = 0;
    dp[1][nums[1]] = 1;

 for (int i = 2;i <= N - 1;i++)
    {
        for (int j = 0;j <= 20;j++)
        {
            if (dp[i - 1][j] > 0)
            {
                if (j + nums[i] <= 20)
                {
                    dp[i][nums[i] + j] += dp[i-1][j];
                    
                }

                if (j - nums[i] >= 0)
                {
                    dp[i][j - nums[i]] += dp[i-1][j];

                }
            }
            
        }
    }
    
    cout << dp[N-1][nums[N]];

    return 0;
}
