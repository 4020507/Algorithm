#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

int N, M;
int dp[1000][1000];
int man[1000];
int woman[1000];

int DP(int m, int w) {

    if (m < 0)
        return 0;
    if (w < 0)
        return 1e9;

    if (dp[m][w] != -1)
        return dp[m][w];

    dp[m][w] = 1e9;

    dp[m][w] = min(dp[m][w], abs(man[m] - woman[w]) + DP(m - 1, w - 1));
    dp[m][w] = min(dp[m][w], DP(m, w - 1));

    return dp[m][w];
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    
    cin >> N >> M;

    int i;

    for (i = 0; i < N; i++)
        cin >> man[i];
    for (i = 0; i < M; i++)
        cin >> woman[i];

    sort(man, man + N);
    sort(woman, woman + M);

    if (M < N) {
        swap(man, woman);
        swap(N, M);
    }

    memset(dp, -1, sizeof(dp));

    cout << DP(N - 1, M - 1);

    return 0;

}
