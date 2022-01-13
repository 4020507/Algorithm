#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

#define MAX 1025

int matrix[MAX][MAX];
int dp[MAX][MAX];

int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;

    for (int i = 1;i <= N;i++) {
        for (int j = 1;j <= N;j++) {
            cin >> matrix[i][j];

            dp[i][j] = dp[i][j - 1] + dp[i - 1][j] + matrix[i][j] - dp[i - 1][j - 1];
        }
    }

    int x1, x2, y1, y2;

    for (int i = 0;i < M;i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        cout << dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1] << '\n';
    }
    
    return 0;

}
