#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int map[100][100];
int islands[100][100];
bool visited[100][100];
int N;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int bridge;

void calcDist(int x, int y) {
    queue<pair<int, pair<int,int>>> q;
    q.push({ 0,{x,y} });
    visited[x][y] = true;
    int num = islands[x][y];

    int nx, ny, i, steps;
    
    while (!q.empty()) {
        steps = q.front().first;
        x = q.front().second.first;
        y = q.front().second.second;

        q.pop();

        if (steps > bridge)
            continue;

        for (i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if (!visited[nx][ny]) {
                    if (islands[nx][ny] == num) {
                        q.push({ 0,{nx,ny} });
                        visited[nx][ny] = true;
                    }
                    else if (islands[nx][ny] == 0) {
                        q.push({ (steps + 1),{nx,ny} });
                        visited[nx][ny] = true;
                    }
                    else {
                        bridge = steps;
                    }
                }
            }
        }
    }
}
void setIslands(int x, int y, int num) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = true;
    islands[x][y] = num;

    int nx, ny, i;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if (map[nx][ny] == 1 && !visited[nx][ny]) {
                    q.push({ nx,ny });
                    islands[nx][ny] = num;
                    visited[nx][ny] = true;
                }
            }
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];
    
    memset(visited, false, sizeof(visited));

    int islandNum = 1;
    bridge = 1e9;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && map[i][j] == 1)
                setIslands(i, j, islandNum++);
        }
    }

    int start = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (islands[i][j] == start) {
                memset(visited, false, sizeof(visited));
                calcDist(i, j);
                start++;
            }
        }

        if (start == islandNum)
            break;
    }
    

    

    cout << bridge;

    return 0;

}
