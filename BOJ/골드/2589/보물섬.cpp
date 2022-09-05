#include <iostream>
#include<string.h>
#include<queue>
using namespace std;

bool visited[50][50];
char map[50][50];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int N, M;
int bfs(int x, int y) {

    queue < pair<int, pair<int, int>>> q;
    q.push({ 0,{x,y} });

    memset(visited, false, sizeof(visited));
    visited[x][y] = true;

    int steps = 0;
    int nx, ny, i;
    int longest = 0;

    while (!q.empty()) {
        steps = q.front().first;
        x = q.front().second.first;
        y = q.front().second.second;

        longest = longest > steps ? longest : steps;

        q.pop();

        for (i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (!visited[nx][ny] && map[nx][ny] == 'L') {
                    visited[nx][ny] = true;
                    q.push({ steps + 1,{nx,ny} });
                }
            }
        }
    }

    return longest;
}

int main(int argc, const char* argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    int ans = 0;
    int steps;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'L') {
                steps = bfs(i, j);
                ans = ans > steps ? ans : steps;
            }
        }
    }

    cout << ans;

    return 0;
}
