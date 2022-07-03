#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

int matrix[64][64];
int iceCnt[64][64];
int rotation[64][64];
int N, Q, q;
int n;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visited[64][64];

int lump(int x, int y) {
    queue<pair<int, int>> q;
    int boxes = 1;
    q.push({ x,y });
    visited[x][y] = true;
    int nx, ny, i;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (i = 0;i < 4;i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (!visited[nx][ny] && matrix[nx][ny] > 0) {
                    visited[nx][ny] = true;
                    boxes++;
                    q.push({ nx,ny });
                }
            }
        }
    }

    return boxes;
}
int sum() {
    int cnt = 0;

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++)
            cnt += matrix[i][j];
    }

    return cnt;
}
void melting() {
    memset(iceCnt, 0, sizeof(iceCnt));
    int x, y;

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {

            if (matrix[i][j] == 0)
                continue;

            for (int k = 0;k < 4;k++) {
                x = i + dx[k];
                y = j + dy[k];

                if (x >= 0 && x < n && y >= 0 && y < n) {
                    if (matrix[x][y] > 0)
                        iceCnt[i][j]++;
                }
            }
        }
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (iceCnt[i][j] < 3 && matrix[i][j] > 0)
                matrix[i][j]--;
        }
    }
}
void rotate(int r, int c, int jump) {
    
    for (int i = 0;i < jump;i++)
        for (int j = 0;j < jump;j++)
            rotation[i][j] = matrix[r + jump - j - 1][i + c];

    for (int i = 0;i < jump;i++)
        for (int j = 0;j < jump;j++)
            matrix[i + r][j + c] = rotation[i][j];
}
void divide()
{
    int jump = pow(2, q);

    for (int i = 0;i < n;i += jump) {
        for (int j = 0;j < n;j += jump) {
            rotate(i, j, jump);
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N >> Q;

    n = pow(2, N);

    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            cin >> matrix[i][j];

    for (int i = 0;i < Q;i++) {
        cin >> q;
        divide();
        melting();
    }

    cout << sum() << '\n';

    int box = 0;
    memset(visited, false, sizeof(visited));
    for(int i = 0;i<n;i++)
        for (int j = 0;j < n;j++) {
            if (!visited[i][j] && matrix[i][j] > 0)
                box = max(lump(i, j), box);
        }

    cout << box;

    return 0;

}
