#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
#include<queue>
#include<math.h>
using namespace std;

int n, m, k;
int office[21][21];
int coolDegree[21][21];
int tempCoolDegree[21][21];
bool wall[21][21][4];//0: 위가 벽, 1: 왼쪽이 벽, 2: 아래가 벽, 3: 오른쪽이 벽
pair<int, pair<int,int>> airconditional[401];//2:왼, 3: 위, 4: 오른, 5: 아래
bool spreaded[21][21];
int condCnt;

int x, y, w, strength;
int i, j, quotient;

void left(int index) {
    queue<pair<int, pair<int,int>>>q;

    q.push({ 5,{airconditional[index].second.first,airconditional[index].second.second - 1} });
    coolDegree[airconditional[index].second.first][airconditional[index].second.second - 1] += 5;

    while (!q.empty()) {
        x = q.front().second.first;
        y = q.front().second.second;
        strength = q.front().first - 1;
        q.pop();

        if (strength == 0 || y - 1 < 1) {
            continue;
        }

        //왼쪽 위
        if (x - 1 > 0) {
            if (!wall[x][y][0] && !wall[x - 1][y][1] && !spreaded[x-1][y-1]) {
                coolDegree[x - 1][y - 1] += strength;
                spreaded[x - 1][y - 1] = true;
                q.push({ strength,{x - 1,y - 1} });
            }
        }

        //왼쪽
        if (!wall[x][y][1] && !spreaded[x][y-1]) {
            coolDegree[x][y - 1] += strength;
            spreaded[x][y - 1] = true;
            q.push({ strength,{x,y - 1} });
        }

        //왼쪽 아래
        if (x + 1 <= n) {
            if (!wall[x][y][2] && !wall[x + 1][y][1] && !spreaded[x+1][y-1]) {
                coolDegree[x + 1][y - 1] += strength;
                spreaded[x + 1][y - 1] = true;
                q.push({ strength,{x + 1,y - 1} });
            }
        }
    }
}

void up(int index) {
    queue<pair<int, pair<int, int>>>q;

    q.push({ 5,{airconditional[index].second.first - 1,airconditional[index].second.second} });
    coolDegree[airconditional[index].second.first - 1][airconditional[index].second.second] += 5;

    while (!q.empty()) {
        x = q.front().second.first;
        y = q.front().second.second;
        strength = q.front().first - 1;
        q.pop();

        if (strength == 0 || x - 1 == 0) {
            continue;
        }

        //왼쪽 위
        if (y - 1 > 0) {
            if (!wall[x][y][1] && !wall[x][y - 1][0] && !spreaded[x - 1][y - 1]) {
                coolDegree[x - 1][y - 1] += strength;
                spreaded[x - 1][y - 1] = true;
                q.push({ strength,{x - 1,y - 1} });
            }
        }

        //위
        if (!wall[x][y][0] && !spreaded[x - 1][y]) {
            coolDegree[x - 1][y] += strength;
            spreaded[x - 1][y] = true;
            q.push({ strength,{x - 1,y} });
        }

        //오른쪽 위
        if (y + 1 <= n) {
            if (!wall[x][y][3] && !wall[x][y + 1][0] && !spreaded[x - 1][y + 1]) {
                coolDegree[x - 1][y + 1] += strength;
                spreaded[x - 1][y + 1] = true;
                q.push({ strength,{x - 1,y + 1} });
            }
        }
    }
}

void right(int index) {
    queue<pair<int, pair<int, int>>> q;
    q.push({ 5,{airconditional[index].second.first,airconditional[index].second.second + 1} });
    coolDegree[airconditional[index].second.first][airconditional[index].second.second + 1] += 5;

    while (!q.empty()) {
        x = q.front().second.first;
        y = q.front().second.second;
        strength = q.front().first - 1;

        q.pop();

        if (strength == 0 || y + 1 > n) {
            continue;
        }

        //오른쪽 위
        if (x - 1 > 0) {
            if (!wall[x][y][0] && !wall[x - 1][y][3] && !spreaded[x - 1][y + 1]) {
                coolDegree[x - 1][y + 1] += strength;
                spreaded[x - 1][y + 1] = true;
                q.push({ strength,{x - 1,y + 1} });
            }
        }

        //오른쪽
        if (!wall[x][y][3] && !spreaded[x][y + 1]) {
            coolDegree[x][y + 1] += strength;
            spreaded[x][y + 1] = true;
            q.push({ strength,{x,y + 1} });
        }

        //오른쪽 아래
        if (x + 1 <= n) {
            if (!wall[x][y][2] && !wall[x + 1][y][3] && !spreaded[x+1][y+1]) {
                coolDegree[x + 1][y + 1] += strength;
                spreaded[x + 1][y + 1] = true;
                q.push({ strength,{x + 1,y + 1} });
            }
        }
    }
}

