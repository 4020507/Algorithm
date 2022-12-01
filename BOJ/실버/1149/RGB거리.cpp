#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>

using namespace std;


int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int house[1000][3];
    int N;
    int r, g, b;

    cin >> N;

    house[0][0] = house[0][1] = house[0][2] = 0;

    for (int i = 1; i <= N; i++) {
        cin >> r >> g >> b;

        house[i][0] = min(house[i - 1][1], house[i - 1][2]) + r;
        house[i][1] = min(house[i - 1][0], house[i - 1][2]) + g;
        house[i][2] = min(house[i - 1][0], house[i - 1][1]) + b;
    }

    cout << min(house[N][0], min(house[N][1], house[N][2]));

    return 0;
}
