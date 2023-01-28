#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
#include<vector>
#include<string>
using namespace std;

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int dp[51][1001];
    vector<int> students[51];
    string input;

    int N, M, H;

    cin >> N >> M >> H;
    cin.ignore();
    int i, j;
    string temp;
    for (i = 1; i <= N; i++) {
        getline(cin, input, '\n');
        temp = "";
        for (j = 0; j < input.length(); j++) {
            if (input[j] == ' ' || j == 0) {
                students[i].push_back(stoi(&input[j]));
            }
        }
    }

    int k;
    memset(dp, 0, sizeof(dp));

    for (i = 0; i <= N; i++) {
        dp[i][0] = 1;
    }

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= H; j++) {
            for (k = 0; k < students[i].size(); k++) {
                if (students[i][k] <= j) {
                    dp[i][j] += dp[i - 1][j - students[i][k]];
                    dp[i][j] %= 10007;
                }
            }

            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= 10007;
        }
    }

    cout << dp[N][H];

    return 0;
}
