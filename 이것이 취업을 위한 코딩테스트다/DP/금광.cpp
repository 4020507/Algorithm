#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
using namespace std;

int N, M, T;
int gold[20][20];

int main(void) {

    cin >> T;

    for (int k = 0;k < T;k++)
    {
        cin >> N >> M;

        memset(gold, 0, sizeof(gold));
        for (int i = 1;i <= N;i++)
        {
            for (int j = 1;j <= M;j++)
            {
                cin >> gold[i][j];
            }
        }

        int dp[20][20];
        memset(dp, 0, sizeof(dp));

        for (int i = 1;i <= M;i++)
        {
            for (int j = 1;j <= N;j++)
            {
                dp[j][i] = max(dp[j][i], max(dp[j][i - 1] + gold[j][i], max(dp[j + 1][i - 1] + gold[j][i], dp[j - 1][i - 1] + gold[j][i])));
            }
        }

        int maxi = 0;

        for (int i = 1;i <= N;i++)
        {
            maxi = max(maxi, dp[i][M]);
        }

        cout << maxi << endl;
    }
    

    return 0;
    
}
