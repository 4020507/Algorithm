#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int CCW(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long res = (x1 * y2) + (x2 * y3) + (x3 * y1) - (y1 * x2) - (y2 * x3) - (x1 * y3);

    if (res < 0)
        return -1;
    if (res > 0)
        return 1;

    return 0;
}


int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long x1, y1, x2, y2, x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    int res1 = CCW(x1, y1, x2, y2, x3, y3);
    int res2 = CCW(x1, y1, x2, y2, x4, y4);
    int res3 = CCW(x3, y3, x4, y4, x1, y1);
    int res4 = CCW(x3, y3, x4, y4, x2, y2);

    if (res1 * res2 < 0 && res3 * res4 < 0) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}
