#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 1001

int dp[MAX][MAX];

int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 1;i <= s1.size();i++)
    {
        for (int j = 1;j <= s2.size();j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    int answer = dp[s1.length()][s2.length()];

    cout << answer << '\n';

    vector<char> v;

    if (answer > 0)
    {
        int x = s1.length();
        int y = s2.length();
        v.clear();

        while (1)
        {
            if (x == 0 || y == 0)
                break;
            if (s1[x - 1] == s2[y - 1])
            {
                v.push_back(s1[x - 1]);
                x--;
                y--;
            }
            else
            {
                if (dp[x][y] == dp[x - 1][y])
                {
                    x--;
                }
                else if (dp[x][y] == dp[x][y - 1])
                {
                    y--;
                }
            }
        }
    }

    for (int i = v.size() - 1;i >= 0;i--)
    {
        cout << v[i];
    }
    return 0;

}
