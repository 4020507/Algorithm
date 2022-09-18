#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

int picture[30][30];//그림
int group[30][30];//그룹번호
int n;
int i, j, k;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int score;
int groupCnt[900];//그룹개수
bool visited[30][30];
int rotateTemp[30][30];
int nx, ny;
int cx;
int cy;

void makeGroup(int x, int y, int groupNum, int num) {

    queue<pair<int, int>> q;
    q.push({ x,y });
    group[x][y] = groupNum;
    groupCnt[groupNum] = 1;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;

        q.pop();

        for (k = 0; k < 4; k++) {
            nx = x + dx[k];
            ny = y + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (picture[nx][ny] == num && group[nx][ny] == 0) {
                    group[nx][ny] = groupNum;
                    groupCnt[groupNum]++;
                    q.push({ nx,ny });
                }
            }
        }
    }
}

int artScore() {

    memset(visited, false, sizeof(visited));
    int sum = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (!visited[i][j]) {
                visited[i][j] = true;

                for (k = 0; k < 4; k++) {
                    nx = i + dx[k];
                    ny = j + dy[k];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        if (picture[i][j] != picture[nx][ny]) {
                            sum += (groupCnt[group[i][j]] + groupCnt[group[nx][ny]]) * picture[i][j] * picture[nx][ny];
                        }
                    }
                }
            }
        }
    }

    return sum / 2;
}

void rotateCenter() {

    int cnt = 1;
    int temp;

    while (cx - cnt >= 0) {
        temp = picture[cx - cnt][cy];
        picture[cx - cnt][cy] = picture[cx][cy + cnt];
        picture[cx][cy + cnt] = picture[cx + cnt][cy];
        picture[cx + cnt][cy] = picture[cx][cy - cnt];
        picture[cx][cy - cnt] = temp;
        cnt++;
    }
}

void rotateOthers() {
    for (i = 0; i < cx; i++) {
        for (j = 0; j < cy; j++) {
            rotateTemp[i][j] = picture[cy - j - 1][i];
        }
    }

    for (i = 0; i < cx; i++) {
        for (j = 0; j < cy; j++) {
            picture[i][j] = rotateTemp[i][j];
        }
    }


    for (i = 0; i < cx; i++) {
        for (j = cy + 1; j < n; j++) {
            rotateTemp[i][j] = picture[n - j - 1][i + cx + 1];
        }
    }

    for (i = 0; i < cx; i++) {
        for (j = cy + 1; j < n; j++) {
            picture[i][j] = rotateTemp[i][j];
        }
    }


    for (i = cx + 1; i < n; i++) {
        for (j = 0; j < cy; j++) {
            rotateTemp[i][j] = picture[n - j - 1][i - cx - 1];
        }
    }

    for (i = cx + 1; i < n; i++) {
        for (j = 0; j < cy; j++) {
            picture[i][j] = rotateTemp[i][j];
        }
    }


    for (i = cx + 1; i < n; i++) {
        for (j = cy + 1; j < n; j++) {
            rotateTemp[i][j] = picture[n - j + cy][i];
        }
    }

    for (i = cx + 1; i < n; i++) {
        for (j = cy + 1; j < n; j++) {
            picture[i][j] = rotateTemp[i][j];
        }
    }
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    cx = n / 2;
    cy = cx;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> picture[i][j];
        }
    }

    score = 0;
    int groupNum;
    for (int t = 0; t < 4; t++) {

        memset(group, 0, sizeof(group));
        groupNum = 1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (group[i][j] == 0) {
                    makeGroup(i, j, groupNum++, picture[i][j]);
                }
            }
        }

        score += artScore();

        rotateCenter();
        rotateOthers();
    }

    cout << score;

    return 0;
}
