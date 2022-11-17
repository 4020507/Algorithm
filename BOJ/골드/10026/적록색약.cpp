#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

char grid[101][101];
bool visited[101][101];
int N;

void normal(int x, int y, char color) {

    visited[x][y] = true;
    queue<pair<int, int>> q;

    q.push({x,y});

    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };

    int nx, ny, i;

    while (!q.empty()) {

        x = q.front().first;
        y = q.front().second;

        q.pop();

        for (i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && grid[nx][ny] == color) {
                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({ nx,ny });
                }
            }
        }
    }
}

void problem(int x, int y, char color) {

    visited[x][y] = true;
    queue<pair<int, int>> q;

    q.push({ x,y });

    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };

    int nx, ny, i;

    while (!q.empty()) {

        x = q.front().first;
        y = q.front().second;

        q.pop();

        for (i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if (color == 'B' && color == grid[nx][ny] && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({ nx,ny });
                }
                else if ((grid[nx][ny] == 'R' || grid[nx][ny] == 'G') && (color == 'R' || color == 'G') && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({ nx,ny });
                }
            }
        }
    }

}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    memset(visited, false, sizeof(visited));
    int ans1, ans2;
    ans1 = ans2 = 0;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (!visited[i][j]) {
                normal(i, j, grid[i][j]);
                ans1++;
            }
        }
    }

    memset(visited, false, sizeof(visited));

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (!visited[i][j]) {
                problem(i, j, grid[i][j]);
                ans2++;
            }
        }
    }

    cout << ans1 << ' ' << ans2;

    return 0;
}
