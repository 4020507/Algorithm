#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
using namespace std;

int N, T;
int study[1000][2];
int score;
int dp[10001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N >> T;

    for (int i = 0; i < N; i++)
        cin >> study[i][0] >> study[i][1];

    for (int i = 0; i < N; i++) {
        for (int j = T; j >= study[i][0]; j--) {
            dp[j] = max(dp[j],dp[j - study[i][0]] + study[i][1]);
        }
    }

    cout << dp[T];

    return 0;

}
