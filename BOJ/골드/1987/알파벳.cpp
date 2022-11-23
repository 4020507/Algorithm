#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>

using namespace std;

bool visited[20][20];
int map[20][20];
bool alphabet[26];
int N, M;
int ans;

void dfs(int x, int y, int dist) {
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    int nx, ny;
    ans = max(ans, dist);

    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if (!visited[nx][ny] && !alphabet[map[nx][ny]]) {
                visited[nx][ny] = true;
                alphabet[map[nx][ny]] = true;
                dfs(nx, ny, dist + 1);
                visited[nx][ny] = false;
                alphabet[map[nx][ny]] = false;
            }
        }
    }
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    
    cin >> N >> M;

    int i, j;
    char c;

    memset(alphabet, false, sizeof(alphabet));
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            cin >> c;
            map[i][j] = (c - 'A');
            visited[i][j] = false;
        }
    }

    ans = 0;

    visited[0][0] = true;
    alphabet[map[0][0]] = true;
    dfs(0, 0, 1);

    cout << ans;

    return 0;
}
