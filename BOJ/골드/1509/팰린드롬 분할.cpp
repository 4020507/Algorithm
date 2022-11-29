#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
#include<string>
using namespace std;

bool isPalindrome[2501][2501];
string s;
int dp[2501];

bool checkPalin(int start, int end) {

    if (end > s.length() - 1) {
        return false;
    }

    if (s[start] == s[end]) {
        if ((end - start == 1) || isPalindrome[start + 1][end - 1]) {
            return true;
        }
    }

    return false;
}

void setPalindrome() {
    int i, j;
    int len = s.length() - 1;

    for (i = 0; i < len; i++) {
        for (j = 1; j + i <= len; j++) {
            if (i == 0) {
                isPalindrome[j][j] = true;
            }
            else {
                isPalindrome[j][j+i] = checkPalin(j, j + i);
            }
        }
    }
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    
    s = " " + s;

    setPalindrome();

    int i, j;

    dp[0] = 0;

    for (i = 1; i <= s.length() - 1; i++) {
        dp[i] = 1e9;

        for (j = 1; j <= i; j++) {
            if (isPalindrome[j][i]) {
                if (dp[i] > dp[j - 1] + 1) {
                    dp[i] = dp[j - 1] + 1;
                }
            }
        }
    }

    cout << dp[s.length() - 1];

    return 0;
}
