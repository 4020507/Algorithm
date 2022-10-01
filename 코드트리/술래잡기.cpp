#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cstdlib>

#define MAX_N 100
#define DIR_NUM 4

using namespace std;

int n, m, h, k;
vector<int> hiders[MAX_N][MAX_N];
vector<int> next_hiders[MAX_N][MAX_N];
bool tree[MAX_N][MAX_N];
int seeker_next_dir[MAX_N][MAX_N];
int seeker_rev_dir[MAX_N][MAX_N];
pair<int, int> seeker_pos;
bool forward_facing = true;

int ans;


void InitializeSeekerPath() {

    int dx[DIR_NUM] = { -1, 0, 1,  0 };
    int dy[DIR_NUM] = { 0 , 1, 0, -1 };

    int curr_x = n / 2, curr_y = n / 2;
    int move_dir = 0, move_num = 1;

    while (curr_x || curr_y) {
        for (int i = 0; i < move_num; i++) {
            seeker_next_dir[curr_x][curr_y] = move_dir;
            curr_x += dx[move_dir]; curr_y += dy[move_dir];
            seeker_rev_dir[curr_x][curr_y] = (move_dir < 2) ? (move_dir + 2) : (move_dir - 2);

            if (!curr_x && !curr_y)
                break;
        }

        move_dir = (move_dir + 1) % 4;

        if (move_dir == 0 || move_dir == 2)
            move_num++;
    }
}

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void HiderMove(int x, int y, int move_dir) {

    int dx[DIR_NUM] = { 0 , 0, 1, -1 };
    int dy[DIR_NUM] = { -1, 1, 0,  0 };

    int nx = x + dx[move_dir], ny = y + dy[move_dir];

    if (!InRange(nx, ny)) {
        move_dir = (move_dir < 2) ? (1 - move_dir) : (5 - move_dir);
        nx = x + dx[move_dir]; ny = y + dy[move_dir];
    }

    if (make_pair(nx, ny) != seeker_pos)
        next_hiders[nx][ny].push_back(move_dir);
    else
        next_hiders[x][y].push_back(move_dir);
}

int DistFromSeeker(int x, int y) {

    int seeker_x, seeker_y;
    tie(seeker_x, seeker_y) = seeker_pos;

    return abs(seeker_x - x) + abs(seeker_y - y);
}

void HiderMoveAll() {

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            next_hiders[i][j].clear();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {

            if (DistFromSeeker(i, j) <= 3) {
                for (int k = 0; k < (int)hiders[i][j].size(); k++)
                    HiderMove(i, j, hiders[i][j][k]);
            }

            else {
                for (int k = 0; k < (int)hiders[i][j].size(); k++)
                    next_hiders[i][j].push_back(hiders[i][j][k]);
            }
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            hiders[i][j] = next_hiders[i][j];
}

int GetSeekerDir() {
    int x, y;
    tie(x, y) = seeker_pos;

    int move_dir;
    if (forward_facing)
        move_dir = seeker_next_dir[x][y];
    else
        move_dir = seeker_rev_dir[x][y];

    return move_dir;
}

void CheckFacing() {

    if (seeker_pos == make_pair(0, 0) && forward_facing)
        forward_facing = false;

    if (seeker_pos == make_pair(n / 2, n / 2) && !forward_facing)
        forward_facing = true;
}

void SeekerMove() {
    int x, y;
    tie(x, y) = seeker_pos;

    int dx[DIR_NUM] = { -1, 0, 1,  0 };
    int dy[DIR_NUM] = { 0 , 1, 0, -1 };

    int move_dir = GetSeekerDir();

    seeker_pos = make_pair(x + dx[move_dir], y + dy[move_dir]);

    CheckFacing();
}

void GetScore(int t) {
    int dx[DIR_NUM] = { -1, 0, 1,  0 };
    int dy[DIR_NUM] = { 0 , 1, 0, -1 };

    int x, y;
    tie(x, y) = seeker_pos;

    int move_dir = GetSeekerDir();

    for (int dist = 0; dist < 3; dist++) {
        int nx = x + dist * dx[move_dir], ny = y + dist * dy[move_dir];
        if (InRange(nx, ny) && !tree[nx][ny]) {
            ans += t * (int)hiders[nx][ny].size();
            hiders[nx][ny].clear();
        }
    }
}

void Simulate(int t) {
    HiderMoveAll();

    SeekerMove();

    GetScore(t);
}

int main() {

    cin >> n >> m >> h >> k;

    while (m--) {
        int x, y, d;
        cin >> x >> y >> d;
        hiders[x - 1][y - 1].push_back(d);
    }

    while (h--) {
        int x, y;
        cin >> x >> y;
        tree[x - 1][y - 1] = true;
    }

    seeker_pos = make_pair(n / 2, n / 2);

    InitializeSeekerPath();

    for (int t = 1; t <= k; t++)
        Simulate(t);

    cout << ans;
    return 0;
}
