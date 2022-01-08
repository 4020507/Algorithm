#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

string num;
int K;
int ans;
int dp[1000001][11];

int dfs(string s, int cnt)
{
    int num = stoi(s);
    if (cnt == K)
    {
        return num;
    }

    int& val = dp[num][cnt];

    if (val != -1)
        return val;

    for (int i = 0;i < s.length();i++)
    {
        for (int j = i+1;j < s.length();j++)
        {
            if (s[j] == '0' && i == 0)
                continue;
            swap(s[i], s[j]);
            val = max(val, dfs(s, cnt + 1));
            swap(s[i], s[j]);
        }
    }

    return val;
}
int main() {

    cin >> num >> K;
    
    memset(dp, -1, sizeof(dp));
    cout << dfs(num, 0);
    return 0;
}
