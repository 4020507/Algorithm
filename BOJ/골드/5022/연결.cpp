#include <iostream>
#include <cstring>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 101
#define INF 987654321
using namespace std;

typedef pair<int, int> pos;

struct node {
    int x, y;
    vector<pos> path;

    node() { }
    node(int _x, int _y, vector<pos> v) : x(_x), y(_y), path(v) { }
};

int n, m, ans, cnt;
int rx1, ry1, rx2, ry2;
int bx1, by1, bx2, by2;
bool r_end, b_end;

bool visited[MAX][MAX];
bool done[MAX][MAX];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

node a, b;

void bfs(int x1, int y1, int x2, int y2, int turn) {
    queue<node> q;
    vector<pos> v;
    v.push_back(pos(x1, y1));
    q.push(node(x1, y1, v));
    visited[x1][y1] = true;
    done[x1][y1] = true;

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        vector<pos> path = q.front().path;
        q.pop();

        if (x == x2 && y == y2) {

            for (int i = 0; i < path.size(); i++) {
                int xx = path[i].first;
                int yy = path[i].second;

                done[xx][yy] = true;
            }

            if (turn == 1) r_end = true;
            else b_end = true;

            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            vector<pos> nv;

            for (int j = 0; j < path.size(); j++) {
                nv.push_back(path[j]);
            }

            if (nx<0 || ny<0 || nx>n || ny>m) continue;
            if (turn == 1 && ((nx == bx1 && ny == by1) || (nx == bx2 && ny == by2))) continue;
            if (turn == 2 && ((nx == rx1 && ny == ry1) || (nx == rx2 && ny == ry2))) continue;

            if (!visited[nx][ny] && !done[nx][ny]) {
                nv.push_back(pos(nx, ny));
                q.push(node(nx, ny, nv));
                visited[nx][ny] = true;
            }
        }
    }
}

int main(int argc, const char* argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> m >> n;

    cin >> ry1 >> rx1;
    cin >> ry2 >> rx2;
    cin >> by1 >> bx1;
    cin >> by2 >> bx2;

    ans = INF;

    memset(visited, false, sizeof(visited));
    memset(done, false, sizeof(done));
    r_end = false;
    bfs(rx1, ry1, rx2, ry2, 1);

    memset(visited, false, sizeof(visited));
    b_end = false;
    bfs(bx1, by1, bx2, by2, 2);

    cnt = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (done[i][j])
                cnt++;
        }
    }

    if (r_end && b_end)
        ans = min(ans, cnt - 2);

    memset(visited, false, sizeof(visited));
    memset(done, false, sizeof(done));
    b_end = false;
    bfs(bx1, by1, bx2, by2, 2);

    memset(visited, false, sizeof(visited));
    r_end = false;
    bfs(rx1, ry1, rx2, ry2, 1);

    cnt = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (done[i][j])
                cnt++;
        }
    }

    if (r_end && b_end)
        ans = min(ans, cnt - 2);

    if (ans == INF)
        cout << "IMPOSSIBLE" << "\n";
    else
        cout << ans << "\n";

    return 0;
}
