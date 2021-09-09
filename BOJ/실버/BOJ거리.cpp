#include<iostream>
#include<string.h>

#pragma warning(disable:4996)
using namespace std;

int N;
int dp[1001];
char boj[1001];
int main(int argc, char** argv)
{
    cin >> N;
    
    for (int i = 0;i < N;i++)
        cin >> boj[i];

    fill(dp, dp + 1001, 1e9);
    dp[0] = 0;
    for (int i = 0;i < N;i++)
    {
        for (int j = i+1;j < N;j++)
        {
            if (boj[i] == 'B' && boj[j] == 'O')
            {
                dp[j] = min(dp[j], dp[i] + (j - i) * (j - i));
            }
            else if (boj[i] == 'O' && boj[j] == 'J')
            {
                dp[j] = min(dp[j], dp[i] + (j - i) * (j - i));
            }
            else if (boj[i] == 'J' && boj[j] == 'B')
            {
                dp[j] = min(dp[j], dp[i] + (j - i) * (j - i));
            }
        }
    }
    if (dp[N - 1] == 1e9)
        cout << -1;
    else
        cout << dp[N - 1];
    return 0;
}
