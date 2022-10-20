#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
#include<string>
using namespace std;

int N, M, K;
int map[1000][1000];
int dp[1000][1000][11];

int findRoute() {

    queue<pair<int, pair<int, int>>> q;

    q.push({ 0,{0,0} });

    int x, y, nx, ny, k, i;
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { 1,-1,0,0 };

    dp[0][0][0] = 1;

    while (!q.empty()) {
        x = q.front().second.first;
        y = q.front().second.second;
        k = q.front().first;

        q.pop();

        if (x == N - 1 && y == M - 1) {
            return dp[x][y][k];
        }

        for (i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {

                if (map[nx][ny] == 0 && dp[nx][ny][k] == 0) {
                    q.push({ k,{nx,ny} });
                    dp[nx][ny][k] = dp[x][y][k] + 1;
                }
                else if (map[nx][ny] == 1 && k < K && dp[nx][ny][k+1] == 0) {
                    q.push({ k+1,{nx,ny} });
                    dp[nx][ny][k + 1] = dp[x][y][k] + 1;
                }
            }
        }
    }


    return -1;
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            map[i][j] = s[j] - '0';
        }
    }
    
    cout << findRoute();


    return 0;
}
