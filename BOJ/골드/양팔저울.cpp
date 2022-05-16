#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
using namespace std;

int weight[30];
int dp[31][15000];
int marbles[7];
int N, M;

void DP(int n, int w) {
    if (N < n || dp[n][w])
        return;
    dp[n][w] = true;

    DP(n + 1, w + weight[n]);
    DP(n + 1, (abs(w - weight[n])));
    DP(n + 1, w);

}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> weight[i];

    memset(dp, false, sizeof(dp));

    DP(0, 0);

    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> marbles[i];

        if (marbles[i] > 15000 || !dp[N][marbles[i]])
            cout << 'N' << ' ';
        else if (dp[N][marbles[i]])
            cout << 'Y' << ' ';
        else
            cout << 'N' << ' ';
    }

    return 0;

}
