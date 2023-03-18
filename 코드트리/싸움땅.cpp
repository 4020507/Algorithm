#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

priority_queue<int> matrix[20][20];
int playerNum[20][20];
int n, m;
vector<pair<pair<int, int>, pair<int, pair<int, int>>>> players; //x,y d,s,g
int score[30];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };


void move() {

    int x, y, nx, ny;
    int sum1, sum2;
    int pNum;
    int winNum, loseNum;
    int gun;

    for (int p = 0; p < m; p++) {

        playerNum[players[p].first.first][players[p].first.second] = -1;
        //1-1
        x = players[p].first.first + dx[players[p].second.first];
        y = players[p].first.second + dy[players[p].second.first];

        if (x < 0 || x >= n || y < 0 || y >= n) {
            players[p].second.first = (players[p].second.first + 2) % 4;

            x = players[p].first.first + dx[players[p].second.first];
            y = players[p].first.second + dy[players[p].second.first];
        }

        //2-1
        if (playerNum[x][y] == -1) {
            playerNum[x][y] = p;
            players[p].first.first = x;
            players[p].first.second = y;
            gun = matrix[x][y].top();

            if (gun > players[p].second.second.second) {
                matrix[x][y].pop();
                matrix[x][y].push(players[p].second.second.second);
                players[p].second.second.second = gun;
            }
        }
        else {//2-2
            //기존
            pNum = playerNum[x][y];
            sum1 = players[pNum].second.second.first + players[pNum].second.second.second;

            //현재 플레이어
            sum2 = players[p].second.second.first + players[p].second.second.second;

            if ((sum1 > sum2) || ((sum1 == sum2) && (players[pNum].second.second.first > players[p].second.second.first))) {
                winNum = pNum;
                loseNum = p;
            }
            else {
                winNum = p;
                loseNum = pNum;
            }

            score[winNum] += abs(sum1 - sum2);
            playerNum[x][y] = winNum;
            players[winNum].first.first = x;
            players[winNum].first.second = y;

            //2-2-2
            matrix[x][y].push(players[loseNum].second.second.second);
            players[loseNum].second.second.second = 0;

            while (1) {
                nx = x + dx[players[loseNum].second.first];
                ny = y + dy[players[loseNum].second.first];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n || playerNum[nx][ny] != -1) {
                    players[loseNum].second.first = (players[loseNum].second.first + 1) % 4;
                }
                else {
                    players[loseNum].first.first = nx;
                    players[loseNum].first.second = ny;
                    playerNum[nx][ny] = loseNum;
                    gun = matrix[nx][ny].top();

                    if (gun != 0) {
                        players[loseNum].second.second.second = gun;
                        matrix[nx][ny].pop();
                        matrix[nx][ny].push(0);
                    }

                    break;
                }
            }

            //2-2-3
            gun = matrix[x][y].top();
            if (players[winNum].second.second.second < gun) {
                matrix[x][y].pop();
                matrix[x][y].push(players[winNum].second.second.second);
                players[winNum].second.second.second = gun;
            }

        }
    }
}


int main() {
    // 여기에 코드를 작성해주세요.

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int k;

    cin >> n >> m >> k;

    int i, j;
    int gun;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> gun;
            matrix[i][j].push(gun);
            playerNum[i][j] = -1;
        }
    }

    int x, y, d, s;

    for (i = 0; i < m; i++) {
        cin >> x >> y >> d >> s;
        x--; y--;

        players.push_back({ {x,y},{d,{s,0}} });
        playerNum[x][y] = i;
        score[i] = 0;
    }

    for (int t = 0; t < k; t++) {
        move();
    }

    for (i = 0; i < m; i++) {
        cout << score[i] << ' ';
    }
    return 0;
}
