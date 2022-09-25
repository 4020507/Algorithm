#include <iostream>
#include <vector>

#define MAX_N 20
#define MAX_M 5
#define DIR_NUM 4

using namespace std;

int n, m, k;
int board[MAX_N + 1][MAX_N + 1];

vector<pair<int, int> > v[MAX_M + 1];
int tail[MAX_M + 1];
bool visited[MAX_N + 1][MAX_N + 1];
int board_idx[MAX_N + 1][MAX_N + 1];

int ans;

int dx[DIR_NUM] = {-1, 0, 1, 0};
int dy[DIR_NUM] = {0, -1, 0, 1};

bool IsOutRange(int x, int y) {
    return !(1 <= x && x <= n && 1 <= y && y <= n);
}

void DFS(int x, int y, int idx) {
    visited[x][y] = true;
    board_idx[x][y] = idx;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(IsOutRange(nx, ny)) continue;

        if(board[nx][ny] == 0) continue;
        if(visited[nx][ny]) continue;
        if((int) v[idx].size() == 1 && board[nx][ny] != 2) continue;

        v[idx].push_back({nx, ny});
        if(board[nx][ny] == 3) tail[idx] = (int) v[idx].size();
        DFS(nx, ny, idx);
    }
}

void Init() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> board[i][j];

    int cnt = 1;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(board[i][j] == 1) v[cnt++].push_back({i, j});

    for(int i = 1; i <= m; i++)
        DFS(v[i][0].first, v[i][0].second, i);
}

void MoveAll() {
    for(int i = 1; i <= m; i++) {
        pair<int, int> tmp = v[i].back();
        for(int j = (int) v[i].size() - 1; j >= 1; j--)
            v[i][j] = v[i][j - 1];
        v[i][0] = tmp;
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < (int) v[i].size(); j++) {
            pair<int, int> x = v[i][j];
            if(j == 0)
                board[x.first][x.second] = 1;
            else if(j < tail[i] - 1)
                board[x.first][x.second] = 2;
            else if(j == tail[i] - 1)
                board[x.first][x.second] = 3;
            else
                board[x.first][x.second] = 4;
        }
    }
}

void GetPoint(int x, int y) {
    int idx = board_idx[x][y];
    int cnt = 0;
    for(int i = 0; i < (int) v[idx].size(); i++)
        if(v[idx][i].first == x && v[idx][i].second == y) cnt = i;
    ans += (cnt + 1) * (cnt + 1);
}

int ThrowBall(int turn) {
    int t = (turn - 1) % (4 * n) + 1;

    if(t <= n) {
        for(int i = 1; i <= n; i++) {
            if(1 <= board[t][i] && board[t][i] <= 3) {
                GetPoint(t, i);
                return board_idx[t][i];
            }
        }
    }
    else if(t <= 2 * n) {
        t -= n;
        for(int i = 1; i <= n; i++) {
            if(1 <= board[n + 1 - i][t] && board[n + 1 - i][t] <= 3) {
                GetPoint(n + 1 - i, t);
                return board_idx[n + 1 - i][t];
            }
        }
    }
    else if(t <= 3 * n) {
        t -= (2 * n);
        for(int i = 1; i <= n; i++) {
            if(1 <= board[n + 1 - t][n + 1 - i] && board[n + 1 - t][n + 1 - i] <= 3) {
                GetPoint(n + 1 - t, n + 1 - i);
                return board_idx[n + 1 - t][n + 1 - i];
            }
        }
    }
    else {
        t -= (3 * n);
        for(int i = 1; i <= n; i++) {
            if(1 <= board[i][n + 1 - t] && board[i][n + 1 - t] <= 3) {
                GetPoint(i, n + 1 - t);
                return board_idx[i][n + 1 - t];
            }
        }
    }
    return 0;
}

void Reverse(int got_ball_idx) {

    if(got_ball_idx == 0) return;

    int idx = got_ball_idx;

    vector<pair<int, int> > new_v;


    for(int i = tail[idx] - 1; i >= 0; i--) {
        pair<int, int> x = v[idx][i];
        new_v.push_back(x);
    }

    for(int i = (int) v[idx].size() - 1; i >= tail[idx]; i--) {
        pair<int, int> x = v[idx][i];
        new_v.push_back(x);
    }

    v[idx] = new_v;

    for(int j = 0; j < (int) v[idx].size(); j++) {
        pair<int, int> x = v[idx][j];
        if(j == 0)
            board[x.first][x.second] = 1;
        else if(j < tail[idx] - 1)
            board[x.first][x.second] = 2;
        else if(j == tail[idx] - 1)
            board[x.first][x.second] = 3;
        else
            board[x.first][x.second] = 4;
    }
}

int main() {

    Init();

    for(int i = 1; i <= k; i++) {

        MoveAll();

        int got_ball_idx = ThrowBall(i);

        Reverse(got_ball_idx);
    }

    cout << ans;
    return 0;
}
