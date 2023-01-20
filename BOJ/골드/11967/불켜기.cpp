#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;

bool visited[101][101];
bool isLighted[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int N;
vector<pair<int, int>> v[101][101];

bool check(int x, int y) {
    int nx, ny;

    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];

        if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
            if (visited[nx][ny] && isLighted[nx][ny]) {
                return true;
            }
        }
    }

    return false;
}

int getAns() {

    int ans = 1;
    queue<pair<int, int>> q;
    q.push({ 1,1 });
    visited[1][1] = true;
    isLighted[1][1] = true;

    int x, y, nx, ny;
    int i;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;

        q.pop();

        for (i = 0; i < v[x][y].size(); i++) {

            nx = v[x][y][i].first;
            ny = v[x][y][i].second;

            if (!isLighted[nx][ny]) {
                isLighted[nx][ny] = true;
                ans++;

                if (check(nx, ny)) {
                    q.push({ nx,ny });
                    visited[nx][ny] = true;
                }
            }
        }

        for (i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                if (!visited[nx][ny] && isLighted[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({ nx,ny });
                }
            }
        }
    }

    return ans;
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int M;
    int x, y, a, b;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> x >> y >> a >> b;

        v[x][y].push_back({ a,b });
    }

    memset(visited, false, sizeof(visited));
    memset(isLighted, false, sizeof(isLighted));

    cout << getAns();

    return 0;
}
