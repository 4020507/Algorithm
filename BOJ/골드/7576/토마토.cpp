#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
using namespace std;

int tomato[1000][1000];

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);    

    int N, M;

    cin >> N >> M;

    int i, j;
    queue<pair<int, int>> q;

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            cin >> tomato[i][j];

            if (tomato[i][j] == 1) {
                q.push({ i,j });
            }
        }
    }

    int x, y, nx, ny;
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N && tomato[nx][ny] == 0) {
                tomato[nx][ny] = tomato[x][y] + 1;
                q.push({ nx,ny });
            }
        }
    }

    int ans = 0;

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            if (tomato[i][j] == 0) {
                cout << -1;
                return 0;
            }
            else {
                ans = max(tomato[i][j], ans);
            }
        }
    }

    cout << ans - 1;

    return 0;
}
