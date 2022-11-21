#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
#include<queue>
#include<string>
using namespace std;

int map[1000][1000];
int dp[1000][1000][2];
int N, M;

int findShortestRoute() {

    queue<pair<pair<int, int>, int>> q;

    q.push({ {0,0},0 });
    dp[0][0][0] = 1;

    int x, y, nx, ny;
    int wall, i;
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };

    while (!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        wall = q.front().second;
        q.pop();

        if (x == N - 1 && y == M - 1) {
            return dp[x][y][wall];
        }

        for (i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (map[nx][ny] == 0) {
                    if (dp[nx][ny][wall] == -1 || dp[nx][ny][wall] > dp[x][y][wall] + 1) {
                        dp[nx][ny][wall] = dp[x][y][wall] + 1;
                        q.push({ {nx,ny},wall });
                    }
                }
                else if (map[nx][ny] == 1 && wall == 0) {
                    if (dp[nx][ny][1] == -1 || dp[nx][ny][1] > dp[x][y][wall] + 1) {
                        dp[nx][ny][1] = dp[x][y][wall] + 1;
                        q.push({ {nx,ny},1 });
                    }
                }
            }
        }
    }


    return -1;
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    
    cin >> N >> M;

    int i, j;
    string s;

    for (i = 0; i < N; i++) {
        cin >> s;
        for (j = 0; j < M; j++) {
            map[i][j] = s[j] - '0';
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }

    cout << findShortestRoute();

    return 0;
}
