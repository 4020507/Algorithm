#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string S;
int check;

void makeString(string t) {
    if (t == S) {
        check = 1;
        return;
    }

    if (t.length() == S.length()) {
        return;
    }

    string temp;

    if (t[t.length() - 1] == 'A') {
        temp = t.substr(0, t.length() - 1);
        makeString(temp);
    }

    if (t[0] == 'B') {
        reverse(t.begin(), t.end());
        temp = t.substr(0, t.length() - 1);
        makeString(temp);
    }
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string T;

    cin >> S >> T;
    check = 0;

    makeString(T);

    cout << check;

    return 0;
}
