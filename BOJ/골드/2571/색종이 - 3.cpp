#include <iostream>
#include <string.h>
using namespace std;

bool paper[101][101];


bool check(int x, int y, int ax, int ay) {

    int i, j;

    for (i = x; i <= ax; i++) {
        for (j = y; j <= ay; j++) {
            if (!paper[i][j]) {
                return false;
            }
        }
    }

    return true;
}
int area(int x, int y) {

    int i, j;
    int temp = 0;

    for (i = 0; i + x <= 100; i++) {
        for (j = 0; j + y <= 100; j++) {
            if (check(x, y, x + i, y + j)) {
                temp = max(temp, (i+1) * (j+1));
            }
        }
    }

    return temp;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int cnt;
    int a, b;

    cin >> cnt;

    int i,j,k;
    memset(paper, false, sizeof(paper));

    for (i = 0; i < cnt; i++) {
        cin >> a >> b;

        for (j = b; j < b + 10; j++) {
            for (k = a; k < a + 10; k++) {
                paper[j][k] = true;
            }
        }
    }

    int ans = 100;
    for (i = 0; i <= 100; i++) {
        for (j = 0; j <= 100; j++) {
            if (paper[i][j]) {
                ans = max(ans, area(i, j));
            }
        }
    }

    cout << ans;

    return 0;
}
