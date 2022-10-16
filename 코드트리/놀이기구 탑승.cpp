#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int matrix[20][20];
int friends[401][401];
int n;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void findMySeat(int myNum) {

    int x, y, emptySeat, friendsCnt, tEmpty, tFriends, nx, ny, k;
    x = 21;
    y = 21;
    emptySeat = 0;
    friendsCnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (matrix[i][j] == 0) {
                tEmpty = 0;
                tFriends = 0;
                for (k = 0; k < 4; k++) {
                    nx = i + dx[k];
                    ny = j + dy[k];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {

                        if (matrix[nx][ny] == 0) {
                            tEmpty++;
                        }
                        else {
                            if (friends[myNum][matrix[nx][ny]] == 1) {
                                tFriends++;
                            }
                        }
                    }
                }

                if (friendsCnt < tFriends) {
                    x = i;
                    y = j;
                    friendsCnt = tFriends;
                    emptySeat = tEmpty;
                }
                else if (friendsCnt == tFriends) {
                    if (emptySeat < tEmpty) {
                        x = i;
                        y = j;
                        friendsCnt = tFriends;
                        emptySeat = tEmpty;
                    }
                    else if (emptySeat == tEmpty) {
                        if (i < x) {
                            x = i;
                            y = j;
                        }
                        else if (i == x) {
                            if (j < y) {
                                y = j;
                            }
                        }
                    }
                }
            }
        }
    }

    matrix[x][y] = myNum;
}

int earnScore() {

    int calc;
    int x, y, i, j, k;
    int scoreList[5] = { 0,1,10,100,1000 };
    int score = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            calc = 0;

            for (k = 0; k < 4; k++) {
                x = i + dx[k];
                y = j + dy[k];

                if (x >= 0 && x < n && y >= 0 && y < n) {
                    if (friends[matrix[i][j]][matrix[x][y]] == 1) {
                        calc++;
                    }
                }
            }

            score += scoreList[calc];
        }
    }

    return score;
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    int n0, n1, n2, n3, n4, i;

    for (i = 0; i < n * n; i++) {
        cin >> n0 >> n1 >> n2 >> n3 >> n4;

        friends[n0][n1] = 1;
        friends[n0][n2] = 1;
        friends[n0][n3] = 1;
        friends[n0][n4] = 1;

        findMySeat(n0);
    }

    cout << earnScore();

    return 0;
}
