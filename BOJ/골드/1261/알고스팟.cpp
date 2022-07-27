#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int N, M;
int mirro[101][101];
int dist[101][101];

void bfs() {

    queue<pair<int, int>> q;
    q.push({ 1,1 });

    int x, y;
    int nx, ny;
    int i;
    dist[1][1] = 0;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;

        q.pop();

        for (i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 1 && nx <= M && ny >= 1 && ny <= N) {

                if (mirro[nx][ny] == 1) {
                    if (dist[nx][ny] > dist[x][y] + 1) {
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({ nx,ny });
                    }
                }
                else {
                    if (dist[nx][ny] > dist[x][y]) {
                        dist[nx][ny] = dist[x][y];
                        q.push({ nx,ny });
                    }
                }
            }
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;

    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> s;

        for (int j = 0; j < N; j++) {
            mirro[i][j + 1] = s[j] - '0';
        }
    }
   
    for (int i = 1; i <= M; i++)
        fill(dist[i], dist[i] + N + 1, 1e9);

    bfs();

    cout << dist[M][N];
    return 0;

}
