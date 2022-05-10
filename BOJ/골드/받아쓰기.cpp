#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
string s1, s2;

bool scribbling(char a, char b) {
    if (a == b)
        return true;
    if (a == 'i' && (b == 'i' || b == 'j' || b == 'l'))
        return true;
    if (a == 'v' && (b == 'v' || b == 'w'))
        return true;
    return false;
}
int getAnswer() {
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

    int i, j;

    for (i = 1; i <= N; i++)
        dp[i][0] = i;

    for (j = 1; j <= M; j++)
        dp[0][j] = j;

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= M; j++) {
            if (scribbling(s1[i - 1], s2[j - 1]))
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    }

    return dp[N][M];
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N >> M;

    cin >> s1 >> s2;

    cout << getAnswer();

    return 0;

}
