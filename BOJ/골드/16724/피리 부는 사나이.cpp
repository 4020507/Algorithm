#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int map[1000][1000];
int visited[1000][1000];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int safeZone;

void move(int x, int y, int mark) {
    visited[x][y] = mark;

    int nx = x + dx[map[x][y]];
    int ny = y + dy[map[x][y]];

    if (visited[nx][ny] == 0) {
        move(nx, ny, mark);
    }
    else {
        if (visited[nx][ny] == mark) {
            safeZone++;
        }
    }
}


int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    
    cin >> N >> M;

    int i, j;
    char c;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            cin >> c;

            switch (c) {
            case 'U':
                map[i][j] = 0;
                break;
            case 'D':
                map[i][j] = 1;
                break;
            case 'L':
                map[i][j] = 2;
                break;
            case 'R':
                map[i][j] = 3;
            }

            visited[i][j] = 0;
        }
    }

    safeZone = 0;
    int mark = 1;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (visited[i][j] == 0) {
                move(i, j, mark);
                mark++;
            }
        }
    }

    cout << safeZone;

    return 0;
}
