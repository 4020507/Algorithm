#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

double CCW(double x1, double y1, double x2, double y2, double x3, double y3) {

    return ((x1 * y2) + (x2 * y3) + (x3 * y1) - (y1 * x2) - (y2 * x3) - (y3 * x1)) / 2;
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;

    cin >> N;

    double x, y;
    vector<pair<double, double>> v;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;

        v.push_back({ x,y });
    }

    double ans = 0;
    x = v[0].first;
    y = v[0].second;
    for (int i = 1; i < N; i++) {
        ans += CCW(x, y, v[i - 1].first, v[i - 1].second, v[i].first, v[i].second);
    }

    cout << fixed;
    cout.precision(1);

    cout << abs(ans);

    return 0;
}
