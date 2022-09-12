#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int matrix[20][20];
int herbicide[20][20];
int temp[20][20];
int n, m, k, c;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int dx2[4] = { -1,-1,1,1 };
int dy2[4] = { 1,-1,1,-1 };
int ans;
int i, j;

void growTrees() {
    int nx, ny, l;
    int cnt;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] > 0) {
                cnt = 0;
                for (l = 0; l < 4; l++) {
                    nx = i + dx[l];
                    ny = j + dy[l];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        if (matrix[nx][ny] > 0) {
                            cnt++;
                        }
                    }
                }
                matrix[i][j] += cnt;
            }
        }
    }
}

void breeding() {
    int nx, ny, l, cnt;
    vector<pair<int, int>> newTrees;

    memset(temp, 0, sizeof(temp));

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {

            if (matrix[i][j] > 0) {
                cnt = 0;
                newTrees.clear();
                for (l = 0; l < 4; l++) {
                    nx = i + dx[l];
                    ny = j + dy[l];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        if (matrix[nx][ny] == 0 && herbicide[nx][ny] == 0) {
                            newTrees.push_back({ nx,ny });
                        }
                    }
                }

                cnt = newTrees.size();

                for (l = 0; l < cnt; l++) {
                    temp[newTrees[l].first][newTrees[l].second] += (matrix[i][j] / cnt);
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] += temp[i][j];
        }
    }
}

void spray() {
    int nx, ny, p, l;
    int tx, ty;
    tx = ty = 0;
    int maxi = 0;
    int t;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] > 0) {
                t = 0;
                for (p = 0; p < 4; p++) {
                    for (l = 1; l <= k; l++) {
                        nx = i + dx2[p] * l;
                        ny = j + dy2[p] * l;

                        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                            if (herbicide[nx][ny] == 0 && matrix[nx][ny] > 0) {
                                t += matrix[nx][ny];
                            }
                            else {
                                break;
                            }
                        }
                    }
                }

                t += matrix[i][j];

                if (maxi < t) {
                    maxi = t;
                    tx = i;
                    ty = j;
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (herbicide[i][j] > 0) {
                herbicide[i][j]--;
            }
        }
    }

    for (p = 0; p < 4; p++) {
        for (l = 1; l <= k; l++) {
            nx = tx + dx2[p] * l;
            ny = ty + dy2[p] * l;

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (matrix[nx][ny] > 0) {
                    matrix[nx][ny] = 0;
                    herbicide[nx][ny] = c;
                }
                else if (matrix[nx][ny] == -1) {
                    break;
                }
                else if (matrix[nx][ny] == 0) {
                    herbicide[nx][ny] = c;
                    break;
                }
            }
        }
    }

    matrix[tx][ty] = 0;
    herbicide[tx][ty] = c;
    ans += maxi;
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k >> c;

    memset(matrix, 0, sizeof(matrix));
    memset(herbicide, 0, sizeof(herbicide));
    ans = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int t = 0; t < m; t++) {
        growTrees();
        breeding();
        spray();
    }

    cout << ans;
}