void down(int index) {

    queue<pair<int, pair<int, int>>>q;
    q.push({ 5,{airconditional[index].second.first + 1, airconditional[index].second.second} });
    coolDegree[airconditional[index].second.first + 1][airconditional[index].second.second] += 5;

    while (!q.empty()) {
        x = q.front().second.first;
        y = q.front().second.second;
        strength = q.front().first - 1;

        q.pop();

        if (strength == 0 || x + 1 > n) {
            continue;
        }

        //왼쪽 아래
        if (y - 1 > 0) {
            if (!wall[x][y][1] && !wall[x][y - 1][2] && !spreaded[x + 1][y - 1]) {
                coolDegree[x + 1][y - 1] += strength;
                spreaded[x + 1][y - 1] = true;
                q.push({ strength,{x,y - 1} });
            }
        }

        //아래
        if (!wall[x][y][2] && !spreaded[x + 1][y]) {
            coolDegree[x + 1][y] += strength;
            spreaded[x + 1][y] = true;
            q.push({ strength,{x + 1,y} });
        }

        //오른쪽 아래
        if (y + 1 <= n && !wall[x][y][3] && !wall[x][y + 1][2] && !spreaded[x + 1][y + 1]) {
            coolDegree[x + 1][y + 1] += strength;
            spreaded[x + 1][y + 1] = true;
            q.push({ strength,{x + 1,y + 1} });
        }
    }
}

void coolingController(int index) {

    if (airconditional[index].first == 2) {
        left(index);
    }
    else if (airconditional[index].first == 3) {
        up(index);
    }
    else if (airconditional[index].first == 4) {
        right(index);
    }
    else {
        down(index);
    }
}

void mixAir() {

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            //위
            if (i - 1 > 0 && !wall[i][j][0]) {
                quotient = (coolDegree[i][j] - coolDegree[i - 1][j]) / 4;

                tempCoolDegree[i][j] -= quotient;
            }

            //왼쪽
            if (j - 1 > 0 && !wall[i][j][1]) {
                quotient = (coolDegree[i][j] - coolDegree[i][j - 1]) / 4;

                tempCoolDegree[i][j] -= quotient;
            }

            //아래
            if (i + 1 <= n && !wall[i][j][2]) {
                quotient = (coolDegree[i][j] - coolDegree[i + 1][j]) / 4;

                tempCoolDegree[i][j] -= quotient;
            }

            //오른쪽
            if (j + 1 <= n && !wall[i][j][3]) {
                quotient = (coolDegree[i][j] - coolDegree[i][j + 1]) / 4;

                tempCoolDegree[i][j] -= quotient;
            }
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            coolDegree[i][j] += tempCoolDegree[i][j];
        }
    }
}

void decreaseBorders() {

    for (j = 1; j <= n; j++) {

        if (coolDegree[1][j] > 0) {
            coolDegree[1][j]--;
        }

        if (coolDegree[n][j] > 0) {
            coolDegree[n][j]--;
        }
    }

    for (i = 2; i <= n - 1; i++) {

        if (coolDegree[i][1] > 0) {
            coolDegree[i][1]--;
        }

        if (coolDegree[i][n] > 0) {
            coolDegree[i][n]--;
        }
    }
}

bool check() {

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (office[i][j] == 1 && coolDegree[i][j] < k) {
                return false;
            }
        }
    }

    return true;
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    condCnt = 0;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> office[i][j];

            wall[i][j][0] = false;
            wall[i][j][1] = false;

            if (office[i][j] >= 2) {
                airconditional[condCnt++] = { office[i][j],{i,j} };
            }
        }
    }
    
    for (i = 0; i < m; i++) {
        cin >> x >> y >> w;
        wall[x][y][w] = true;

        if (w == 0) {
            wall[x - 1][y][2] = true;
        }
        else {
            wall[x][y - 1][3] = true;
        }
    }

    int minutes = 0;
    int t;

    while (!check()) {

        if (minutes > 100) {
            minutes = -1;
            break;
        }

        for (t = 0; t < condCnt; t++) {
            memset(spreaded, false, sizeof(spreaded));
            coolingController(t);
        }

        memset(tempCoolDegree, 0, sizeof(tempCoolDegree));
        mixAir();
        
        decreaseBorders();

        minutes++;
    }

    cout << minutes;


    return 0;
}
