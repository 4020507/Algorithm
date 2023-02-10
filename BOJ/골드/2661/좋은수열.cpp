#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>

using namespace std;

string ans;

void solve(string s, int& N) {

    if (ans != "") {
        return;
    }

    int size = s.size();

    if (size > N) {
        return;
    }

    for (int i = 1; i <= size / 2; i++) {
        if (s.substr(size - i, i) == s.substr(size - 2 * i, i)) {
            return;
        }
    }

    if (size == N) {
        ans = s;
        return;
    }

    solve(s + '1', N);
    solve(s + '2', N);
    solve(s + '3', N);
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);    

    int N;
    cin >> N;

    ans = "";

    solve("1", N);
    solve("2", N);
    solve("3", N);

    cout << ans;

    return 0;
}
