#include <iostream>
#include <math.h>
#include <queue>
#include <string.h>

using namespace std;

int matrix[64][64];
int temp[64][64];
bool visited[64][64];
int n;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int groupSize() {
    int biggest = 0;
    memset(visited, false, sizeof(visited));
    int i, j, x, y, nx, ny, k;
    int tSize;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] > 0 && !visited[i][j]) {
                tSize = 1;
                queue<pair<int, int>> q;
                q.push({ i,j });
                visited[i][j] = true;

                while (!q.empty()) {
                    x = q.front().first;
                    y = q.front().second;
                    q.pop();

                    for (k = 0; k < 4; k++) {
                        nx = x + dx[k];
                        ny = y + dy[k];

                        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                            if (!visited[nx][ny] && matrix[nx][ny] > 0) {
                                tSize++;
                                q.push({ nx,ny });
                                visited[nx][ny] = true;
                            }
                        }
                    }
                }

                biggest = max(biggest, tSize);
            }
        }
    }

    return biggest;
}

int totalIce() {
    int total = 0;

    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            total += matrix[i][j];
        }
    }

    return total;
}
void meltDown() {
    int i, j, k;
    int ice;
    int x, y;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {

            if (matrix[i][j] == 0) {
                temp[i][j] = 0;
                continue;
            }

            ice = 0;
            for (k = 0; k < 4; k++) {
                x = i + dx[k];
                y = j + dy[k];

                if (x >= 0 && x < n && y >= 0 && y < n) {
                    if (matrix[x][y] > 0) {
                        ice++;
                    }
                }
            }

            if (ice < 3) {
                temp[i][j] = matrix[i][j] - 1;
            }
            else {
                temp[i][j] = matrix[i][j];
            }
        }
    }
}

void copyMatrix() {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
}

void rotate(int x, int y, int level) {
    int i, j;
    int full = pow(2, level);
    int half = pow(2, level - 1);

    //왼위
    for (i = x; i < x + half; i++) {
        for (j = y; j < y + half; j++) {
            temp[i][j + half] = matrix[i][j];
        }
    }

    //오위
    for (i = x; i < x + half; i++) {
        for (j = y + half; j < y + full; j++) {
            temp[i + half][j] = matrix[i][j];
        }
    }

    //왼아래
    for (i = x + half; i < x + full; i++) {
        for (j = y; j < y + half; j++) {
            temp[i - half][j] = matrix[i][j];
        }
    }

    //오아래
    for (i = x + half; i < x + full; i++) {
        for (j = y + half; j < y + full; j++) {
            temp[i][j - half] = matrix[i][j];
        }
    }
}

void chooseIndex(int level) {

    if (level == 0) {
        return;
    }

    int i, j;
    int shift = pow(2, level);

    for (i = 0; i < n; i += shift) {
        for (j = 0; j < n; j += shift) {
            rotate(i, j, level);
        }
    }

    copyMatrix();

}

int main() {
    // 여기에 코드를 작성해주세요.
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int q;

    cin >> n >> q;

    n = pow(2, n);

    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int level;

    for (int t = 0; t < q; t++) {
        cin >> level;

        chooseIndex(level);
        meltDown();
        copyMatrix();
    }

    cout << totalIce() << '\n';
    cout << groupSize();

    return 0;
}
