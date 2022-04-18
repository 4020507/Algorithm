#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;
char maze[50][50];
pair<int, int> key[251];
pair<int, int> start;
vector<pair<int, pair<int,int>>> dist;
bool visited[50][50];

int parent[251];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool bfs(int x, int y, int idx) {
    queue<pair<int, pair<int,int>>> q;
    q.push({ 0,{x,y} });

    int nx, ny, cost;
    memset(visited, false, sizeof(visited));
    visited[x][y] = true;

    bool check = false;
    int i, j;
    while (!q.empty()) {
        x = q.front().second.first;
        y = q.front().second.second;
        cost = q.front().first;
        q.pop();
        for (i = 0;i < 4;i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if (!visited[nx][ny] && maze[nx][ny] != '1') {
                    visited[nx][ny] = true;
                    q.push({ cost + 1,{nx,ny} });

                    if (maze[nx][ny] == 'K') {
                        for (j = 0;j < M;j++) {
                            if (key[j].first == nx && key[j].second == ny) {
                                dist.push_back({ cost + 1,{idx,j} });
                                break;
                            }
                        }
                    }
                    else if (maze[nx][ny] == 'S') {
                        dist.push_back({ cost + 1,{idx,0} });
                        check = true;
                    }
                }
            }
        }
    }


    return check;
}

int findParent(int p) {
    if (parent[p] == p)
        return p;
    return parent[p] = findParent(parent[p]);
}

void Union(int p1, int p2) {
    p1 = findParent(p1);
    p2 = findParent(p2);

    if (p1 < p2)
        parent[p2] = p1;
    else
        parent[p1] = p2;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int index = 1;
    cin >> N >> M;

    int i, j;
    for (i = 0;i < N;i++)
        for (j = 0;j < N;j++) {
            cin >> maze[i][j];

            if (maze[i][j] == 'S') {
                start.first = i;
                start.second = j;
            }
            else if (maze[i][j] == 'K') {
                key[index].first = i;
                key[index++].second = j;
            }
        }

    for (i = 1;i <= M;i++) {
        if (!bfs(key[i].first, key[i].second, i)) {
            cout << -1;
            return 0;
        }
    }
    for (i = 1;i <= M;i++)
        parent[i] = i;

    sort(dist.begin(), dist.end());
    int cost;
    int ans = 0;
    int p1, p2;

    for (auto d : dist) {
        cost = d.first;
        p1 = d.second.first;
        p2 = d.second.second;

        p1 = findParent(p1);
        p2 = findParent(p2);

        if (p1 != p2) {
            Union(p1, p2);
            ans += cost;
        }
    }

    cout << ans;

    return 0;

}
