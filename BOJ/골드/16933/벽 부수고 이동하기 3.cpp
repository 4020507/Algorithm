#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
#include<queue>
#include<cstdio>

using namespace std;

int map[1000][1000];
int N, M, K;
int visited[1000][1000][11][2];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs() {
    memset(visited, 0, sizeof(visited));

    queue<pair<pair<int, int>, pair<int, int>>> q;

    q.push({ {0,0},{0,0} });
    visited[0][0][0][0] = 1;

    int x, y, nx, ny, k, isNight;
    int i;

    while (!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        k = q.front().second.first;
        isNight = q.front().second.second;

        q.pop();

        for (i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {

                if (map[nx][ny] == 0 && visited[nx][ny][k][1 - isNight] == 0) {
                    visited[nx][ny][k][1 - isNight] = visited[x][y][k][isNight] + 1;
                    q.push({ {nx,ny},{k,1 - isNight} });
                }

                if (map[nx][ny] == 1 && isNight == 0 && k +1 <= K && visited[nx][ny][k + 1][1 - isNight] == 0) {
                    visited[nx][ny][k + 1][1 - isNight] = visited[x][y][k][isNight] + 1;
                    q.push({ {nx,ny},{k + 1,1 - isNight} });
                }
            }
        }

        if (visited[x][y][k][1 - isNight] == 0) {
            visited[x][y][k][1 - isNight] = visited[x][y][k][isNight] + 1;
            q.push({ {x,y},{k,1 - isNight} });
        }
    }
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    int ans = -1;

    bfs();

    for (int i = 0; i <= K; i++) {
        for (int j = 0; j < 2; j++) {
            if (visited[N - 1][M - 1][i][j] != 0) {

                if(ans == -1 || ans > visited[N-1][M-1][i][j])
                    ans = visited[N - 1][M - 1][i][j];
            }
        }
    }

    cout << ans;

    return 0;
}
