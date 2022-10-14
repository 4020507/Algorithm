#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

int matrix[50][50];
int direction[50][50];
int arr[2500];
int tArr[2500];
vector<int> zeroesIndex;
int N, M, d, s;
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,-1,1 };
int i, j;
int x, y, nx, ny;
int score;

void setDirection() {
    x = N / 2 + 1;
    y = N / 2;

    int dir = 0;
    int cnt = 0;
    int tCnt = 1;
    int increaseCnt = 1;
    int td[4] = { 2,4,1,3 };

    while (1) {

        direction[x][y] = td[dir];

        if (x == 1 && y == 1) {
            break;
        }

        x = x + dx[td[dir]];
        y = y + dy[td[dir]];
        cnt++;

        if (increaseCnt == cnt) {
            cnt = 0;
            tCnt++;

            if (tCnt == 2) {
                increaseCnt++;
                tCnt = 0;
            }
            dir = (dir + 1) % 4;
        }
    }
}

void destory() {
    x = N / 2 + 1;
    y = N / 2 + 1;

    for (i = 0; i < s; i++) {
        x = x + dx[d];
        y = y + dy[d];

        matrix[x][y] = 0;
    }
}

void arrange1D() {
    x = N / 2 + 1;
    y = N / 2;

    for (i = 0; i < N * N; i++) {
        arr[i] = matrix[x][y];
        nx = x + dx[direction[x][y]];
        ny = y + dy[direction[x][y]];

        x = nx;
        y = ny;
    }
}

void removeZeroes() {

    int idx = 0;

    for (i = 0; i < N * N; i++) {
        if (arr[i] != 0) {
            tArr[idx++] = arr[i];
        }
    }

    memset(arr, 0, sizeof(arr));

    for (i = 0; i < idx; i++) {
        arr[i] = tArr[i];
    }
}

bool explode() {
    int idx = 0;
    int val = arr[0];
    int cnt = 1;

    zeroesIndex.clear();

    for (i = 1; i < N * N; i++) {

        if (arr[i] == 0) {

            if (cnt >= 4) {
                for (j = 1; j <= cnt; j++) {
                    zeroesIndex.push_back(i - j);
                }

                score += (val * cnt);
            }

            break;
        }

        if (arr[i] == val) {
            cnt++;
        }
        else {
            if (cnt >= 4) {
                for (j = 1; j <= cnt; j++) {
                    zeroesIndex.push_back(i - j);
                }

                score += (val * cnt);
            }

            cnt = 1;
            val = arr[i];
        }
    }

    for (auto z : zeroesIndex) {
        arr[z] = 0;
    }

    if (zeroesIndex.size() > 0) {
        return true;
    }
    
    return false;
}

void setNum() {
    int idx = 0;
    int val = arr[0];
    int cnt = 1;

    memset(tArr, 0, sizeof(tArr));

    for (i = 1; i < N * N; i++) {
        
        if (idx >= N * N) {
            break;
        }

        if (arr[i] == 0) {

            if (val == 0) {
                break;
            }

            tArr[idx++] = cnt;

            if (idx < N * N) {
                tArr[idx] = arr[i - 1];
            }
            break;
        }

        if (val == arr[i]) {
            cnt++;
        }
        else {
            tArr[idx++] = cnt;

            if (idx >= N * N) {
                break;
            }

            tArr[idx++] = arr[i - 1];
            val = arr[i];
            cnt = 1;
        }
    }

    idx = 0;

    x = N / 2 + 1;
    y = N / 2;

    while (1) {
        matrix[x][y] = tArr[idx++];

        if (x == 1 && y == 1) {
            break;
        }

        nx = x + dx[direction[x][y]];
        ny = y + dy[direction[x][y]];

        x = nx;
        y = ny;
    }
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            cin >> matrix[i][j];
        }
    }

    setDirection();

    score = 0;

    for (int m = 0; m < M; m++) {
        cin >> d >> s;

        destory();
        arrange1D();
        removeZeroes();

        while (explode()) {
            removeZeroes();
        }

        setNum();

    }

    cout << score;

    return 0;
}
