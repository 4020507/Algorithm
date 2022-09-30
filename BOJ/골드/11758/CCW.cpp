#include<iostream>
#include<string.h>
#define INF 1000000000
using namespace std;


int CCW(int x1, int y1, int x2, int y2, int x3, int y3) {

    int calc = x1 * (y2 - y3) - y1 * (x2 - x3) + 1 * (x2 * y3 - x3 * y2);

    if (calc > 0)
        return 1;
    if (calc < 0)
        return -1;
    return 0;
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x1, x2, x3, y1, y2, y3;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;


    cout << CCW(x1, y1, x2, y2, x3, y3);

    return 0;
}
