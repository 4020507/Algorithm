#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int W, H, K;
int matrix[200][200];
bool visited[200][200][31];

void bfs() {

    pair<int, int> horse[8] = { {-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{2,-1},{2,1},{1,2} };
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    

    queue<pair<pair<int,int>, pair<int,int>>> q;
    q.push({ {0,0},{0,0}});

    memset(visited, false, sizeof(visited));
    visited[0][0][0] = true;

    int x, y, nx, ny, k, i;
    int step;

    while (!q.empty()) {

        step = q.front().first.first;
        k = q.front().first.second;
        x = q.front().second.first;
        y = q.front().second.second;

        q.pop();

        if (x == H - 1 && y == W - 1) {
            cout << step;
            return;
        }

        step++;

        for (i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                if (!visited[nx][ny][k] && matrix[nx][ny] != 1) {
                    visited[nx][ny][k] = true;
                    q.push({ {step,k},{nx,ny} });
                }
            }
        }

        if (k < K) {
            k++;
            for (i = 0; i < 8; i++) {
                nx = x + horse[i].first;
                ny = y + horse[i].second;

                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny][k] && matrix[nx][ny] != 1) {
                    visited[nx][ny][k] = true;
                    q.push({ {step,k},{nx,ny}});

                }
            }
        }
    }

    cout << -1;

}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> K >> W >> H;

    int i, j;

    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            cin >> matrix[i][j];
        }
    }

    bfs();

    return 0;
}
