#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
pair<int, int> person[30];
pair<int, int> store[30];
vector<pair<int, int>> camp;
int matrix[30][30];
int n, m;
bool visited[30][30];

bool canMove(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < n && matrix[x][y] != 2 && !visited[x][y]) {
        return true;
    }

    return false;
}

void nextStep(int pNum) {

    if (person[pNum] == store[pNum]) {
        return;
    }

    if (person[pNum].first == -1) {
        return;
    }

    int i, j;
    int x, y, nx, ny;

    int nextX, nextY;
    int minDist = 999999999;
    int d;

    for (i = 0; i < 4; i++) {
        x = person[pNum].first + dx[i];
        y = person[pNum].second + dy[i];
        memset(visited, false, sizeof(visited));

        if (canMove(x, y)) {
            visited[x][y] = true;
            queue<pair<int, pair<int, int>>> q;
            q.push({ 1,{x,y} });

            while (!q.empty()) {
                d = q.front().first;
                x = q.front().second.first;
                y = q.front().second.second;
                q.pop();

                if (x == store[pNum].first && y == store[pNum].second) {
                    if (d < minDist) {
                        minDist = d;
                        nextX = person[pNum].first + dx[i];
                        nextY = person[pNum].second + dy[i];
                        break;
                    }
                }

                for (j = 0; j < 4; j++) {
                    nx = x + dx[j];
                    ny = y + dy[j];

                    if (canMove(nx, ny)) {
                        visited[nx][ny] = true;
                        q.push({ d + 1,{nx,ny} });
                    }
                }
            }
        }
    }

    person[pNum] = { nextX,nextY };

    if (person[pNum] == store[pNum]) {
        matrix[nextX][nextY] = 2;
    }
}

bool inCamp() {
    int arrivedCnt = 0;

    for (int i = 1; i <= m; i++) {
        if (person[i] == store[i]) {
            arrivedCnt++;
        }
    }

    if (arrivedCnt == m) {
        return true;
    }

    return false;
}

void setCamp(int pNum) {
    int nextX, nextY;
    int x, y, nx, ny;
    int i, j;
    int d;
    int minD = 99999999;

    for (i = 0; i < camp.size(); i++) {
        x = camp[i].first;
        y = camp[i].second;

        if (matrix[x][y] != 2) {
            queue<pair<int, pair<int, int>>> q;
            memset(visited, false, sizeof(visited));
            visited[x][y] = true;
            q.push({ 0,{x,y} });

            while (!q.empty()) {
                d = q.front().first;
                x = q.front().second.first;
                y = q.front().second.second;

                q.pop();

                if (d > minD) {
                    break;
                }

                if (x == store[pNum].first && y == store[pNum].second) {
                    if (d < minD) {
                        nextX = camp[i].first;
                        nextY = camp[i].second;
                        minD = d;
                    }
                    else if (d == minD) {
                        if (x < nextX) {
                            nextX = camp[i].first;
                            nextY = camp[i].second;
                        }
                        else if (x == nextX) {
                            if (y < nextY) {
                                nextY = camp[i].second;
                            }
                        }
                    }
                }

                for (j = 0; j < 4; j++) {
                    nx = x + dx[j];
                    ny = y + dy[j];

                    if (canMove(nx, ny)) {
                        q.push({ d + 1,{nx,ny} });
                        visited[nx][ny] = true;
                    }
                }
            }
        }
    }

    person[pNum] = { nextX,nextY };
    matrix[nextX][nextY] = 2;
}

int main() {
    // 여기에 코드를 작성해주세요.

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    int i;

    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];

            if (matrix[i][j] == 1) {
                camp.push_back({ i,j });
            }
        }
    }

    int x, y;

    for (i = 1; i <= m; i++) {
        cin >> x >> y;
        store[i] = { x - 1,y - 1 };
        person[i] = { -1,-1 };
    }

    int min = 1;

    while (1) {

        for (i = 1; i <= m; i++) {
            nextStep(i);
        }

        if (inCamp()) {
            break;
        }

        if (min <= m) {
            setCamp(min);
        }

        min++;
    }

    cout << min;

    return 0;
}
