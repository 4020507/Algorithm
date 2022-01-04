#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int alpha[26];
int N;
string s[10];
int temp[10];
int temp_num[26];
int ans;

void dfs(int num, int n)
{
    if (n == 0)
    {
        int sum = 0;
        memset(temp, 0, sizeof(temp));
        for (int i = 0;i < N;i++)
        {
            for (int j = 0;j < s[i].length();j++)
            {
                temp[i] = temp[i] * 10 + temp_num[s[i][j] - 'A'];
            }
            sum += temp[i];
        }
        ans = max(sum, ans);
        return;
    }
    for (int i = 0;i < 26;i++)
    {
        if (alpha[i] > 0 && temp_num[i] == -1)
        {
            temp_num[i] = num;
            dfs(num - 1, n-1);
            temp_num[i] = -1;
        }
    }
}
int main() {

    cin >> N;
    int alpha_count = 0;

    for (int i = 0;i < N;i++)
    {
        cin >> s[i];

        for (int j = 0;j < s[i].length();j++)
        {
            if (alpha[s[i][j] - 'A'] == 0)
                alpha_count++;
            alpha[s[i][j] - 'A']++;
        }
    }

    memset(temp_num, -1, sizeof(temp_num));
    dfs(9, alpha_count);

    cout << ans;

    return 0;
}
