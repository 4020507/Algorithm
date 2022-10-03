#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;

int N, K;
int arr[100][100];
int arr2[100][100];
int minVal;
int maxVal;
int n, m, h, x, y, idx;
int i, j, k, diff, half;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

bool check() {
    maxVal = 0;
    minVal = 1e9;

    for (i = 0; i < N; i++) {
        maxVal = max(maxVal, arr[0][i]);
        minVal = min(minVal, arr[0][i]);
    }

    return (maxVal - minVal) > K ? true : false;
}

void addFish() {

    for (i = 0; i < N; i++) {
        if (minVal == arr[0][i]) {
            arr[0][i]++;
        }
    }
}

void arrangeFishBowl() {
    n = 0;
    m = 0;
    h = 1;
    x = 0;
    y = 0;
    idx = N;

    while (1) {

        if (idx - h - 1< m) {
            break;
        }

        for (i = h; i > 0; i--) {
            for (j = m; j >= 0; j--) {
                arr2[i][j] = arr[x][y];

                x--;

                if (x == -1) {
                    x = n;
                    y++;
                }
            }

            x = m;
        }

        for (i = 0; i < idx - h; i++) {
            arr[0][i] = arr[0][i + h];
        }

        for (i = idx - h; i < idx; i++) {
            arr[0][i] = 0;
        }

        for (i = h; i >= 1; i--) {
            for (j = m; j >= 0; j--) {
                arr[i][j] = arr2[i][j];
            }
        }
        idx -= h;

        if (h == m) {
            h++;
        }
        else {
            m++;
        }

        x = m;
        y = 0;
    }
    
}

void sendFish() {

    memset(arr2, 0, sizeof(arr2));

    for (i = 0; i <= h; i++) {
        for (j = 0; j < idx; j++) {
            if (arr[i][j] > 0) {
                for (k = 0; k < 4; k++) {
                    x = i + dx[k];
                    y = j + dy[k];

                    if (x >= 0 && x <= h && y >= 0 &&  y < idx && arr[x][y] > 0) {
                        diff = (arr[x][y] - arr[i][j]) / 5;
                        arr2[i][j] += diff;
                    }
                }
            }
        }
    }

    for (i = 0; i <= h; i++) {
        for (j = 0; j < idx; j++) {
            arr[i][j] += arr2[i][j];
        }
    }
}

void oneLine() {
    k = 0;
    memset(arr2, 0, sizeof(arr2));

    for (j = 0; j < idx; j++) {
        for (i = 0; i <= h; i++) {
            if (arr[i][j] != 0) {
                arr2[0][k++] = arr[i][j];
            }
        }
    }

    memset(arr, 0, sizeof(arr));
    for (i = 0; i < k; i++) {
        arr[0][i] = arr2[0][i];
    }
}

void levitation() {
    k = 0;
    half = N / 2;

    for (i = half - 1; i >= 0; i--) {
        arr[1][i] = arr[0][k];
        arr[0][k] = arr[0][half + k];
        arr[0][half+k] = 0;
        k++;
    }

    m = 3;
    n = N / 4 - 1;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < N / 4; j++) {
            arr[m][n] = arr[i][j];
            n--;
        }
        m--;
        n = N / 4 - 1;
    }

    half /= 2;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < N / 4; j++) {
            arr[i][j] = arr[i][j + half];
            arr[i][j + half] = 0;
        }
    }
}


int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    for (i = 0; i < N; i++) {
        cin >> arr[0][i];
    }

    int ans = 0;

    while (check()) {
        ans++;
        addFish();
        arrangeFishBowl();
        sendFish();
        oneLine();
        levitation();

        h = 3;
        idx = N / 4;
        sendFish();
        oneLine();
    }

    cout << ans;

    return 0;
}
