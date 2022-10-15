#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int bombs[20][20];
int rotTemp[20][20];
int n;
int i, j, k;
int cnt, groupIdx;
vector<pair<int,int>> groups[400];
int redCnt[400];
vector<pair<int, int>> reds;
bool counted[20][20];
queue<pair<int, int>> q;
int x, y, nx, ny;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool makeGroups() {

    for (i = 0; i < groupIdx; i++) {
        groups[i].clear();
    }
    groupIdx = 0;
    memset(counted, false, sizeof(counted));

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (bombs[i][j] > 0 && !counted[i][j]) {
                cnt = 0;
                
                q.push({ i,j });
                counted[i][j] = true;
                groups[groupIdx].push_back({ i,j });

                while (!q.empty()) {
                    x = q.front().first;
                    y = q.front().second;

                    q.pop();

                    for (k = 0; k < 4; k++) {
                        nx = x + dx[k];
                        ny = y + dy[k];

                        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                            if (!counted[nx][ny] && (bombs[nx][ny] == 0 || bombs[nx][ny] == bombs[i][j])) {
                                counted[nx][ny] = true;
                                q.push({ nx,ny });

                                groups[groupIdx].push_back({ nx,ny });

                                if (bombs[nx][ny] == 0) {
                                    cnt++;
                                }
                            }
                        }
                    }
                }

                if (groups[groupIdx].size() >= 2) {
                    redCnt[groupIdx] = cnt;
                    groupIdx++;
                }
                else {
                    groups[groupIdx].clear();
                }

                for (auto r : reds) {
                    counted[r.first][r.second] = false;
                }
            }
        }
    }

    if (groupIdx > 0) {
        return true;
    }

    return false;
}

pair<int, int> findStandard(int idx) {

    nx = -1;
    ny = 1e9;

    for (auto g : groups[idx]) {
        if (bombs[g.first][g.second] != 0) {

            if (nx < g.first) {
                nx = g.first;
                ny = g.second;
            }
            else if (nx == g.first) {
                if (ny > g.second) {
                    ny = g.second;
                }
            }
        }
    }

    return { nx,ny };
}
int findBigGroup() {
    int maxCnt = groups[0].size();
    int bigGroupIdx = 0;
    pair<int, int> coord1 = findStandard(0);
    pair<int, int> coord2;

    for (i = 1; i < groupIdx; i++) {

        if (maxCnt < groups[i].size()) {
            maxCnt = groups[i].size();
            bigGroupIdx = i;
            coord1 = findStandard(i);
        }
        else if (maxCnt == groups[i].size()) {

            if (redCnt[bigGroupIdx] != redCnt[i]) {

                if (redCnt[bigGroupIdx] > redCnt[i]) {
                    bigGroupIdx = i;
                    coord1 = findStandard(i);
                }
            }
            else {

                coord2 = findStandard(i);

                if (coord1.first < coord2.first) {
                    coord1 = coord2;
                    bigGroupIdx = i;
                }
                else if (coord1.first == coord2.first) {
                    if (coord1.second > coord2.second) {
                        coord1 = coord2;
                        bigGroupIdx = i;
                    }
                }
            }
        }
    }

    return bigGroupIdx;
}

int removeBombs(int bigGroupIdx) {

    for (auto g : groups[bigGroupIdx]) {

        bombs[g.first][g.second] = -2;
    }

    return groups[bigGroupIdx].size() * groups[bigGroupIdx].size();
}

void fillEmpty() {

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            rotTemp[i][j] = -2;
        }
    }

    int tIndex;

    for (j = 0; j < n; j++) {
        tIndex = n - 1;
        for (i = n - 1; i >= 0; i--) {

            if (bombs[i][j] != -2) {

                if (bombs[i][j] == -1) {
                    tIndex = i;
                }

                rotTemp[tIndex--][j] = bombs[i][j];
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            bombs[i][j] = rotTemp[i][j];
        }
    }
}

void rotate() {

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            rotTemp[i][j] = bombs[j][n - 1 - i];
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            bombs[i][j] = rotTemp[i][j];
        }
    }
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m;

    cin >> n >> m;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> bombs[i][j];

            if (bombs[i][j] == 0) {
                reds.push_back({ i,j });
            }
        }
    }

    int ans = 0;

    while (makeGroups()) {
        ans += removeBombs(findBigGroup());

        fillEmpty();
        rotate();
        fillEmpty();

        reds.clear();
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (bombs[i][j] == 0) {
                    reds.push_back({ i,j });
                }
            }
        }
    }

    cout << ans;

    return 0;
}
