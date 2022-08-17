#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int dist[22][22][22];
bool check[22][22][22];
char map[22][22];
vector<pair<pair<int, int>, int>> trash;
int sx, sy;
void bfs(int x, int y, int pos) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    dist[x][y][pos] = 0;
    check[x][y][pos] = true;
    while (!q.empty()) {
        int px = q.front().first;
        int py = q.front().second;
        q.pop();
 
        for (int i = 0; i < 4; i++) {
            int nx = px + dx[i];
            int ny = py + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (!check[nx][ny][pos] && map[nx][ny] != 'x') {
                    check[nx][ny][pos] = true;
                    dist[nx][ny][pos] = dist[px][py][pos] + 1;
                    q.push({ nx,ny });
                }
            }
        }
    }
}
int main() {
    while (scanf(" %d %d", &m, &n) != -1) {
        if (n == 0 && m == 0) break;
        for (int i = 0; i < 22; i++) {
            for (int j = 0; j < 22; j++) {
                for (int k = 0; k < 22; k++) {
                    dist[i][j][k] = 1e5;
                }
            }
        }
        memset(check, 0, sizeof(check));
        memset(map, 0, sizeof(map));
        trash.clear();
        sx = sy = 0;
        int tcnt = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf(" %1c", &map[i][j]);
                if (map[i][j] == '*') trash.push_back({ { i,j }, tcnt++ });
                if (map[i][j] == 'o')sx = i, sy = j;
            }
        }
        int ans = 1e5;
        int cnt = trash.size();
        if (cnt == 0) {
            puts("0"); continue;
        }
        bfs(sx, sy, 0);
        sort(trash.begin(), trash.end());
        for (int i = 0; i < cnt; i++) bfs(trash[i].first.first, trash[i].first.second, trash[i].second);
        do {
            int temp = dist[trash[0].first.first][trash[0].first.second][0];
            for (int i = 0; i < cnt - 1; i++) temp += dist[trash[i + 1].first.first][trash[i + 1].first.second][trash[i].second];
            ans = min(ans, temp);
        } while (next_permutation(trash.begin(), trash.end()));
        printf("%d\n", ans == 1e5 ? -1 : ans);
    }
}
