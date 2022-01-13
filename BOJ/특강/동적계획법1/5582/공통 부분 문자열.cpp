#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MAX 4001

int dp[MAX][MAX];
int N;

int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    int ans = 0;
    for (int i = 0;i < s1.length();i++)
    {
        for (int j = 0;j < s2.length();j++)
        {
            if (s1[i] == s2[j])
            {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                    ans = max(ans, 1);
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
    }

    cout << ans;
    return 0;

}
