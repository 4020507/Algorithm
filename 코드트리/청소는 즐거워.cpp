#include <iostream>

using namespace std;

int matrix[500][500];
int n;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

bool range(int nx, int ny) {

    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
        return true;
    }

    return false;
}

int spreadDust(int x, int y, int d) {
    int nx, ny;
    int left = 0;
    int outmatrix = 0;

    if (d == 0) {
        nx = x;
        ny = y - 2;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.05;
        }
        else {
            outmatrix += matrix[x][y] * 0.05;
        }
        left += matrix[x][y] * 0.05;

        nx = x - 1;
        ny = y - 1;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.1;
        }
        else {
            outmatrix += matrix[x][y] * 0.1;
        }
        left += matrix[x][y] * 0.1;

        ny = y;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.07;
        }
        else {
            outmatrix += matrix[x][y] * 0.07;
        }
        left += matrix[x][y] * 0.07;

        ny = y + 1;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.01;
        }
        else {
            outmatrix += matrix[x][y] * 0.01;
        }
        left += matrix[x][y] * 0.01;

        nx = x - 2;
        ny = y;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.02;
        }
        else {
            outmatrix += matrix[x][y] * 0.02;
        }
        left += matrix[x][y] * 0.02;

        nx = x + 1;
        ny = y - 1;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.1;
        }
        else {
            outmatrix += matrix[x][y] * 0.1;
        }
        left += matrix[x][y] * 0.1;

        ny = y;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.07;
        }
        else {
            outmatrix += matrix[x][y] * 0.07;
        }
        left += matrix[x][y] * 0.07;

        ny = y + 1;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.01;
        }
        else {
            outmatrix += matrix[x][y] * 0.01;
        }
        left += matrix[x][y] * 0.01;

        nx = x + 2;
        ny = y;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.02;
        }
        else {
            outmatrix += matrix[x][y] * 0.02;
        }
        left += matrix[x][y] * 0.02;
    }
    else if (d == 1) {
        nx = x + 2;
        ny = y;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.05;
        }
        else {
            outmatrix += matrix[x][y] * 0.05;
        }
        left += matrix[x][y] * 0.05;

        nx = x + 1;
        ny = y - 1;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.1;
        }
        else {
            outmatrix += matrix[x][y] * 0.1;
        }
        left += matrix[x][y] * 0.1;

        nx = x;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.07;
        }
        else {
            outmatrix += matrix[x][y] * 0.07;
        }
        left += matrix[x][y] * 0.07;

        nx = x - 1;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.01;
        }
        else {
            outmatrix += matrix[x][y] * 0.01;
        }
        left += matrix[x][y] * 0.01;

        nx = x;
        ny = y - 2;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.02;
        }
        else {
            outmatrix += matrix[x][y] * 0.02;
        }
        left += matrix[x][y] * 0.02;

        nx = x + 1;
        ny = y + 1;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.1;
        }
        else {
            outmatrix += matrix[x][y] * 0.1;
        }
        left += matrix[x][y] * 0.1;

        nx = x;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.07;
        }
        else {
            outmatrix += matrix[x][y] * 0.07;
        }
        left += matrix[x][y] * 0.07;

        nx = x - 1;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.01;
        }
        else {
            outmatrix += matrix[x][y] * 0.01;
        }
        left += matrix[x][y] * 0.01;

        nx = x;
        ny = y + 2;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.02;
        }
        else {
            outmatrix += matrix[x][y] * 0.02;
        }
        left += matrix[x][y] * 0.02;
    }
    else if (d == 2) {
        nx = x;
        ny = y + 2;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.05;
        }
        else {
            outmatrix += matrix[x][y] * 0.05;
        }
        left += matrix[x][y] * 0.05;

        nx = x - 1;
        ny = y + 1;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.1;
        }
        else {
            outmatrix += matrix[x][y] * 0.1;
        }
        left += matrix[x][y] * 0.1;

        ny = y;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.07;
        }
        else {
            outmatrix += matrix[x][y] * 0.07;
        }
        left += matrix[x][y] * 0.07;

        ny = y - 1;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.01;
        }
        else {
            outmatrix += matrix[x][y] * 0.01;
        }
        left += matrix[x][y] * 0.01;

        nx = x - 2;
        ny = y;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.02;
        }
        else {
            outmatrix += matrix[x][y] * 0.02;
        }
        left += matrix[x][y] * 0.02;

        nx = x + 1;
        ny = y + 1;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.1;
        }
        else {
            outmatrix += matrix[x][y] * 0.1;
        }
        left += matrix[x][y] * 0.1;

        ny = y;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.07;
        }
        else {
            outmatrix += matrix[x][y] * 0.07;
        }
        left += matrix[x][y] * 0.07;

        ny = y - 1;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.01;
        }
        else {
            outmatrix += matrix[x][y] * 0.01;
        }
        left += matrix[x][y] * 0.01;

        nx = x + 2;
        ny = y;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.02;
        }
        else {
            outmatrix += matrix[x][y] * 0.02;
        }
        left += matrix[x][y] * 0.02;
    }
    else {

        nx = x - 2;
        ny = y;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.05;
        }
        else {
            outmatrix += matrix[x][y] * 0.05;
        }
        left += matrix[x][y] * 0.05;

        nx = x - 1;
        ny = y - 1;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.1;
        }
        else {
            outmatrix += matrix[x][y] * 0.1;
        }
        left += matrix[x][y] * 0.1;

        nx = x;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.07;
        }
        else {
            outmatrix += matrix[x][y] * 0.07;
        }
        left += matrix[x][y] * 0.07;

        nx = x + 1;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.01;
        }
        else {
            outmatrix += matrix[x][y] * 0.01;
        }
        left += matrix[x][y] * 0.01;

        nx = x;
        ny = y - 2;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.02;
        }
        else {
            outmatrix += matrix[x][y] * 0.02;
        }
        left += matrix[x][y] * 0.02;

        nx = x - 1;
        ny = y + 1;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.1;
        }
        else {
            outmatrix += matrix[x][y] * 0.1;
        }
        left += matrix[x][y] * 0.1;

        nx = x;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.07;
        }
        else {
            outmatrix += matrix[x][y] * 0.07;
        }
        left += matrix[x][y] * 0.07;

        nx = x + 1;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.01;
        }
        else {
            outmatrix += matrix[x][y] * 0.01;
        }
        left += matrix[x][y] * 0.01;

        nx = x;
        ny = y + 2;

        if (range(nx, ny)) {
            matrix[nx][ny] += matrix[x][y] * 0.02;
        }
        else {
            outmatrix += matrix[x][y] * 0.02;
        }
        left += matrix[x][y] * 0.02;
    }

    nx = x + dx[d];
    ny = y + dy[d];

    if (range(nx, ny)) {
        matrix[nx][ny] += (matrix[x][y] - left);
    }
    else {
        outmatrix += (matrix[x][y] - left);
    }
    matrix[x][y] = 0;

    return outmatrix;
}
int sweep() {
    int x, y;
    x = y = n / 2;
    int i = 0;
    int step = 1;
    int cnt = 0;
    int outmatrix = 0;

    while (x != 0 || y != 0) {

        x = x + dx[i];
        y = y + dy[i];

        outmatrix += spreadDust(x, y, i);

        cnt++;

        if (step == cnt) {
            i = (i + 1) % 4;
            cnt = 0;

            if (i == 0 || i == 2) {
                step++;
            }
        }

        
    }

    return outmatrix;
}
int main() {
    // 여기에 코드를 작성해주세요.

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << sweep();
    return 0;
}
