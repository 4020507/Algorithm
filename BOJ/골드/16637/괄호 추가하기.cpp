#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int N;
string s;
int ans;

int calc(int num1, int num2, int index) {

    if (s[index] == '+') {
        return num1 + num2;
    }
    else if (s[index] == '-') {
        return num1 - num2;
    }
    else {
        return num1 * num2;
    }
}

void getAns(int curr, int cal) {

    if (curr >= N) {
        ans = max(cal, ans);

        return;
    }

    if (curr + 2 < N) {
        int num1 = calc(s[curr + 1] - '0', s[curr + 3] - '0', curr + 2);
        getAns(curr + 4, calc(cal, num1, curr));
    }
    getAns(curr + 2, calc(cal, s[curr + 1] - '0', curr));
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> s;

    ans = -1e9;

    getAns(1, s[0] - '0');

    cout << ans;

    return 0;
}16
