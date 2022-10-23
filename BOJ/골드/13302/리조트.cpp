#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
using namespace std;

int dp[101][41];
bool days[101];
int N, M;

int getAns(int curr, int coupons) {

    if (curr >= N) {
        return 0;
    }


    int& calc = dp[curr][coupons];

    if (calc != -1) {
        return calc;
    }

    calc = 1e9;

    calc = min(calc, getAns(curr + 5, coupons + 2) + 37000);
    calc = min(calc, getAns(curr + 3, coupons + 1) + 25000);
    
    if (days[curr + 1]) {
        calc = min(calc, getAns(curr + 1, coupons));
    }
    else {
        if (coupons >= 3) {
            calc = min(calc, getAns(curr + 1, coupons - 3));
        }

        calc = min(calc, getAns(curr + 1, coupons) + 10000);
    }

    return calc;
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    
    cin >> N >> M;

    int d;

    memset(days, false, sizeof(days));
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < M; i++) {
        cin >> d;
        days[d] = true;
    }

    cout << getAns(0, 0);

    return 0;
}
