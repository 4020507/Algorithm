#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;

int dead[5][5];
pair<int, int> pacMan;
int copied[5][5][9];
int monsters[5][5][9];
int moved[5][5][9];
bool visited[5][5];
int m, t;
int pDx[4] = { -1,0,1,0 };
int pDy[4] = { 0,-1,0,1 };
int mDx[9] = { 0,-1,-1,0,1,1,1,0,-1 };
int mDy[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int i, j, k, d;
int x, y, cnt;
vector<pair<int, int>> finalRoute;
bool isMoved;

void copyMonsters() {

    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= 4; j++) {
            for (k = 1; k <= 8; k++) {
                copied[i][j][k] = monsters[i][j][k];
            }
        }
    }
}

void moveMonsters() {

    memset(moved, 0, sizeof(moved));

    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= 4; j++) {
            for (k = 1; k <= 8; k++) {
                if (monsters[i][j][k] > 0) {
                    d = k;
                    isMoved = false;

                    for (cnt = 0; cnt < 8; cnt++) {
                        x = i + mDx[d];
                        y = j + mDy[d];

                        if (x > 0 && x < 5 && y > 0 && y < 5 && dead[x][y] == 0 && (x != pacMan.first || y != pacMan.second)) {
                            moved[x][y][d] += monsters[i][j][k];
                            isMoved = true;
                            break;
                        }

                        d = (d + 1) % 9;

                        if (d == 0) {
                            d = 1;
                        }
                    }

                    if(!isMoved)
                        moved[i][j][k] += monsters[i][j][k];
                }
            }
        }
    }

    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= 4; j++) {
            for (k = 1; k <= 8; k++) {
                monsters[i][j][k] = moved[i][j][k];
            }
        }
    }
}

void pacManMove(int currX, int currY, int moveCnt, int eatCnt, vector<pair<int,int>> route) {
    
    if (moveCnt == 3) {
        if (eatCnt > cnt) {
            pacMan.first = currX;
            pacMan.second = currY;
            finalRoute = route;
            cnt = eatCnt;
        }

        return;
    }

    int monCnt, dir, c;
    bool check;
    for (int i = 0; i < 4; i++) {
        x = currX + pDx[i];
        y = currY + pDy[i];

        if (x > 0 && x < 5 && y > 0 && y < 5) {
            monCnt = 0;
            check = false;

            for (c = 0; c < route.size(); c++) {
                if (route[c].first == x && route[c].second == y) {
                    check = true;
                    break;
                }
            }

            if (!check) {
                for (dir = 1; dir < 9; dir++) {
                    monCnt += monsters[x][y][dir];
                }
            }
            route.push_back({ x,y });
            pacManMove(x, y, moveCnt + 1, eatCnt + monCnt, route);
            route.pop_back();
        }
    }
}

void deadBodyCnt() {

    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= 4; j++) {
            if (dead[i][j] > 0) {
                dead[i][j]++;

                if (dead[i][j] == 3) {
                    dead[i][j] = 0;
                }
            }
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 1; j <= 8; j++) {
            if (monsters[finalRoute[i].first][finalRoute[i].second][j] > 0) {
                monsters[finalRoute[i].first][finalRoute[i].second][j] = 0;
                dead[finalRoute[i].first][finalRoute[i].second] = 1;
            }
        }
    }
}

void bornMonsters() {
    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= 4; j++) {
            for (k = 1; k <= 8; k++) {
                monsters[i][j][k] += copied[i][j][k];
            }
        }
    }
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(dead, 0, sizeof(dead));
    memset(monsters, 0, sizeof(monsters));

    cin >> m >> t;

    cin >> pacMan.first >> pacMan.second;

    int r, c;

    for (i = 0; i < m; i++) {
        cin >> r >> c >> d;

        monsters[r][c][d]++;
    }

    for (int T = 0; T < t; T++) {
        copyMonsters();
        moveMonsters();
        finalRoute.clear();
        cnt = -1;
        pacManMove(pacMan.first, pacMan.second, 0, 0, finalRoute);
        deadBodyCnt();
        bornMonsters();
    }

    cnt = 0;

    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= 4; j++) {
            for (k = 1; k <= 8; k++) {
                cnt += monsters[i][j][k];
            }
        }
    }

    cout << cnt;

    return 0;
}
