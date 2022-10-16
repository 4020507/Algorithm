#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
#include<string>
#include<vector>
using namespace std;

int dx[10] = { 0,1,1,1,0,0,0,-1,-1,-1 };
int dy[10] = { 0,-1,0,1,-1,0,1,-1,0,1 };
char board[100][100];
int R, C;
vector<pair<int, int>> arduino;
bool exploded[10001];
pair<int, int> jongSoo;
int tdx[8] = { 1,1,1,0,0,-1,-1,-1 };
int tdy[8] = { -1,0,1,-1,1,-1,0,1 };

bool moveJongSoo(int dir) {

    jongSoo = { jongSoo.first + dx[dir], jongSoo.second + dy[dir] };

    for (int i = 0; i < arduino.size(); i++) {
        if (jongSoo == arduino[i]) {
            return true;
        }
    }

    return false;
}

bool moveArduino() {

    int i, j;
    int dist;
    int x, y, d;
    int tx, ty;

    for (i = 0; i < arduino.size(); i++) {

        dist = 1e9;

        for (j = 0; j < 8; j++) {
            x = arduino[i].first + tdx[j];
            y = arduino[i].second + tdy[j];

            if (x >= 0 && x < R && y >= 0 && y < C) {
                d = abs(x - jongSoo.first) + abs(y - jongSoo.second);

                if (d < dist) {
                    dist = d;
                    tx = x;
                    ty = y;
                }
            }
        }
        arduino[i] = {tx,ty};

        if (tx == jongSoo.first && ty == jongSoo.second) {
            return true;
        }
    }

    return false;
}

void explodeArduino() {

    if (arduino.size() == 0)
        return;

    int i, j;
    memset(exploded, false, sizeof(exploded));

    for (i = 0; i < arduino.size() - 1; i++) {

        if (exploded[i])
            continue;

        for (j = i + 1; j < arduino.size(); j++) {
            if (exploded[j])
                continue;

            if (arduino[i] == arduino[j]) {
                exploded[i] = true;
                exploded[j] = true;
            }
        }
    }

    vector<pair<int, int>> v;

    for (i = 0; i < arduino.size(); i++) {
        if (!exploded[i]) {
            v.push_back(arduino[i]);
        }
    }

    arduino = v;
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int i, j;

    cin >> R >> C;

    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            cin >> board[i][j];

            if (board[i][j] == 'I') {
                jongSoo = { i,j };
                board[i][j] = '.';
            }
            else if (board[i][j] == 'R') {
                arduino.push_back({ i,j });
                board[i][j] = '.';
            }
        }
    }

    string move;

    cin >> move;

    int len = move.length();

    for (i = 0; i < len; i++) {
        
        if (moveJongSoo(move[i] - '0')) {
            break;
        }

        if (moveArduino()) {
            break;
        }

        explodeArduino();

    }

    if (i < len - 1) {
        cout << "kraj " << (i + 1);
    }
    else {
        board[jongSoo.first][jongSoo.second] = 'I';

        for (i = 0; i < arduino.size(); i++) {

            board[arduino[i].first][arduino[i].second] = 'R';
        }

        for (i = 0; i < R; i++) {
            for (j = 0; j < C; j++) {
                cout << board[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}
