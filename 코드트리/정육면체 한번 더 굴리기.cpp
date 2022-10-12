#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
#include<queue>

using namespace std;

int dice[6] = { 1,2,3,4,5,6 };
int d1, d2, d3, d4, d5, d6;
int n;
int matrix[20][20];
int m;
bool visited[20][20];
int currX, currY;

void setDiceNum() {

    dice[0] = d1;
    dice[1] = d2;
    dice[2] = d3;
    dice[3] = d4;
    dice[4] = d5;
    dice[5] = d6;

}
void east() {

    d1 = dice[3];
    d2 = dice[1];
    d3 = dice[0];
    d4 = dice[5];
    d5 = dice[4];
    d6 = dice[2];
    currY++;
}

void west() {
    d1 = dice[2];
    d2 = dice[1];
    d3 = dice[5];
    d4 = dice[0];
    d5 = dice[4];
    d6 = dice[3];
    currY--;
}

void south() {
    d1 = dice[4];
    d2 = dice[0];
    d3 = dice[2];
    d4 = dice[3];
    d5 = dice[5];
    d6 = dice[1];
    currX++;
}

void north() {
    d1 = dice[1];
    d2 = dice[5];
    d3 = dice[2];
    d4 = dice[3];
    d5 = dice[0];
    d6 = dice[4];
    currX--;
}

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int getScore(int x, int y) {

    queue<pair<int, int>> q;
    int cnt = 1;
    memset(visited, false, sizeof(visited));

    int nx, ny, i;

    q.push({ x,y });
    visited[x][y] = true;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;

        q.pop();

        for (i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (!visited[nx][ny] && matrix[x][y] == matrix[nx][ny]) {
                    cnt++;
                    visited[nx][ny] = true;
                    q.push({ nx,ny });
                }
            }
        }
    }

    return matrix[x][y] * cnt;
}

void moveDice(int dir) {

    switch (dir) {
    case 0:
        east();
        break;
    case 1:
        south();
        break;
    case 2:
        west();
        break;
    case 3:
        north();
        break;
    }
}

int checkReverse(int dir) {

    if (dir == 0) {
        if (currY + 1 >= n) {
            dir = 2;
        }
    }
    else if (dir == 1) {
        if (currX + 1 >= n) {
            dir = 3;
        }
    }
    else if (dir == 2) {
        if (currY - 1 < 0) {
            dir = 0;
        }
    }
    else if (dir == 3) {
        if (currX - 1 < 0) {
            dir = 1;
        }

    }

    return dir;
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int dir = 0;
    int score = 0;
    currX = currY = 0;

    for (i = 0; i < m; i++) {

        moveDice(dir);
        setDiceNum();
        score += getScore(currX, currY);

        if (matrix[currX][currY] < dice[5]) {
            dir++;

            if (dir == 4) {
                dir = 0;
            }
        }
        else if (matrix[currX][currY] > dice[5]) {
            dir--;

            if (dir == -1) {
                dir = 3;
            }
        }
        
        dir = checkReverse(dir);
    }

    cout << score;

    return 0;
}
