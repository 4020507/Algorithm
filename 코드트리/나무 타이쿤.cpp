#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

int libro[15][15];
bool medicine[15][15];
bool temp[15][15];
int dx[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int dy[9] = { 0,1,1,0,-1,-1,-1,0,1 };
int gDx[4] = { -1,1,1,-1 };
int gDy[4] = { 1,1,-1,-1 };
int n;
int i, j, k;
int d, p;
int x, y;
int libroCnt;

void moveMedicine() {

    memset(temp, false, sizeof(temp));

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (medicine[i][j]) {
                x = i;
                y = j;
                for (k = 0; k < p; k++) {
                    x = x + dx[d];
                    y = y + dy[d];

                    if (x == n) {
                        x = 0;
                    }
                    else if (x == -1) {
                        x = n - 1;
                    }

                    if (y == n) {
                        y = 0;
                    }
                    else if (y == -1) {
                        y = n - 1;
                    }
                }

                temp[x][y] = true;
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            medicine[i][j] = temp[i][j];
        }
    }
}

void growLibro() {

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (medicine[i][j]) {
                libro[i][j]++;
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (medicine[i][j]) {
                libroCnt = 0;
                for (k = 0; k < 4; k++) {
                    x = i + gDx[k];
                    y = j + gDy[k];

                    if (x >= 0 && x < n && y >= 0 && y < n && libro[x][y] > 0) {
                        libroCnt++;
                    }
                }
                libro[i][j] += libroCnt;
            }
        }
    }
}

void putMedicine() {

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (libro[i][j] > 1 && !medicine[i][j]) {
                libro[i][j] -= 2;
                medicine[i][j] = true;
            }
            else if (medicine[i][j]) {
                medicine[i][j] = false;
            }
        }
    }
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m;

    cin >> n >> m;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> libro[i][j];
        }
    }

    memset(medicine, false, sizeof(medicine));

    medicine[n - 1][0] = true; medicine[n - 1][1] = true; medicine[n - 2][0] = true; medicine[n - 2][1] = true;

    for (int M = 0; M < m; M++) {
        cin >> d >> p;

        moveMedicine();
        growLibro();
        putMedicine();

    }

    int height = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            height += libro[i][j];
        }
    }

    cout << height;

    return 0;
}
