#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int N, M;
int map[100][100];
vector<pair<int, int>> islands[7];
vector<pair<int, pair<int, int>>> dist;
bool visited[100][100];
int parent[7];
int islandNum;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int findParent(int p) {
    if (parent[p] == p) {
        return p;
    }

    return parent[p] = findParent(parent[p]);
}

void Union(int p1, int p2) {
    p1 = findParent(p1);
    p2 = findParent(p2);

    if (p1 > p2) {
        parent[p1] = p2;
    }
    else {
        parent[p2] = p1;
    }
}

void findIslands(int x, int y) {
    
    queue<pair<int, int>> q;

    q.push({ x,y });
    islands[islandNum].push_back({ x,y });

    int nx, ny, i;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;

        q.pop();

        for (i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (map[nx][ny] == 1 && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    map[nx][ny] = islandNum;
                    islands[islandNum].push_back({ nx,ny });
                    q.push({ nx,ny });
                }
            }
        }
    }
}


pair<int, int> goRight(int x, int y, int num) {

    for (int i = y + 1; i < M; i++) {

        if (map[x][i] == num) {
            return { -1,-1 };
        }
        else if (map[x][i] > 0) {
            return { i - y - 1,map[x][i] };
        }
    }

    return { -1,-1 };
}

pair<int, int> goLeft(int x, int y, int num) {

    for (int i = y - 1; i >= 0; i--) {

        if (map[x][i] == num) {
            return { -1,-1 };
        }
        else if (map[x][i] > 0) {
            return { y - i - 1,map[x][i] };
        }
    }

    return { -1,-1 };
}

pair<int, int> goUp(int x, int y, int num) {

    for (int i = x - 1; i >= 0; i--) {

        if (map[i][y] == num) {
            return { -1,-1 };
        }
        else if (map[i][y] > 0) {
            return { x - i - 1,map[i][y] };
        }
    }

    return { -1,-1 };
}

pair<int, int> goDown(int x, int y, int num) {

    for (int i = x + 1; i < N; i++) {

        if (map[i][y] == num) {
            return { -1,-1 };
        }
        else if (map[i][y] > 0) {
            return { i - x - 1,map[i][y] };
        }
    }

    return { -1,-1 };
}

void calcBridgeDist(int num) {

    int x, y;
    pair<int, int> right, left, up, down;

    for (auto i : islands[num]) {
        x = i.first;
        y = i.second;

        right = goRight(x, y, num);
        left = goLeft(x, y, num);
        up = goUp(x, y, num);
        down = goDown(x, y, num);

        if (right.first != -1 && right.first > 1) {
            dist.push_back({ right.first,{num,right.second} });
        }

        if (left.first != -1 && left.first > 1) {
            dist.push_back({ left.first,{num,left.second} });
        }

        if (up.first != -1 && up.first > 1) {
            dist.push_back({ up.first,{num,up.second} });
        }

        if (down.first != -1 && down.first > 1) {
            dist.push_back({ down.first,{num,down.second} });
        }
    }
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            cin >> map[i][j];
            visited[i][j] = false;
        }
    }

    islandNum = 1;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {

            if (map[i][j] == 1 && !visited[i][j]) {
                visited[i][j] = true;
                map[i][j] = islandNum;
                parent[islandNum] = islandNum;
                findIslands(i, j);
                islandNum++;
            }
        }
    }

    for (i = 1; i < islandNum; i++) {
        calcBridgeDist(i);
    }

    sort(dist.begin(), dist.end());

    int d, i1, i2;
    int ans = 0;

    for (i = 0; i < dist.size(); i++) {
        d = dist[i].first;
        i1 = dist[i].second.first;
        i2 = dist[i].second.second;

        i1 = findParent(i1);
        i2 = findParent(i2);

        if (i1 != i2) {
            Union(i1, i2);
            ans += d;
        }
    }

    for (i = 1; i < islandNum; i++) {
        if (findParent(i) != 1) {
            ans = -1;
            break;
        }
    }


    cout << ans;

    return 0;
}
