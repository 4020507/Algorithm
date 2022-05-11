#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int N, M;
int graphPaper[100][100];
int visited[100][100];
int hours;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void melt() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] > 1)
                graphPaper[i][j] = 0;
        }
    }
}
void touchAir() {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;

    q.push({ 0,0 });
    visited[0][0] = 1;
    int x, y, nx, ny;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (visited[nx][ny] == 0 && graphPaper[nx][ny] == 0) {
                    visited[nx][ny] = 1;
                    q.push({ nx,ny });
                }
                else if (graphPaper[nx][ny] == 1)
                    visited[nx][ny]++;
            }
        }
    }
}
bool check() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graphPaper[i][j] == 1)
                return false;
        }
    }

    return true;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> graphPaper[i][j];
    hours = 0;

    while (!check()) {
        hours++;
        touchAir();
        melt();
    }

    cout << hours;

    return 0;

}
