#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>

using namespace std;

int N;
string s1, s2;
int ans;

char convert(char c) {

    if (c == '1') {
        return '0';
    }

    return '1';
}

void solve(string &s, int cnt, int idx) {
    if (idx == N) {
        if (s[idx - 1] == s2[idx - 1]) {
            if (ans != -1) {
                ans = min(ans, cnt);
            }
            else {
                ans = cnt;
            }
        }

        return;
    }

    if (s[idx - 1] == s2[idx - 1]) {
        solve(s, cnt, idx + 1);
    }
    else {
        s[idx - 1] = convert(s[idx - 1]);
        s[idx] = convert(s[idx]);

        if (idx + 1 < N) {
            s[idx + 1] = convert(s[idx + 1]);
        }

        solve(s, cnt + 1, idx + 1);
    }
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> s1 >> s2;
    
    string temp = s1;

    ans = -1;

    solve(temp, 0, 1);

    if (ans == -1) {
        temp = s1;
        temp[0] = convert(temp[0]);
        temp[1] = convert(temp[1]);
        solve(temp, 1, 1);
    }

    cout << ans;

    return 0;
}
