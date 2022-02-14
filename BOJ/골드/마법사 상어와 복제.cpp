#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int matrix[5][5];
int fish[5][5][9];
int copied[5][5][9];
int moved[5][5][9];
int smell[5][5];

pair<int, int> shark;
int M, S;

int dx[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int dy[9] = { 0,-1,-1,0,1,1,1,0,-1 };

void remains()
{
    for (int i = 1;i <= 4;i++)
        for (int j = 1;j <= 4;j++)
            for (int k = 1;k < 9;k++)
                copied[i][j][k] = fish[i][j][k];
}

void move_fish()
{
    memset(moved, 0, sizeof(moved));
    int x, y;
    int cnt, next;

    for (int i = 1;i <= 4;i++)
    {
        for (int j = 1;j <= 4;j++)
        {
            for (int k = 1;k < 9;k++)
            {
                if (fish[i][j][k] > 0)
                {
                    cnt = 0;
                    next = k;
                    while (cnt < 8)
                    {
                        x = i + dx[next];
                        y = j + dy[next];

                        if (x >= 1 && x <= 4 && y >= 1 && y <= 4)
                        {
                            if ((x != shark.first || y != shark.second) && smell[x][y] == 0)
                            {
                                moved[x][y][next] += fish[i][j][k];
                                break;
                            }
                            
                        }

                        next--;

                        if (next == 0)
                            next = 8;
                        cnt++;
                    }

                    if (cnt == 8)
                        moved[i][j][k] += fish[i][j][k];
                }
            }
        }
    }

    for (int i = 1;i <= 4;i++)
        for (int j = 1;j <= 4;j++)
            for (int k = 1;k < 9;k++)
                fish[i][j][k] = moved[i][j][k];
}

int dx_shark[4] = { -1,0,1,0 };
int dy_shark[4] = { 0,-1,0,1 };
vector<pair<int, int>> update_smell;
int eat_max;

void move_shark(int x, int y, int eat, int curr, vector<pair<int,int>> trace)
{
    if (curr == 3)
    {
        if (eat_max < eat)
        {
            eat_max = eat;
            update_smell = trace;
        }
        else if (eat_max == 0 && update_smell.size() == 0)
            update_smell = trace;

        return;
    }

    int nx, ny;
    int fish_cnt;
    int temp[5][5][9];
    for (int i = 0;i < 4;i++)
    {
        nx = x + dx_shark[i];
        ny = y + dy_shark[i];

        if (nx >= 1 && nx <= 4 && ny >= 1 && ny <= 4)
        {
            fish_cnt = 0;

            for (int j = 1;j < 9;j++) {
                fish_cnt += fish[nx][ny][j];
                temp[nx][ny][j] = fish[nx][ny][j];
                fish[nx][ny][j] = 0;
            }

            trace.push_back({ nx,ny });
            move_shark(nx, ny, eat + fish_cnt, curr + 1, trace);

            for (int j = 1;j < 9;j++)
                fish[nx][ny][j] = temp[nx][ny][j];
            trace.pop_back();
            
        }
    }
}

void faint()
{
    for (int i = 1;i <= 4;i++) {
        for (int j = 1;j <= 4;j++) {
            if (smell[i][j] > 0) {
                smell[i][j]--;
            }
            for (int k = 1;k < 9;k++)
                fish[i][j][k] += copied[i][j][k];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> M >> S;

    int x, y, d;
    memset(fish, 0, sizeof(fish));
    for (int i = 0;i < M;i++)
    {
        cin >> x >> y >> d;

        fish[x][y][d]++;
    }

    cin >> shark.first >> shark.second;
    memset(smell, 0, sizeof(smell));
    
    for (int i = 0;i < S;i++)
    {
        remains();
        move_fish();
        update_smell.clear();

        eat_max = 0;
        move_shark(shark.first, shark.second, 0, 0, update_smell);

        shark.first = update_smell[2].first;
        shark.second = update_smell[2].second;

        for (auto u : update_smell) {
            for (int j = 1;j <= 8;j++) {
                if (fish[u.first][u.second][j] > 0) {
                    fish[u.first][u.second][j] = 0;
                    smell[u.first][u.second] = 3;
                }
            }
        }

        faint();
    }

    int ans = 0;

    for (int i = 1;i <= 4;i++)
        for (int j = 1;j <= 4;j++)
            for (int k = 1;k < 9;k++) {
                if(fish[i][j][k] > 0)
                    ans += fish[i][j][k];
            }

    cout << ans;

    return 0;
}
