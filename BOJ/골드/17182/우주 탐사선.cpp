#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>

using namespace std;


int planets[10][10];
bool visited[10];
int N;
int ans;

void dfs(int curr, int d, int cnt) {
    if (cnt == N) {
        ans = min(ans, d);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i, d + planets[curr][i], cnt + 1);
            visited[i] = false;
        }
    }
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int K;

    cin >> N >> K;

    int i, j, k;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cin >> planets[i][j];
        }
    }

    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                planets[i][j] = min(planets[i][j], planets[i][k] + planets[k][j]);
            }
        }
    }

    memset(visited, false, sizeof(visited));
    ans = 1e9;

    visited[K] = true;
    dfs(K, 0, 1);

    cout << ans;

    return 0;
}
