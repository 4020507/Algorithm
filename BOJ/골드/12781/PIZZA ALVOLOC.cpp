#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;


int CCW(int x1, int y1, int x2, int y2, int x3, int y3) {

    int decision = x1 * y2 + x2 * y3 + x3 * y1 - (y1 * x2 + y2 * x3 + y3 * x1);

    if (decision < 0)
        return -1;
    if (decision > 0)
        return 1;

    return 0;
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x1, y1, x2, y2, x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    int decision = CCW(x1, y1, x2, y2, x3, y3) * CCW(x1, y1, x2, y2, x4, y4);

    if (decision < 0)
        cout << 1;
    else
        cout << 0;

    return 0;
}
