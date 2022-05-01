#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define MAX 1000000000
int N, M, K;
long long dp[101][101];

int main(void)
{
    scanf("%d %d %d", &N, &M, &K);

    dp[0][0] = 0;
    for (int i = 1;i <= N;i++)
        dp[i][0] = 1;
    for (int i = 1;i <= M;i++)
        dp[0][i] = 1;
    for (int i = 1;i <= N;i++)
        for (int j = 1;j <= M;j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            if (dp[i][j] > MAX)
                dp[i][j] = MAX;
        }
    
    int idx = 0;
    if (K > dp[N][M])
    {
        printf("-1");
    }
    else
    {
        int a_cnt = N;
        int z_cnt = M;

        for (int i = 0;i < N + M;i++)
        {
            int a = dp[a_cnt - 1][z_cnt];

            if (a_cnt == 0)
            {
                cout << 'z';
                z_cnt--;
            }
            else if (z_cnt == 0)
            {
                cout << 'a';
                a_cnt--;
            }
            else if (K <= a)
            {
                cout << 'a';
                a_cnt--;
            }
            else
            {
                cout << 'z';
                K -= a;
                z_cnt--;
            }
        }
    }

    return 0;

}
