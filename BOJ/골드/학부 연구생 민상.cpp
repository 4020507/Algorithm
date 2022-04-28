#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int lab[2000][2000];
int dir; //오 왼 위 아래
vector<pair<int, int>> airConditional;
bool visited[2000][2000][4];
bool cnt[2000][2000];
int sit;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void area(int x, int y) {

    queue<pair<int, pair<int,int>>> q;
    q.push({ 0,{x,y} });

    for (int i = 0;i < 4;i++) 
        visited[x][y][i] = true;
    
    int nx, ny;

    while (!q.empty()) {
        dir = q.front().first;
        x = q.front().second.first;
        y = q.front().second.second;
        
        if (!cnt[x][y]) {
            cnt[x][y] = true;
            sit++;
        }
        q.pop();

        if (lab[x][y] == 9) {
            for (int i = 0;i < 4;i++) {
                nx = x + dx[i];
                ny = y + dy[i];

                if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                    if (!visited[nx][ny][i]) {
                        visited[nx][ny][i] = true;
                        q.push({ i,{nx,ny} });
                    }
                }
            }
        }
        else if (lab[x][y] == 0) {
            if (dir == 0) {
                if (y + 1 < M && !visited[x][y + 1][dir]) {
                    visited[x][y + 1][dir] = true;
                    q.push({ dir,{x,y + 1} });
                }
            }
            else if (dir == 1) {
                if (y - 1 >= 0 && !visited[x][y - 1][dir]) {
                    visited[x][y - 1][dir] = true;
                    q.push({ dir,{x,y - 1} });
                }
            }
            else if (dir == 2) {
                if (x - 1 >= 0 && !visited[x - 1][y][dir]) {
                    visited[x - 1][y][dir] = true;
                    q.push({ dir,{x - 1,y} });
                }
            }
            else if (dir == 3) {
                if (x + 1 < N && !visited[x + 1][y][dir]) {
                    visited[x + 1][y][dir] = true;
                    q.push({ dir,{x + 1,y} });
                }
            }
        }
        else if (lab[x][y] == 1) {
            if (dir == 2) {
                if (x - 1 >= 0 && !visited[x - 1][y][dir]) {
                    visited[x - 1][y][dir] = true;
                    q.push({ dir,{x - 1,y} });
                }
            }
            else if (dir == 3) {
                if (x + 1 < N && !visited[x + 1][y][dir]) {
                    visited[x + 1][y][dir] = true;
                    q.push({ dir,{x + 1,y} });
                }
            }
        }
        else if (lab[x][y] == 2) {
            if (dir == 0) {
                if (y + 1 < M && !visited[x][y + 1][dir]) {
                    visited[x][y + 1][dir] = true;
                    q.push({ dir,{x,y + 1} });
                }
            }
            else if (dir == 1) {
                if (y - 1 >= 0 && !visited[x][y - 1][dir]) {
                    visited[x][y - 1][dir] = true;
                    q.push({ dir,{x,y - 1} });
                }
            }
        }
        else if (lab[x][y] == 3) {
            if (dir == 0) {
                if (x - 1 >= 0 && !visited[x - 1][y][2]) {
                    visited[x - 1][y][2] = true;
                    q.push({ 2,{x - 1,y} });
                }
            }
            else if (dir == 1) {
                if (x + 1 < N && !visited[x + 1][y][3]) {
                    visited[x + 1][y][3] = true;
                    q.push({ 3,{x + 1,y} });
                }
            }
            else if (dir == 2) {
                if (y + 1 < M && !visited[x][y + 1][0]) {
                    visited[x][y + 1][0] = true;
                    q.push({ 0,{x,y + 1} });
                }
            }
            else if (dir == 3) {
                if (y - 1 >= 0 && !visited[x][y - 1][1]) {
                    visited[x][y - 1][1] = true;
                    q.push({ 1,{x,y - 1} });
                }
            }
        }
        else if (lab[x][y] == 4) {
            if (dir == 0) {
                if (x + 1 < N && !visited[x + 1][y][3]) {
                    visited[x + 1][y][3] = true;
                    q.push({ 3,{x + 1,y} });
                }
            }
            else if (dir == 1) {
                if (x - 1 >= 0 && !visited[x - 1][y][2]) {
                    visited[x - 1][y][2] = true;
                    q.push({ 2,{x - 1,y} });
                }
            }
            else if (dir == 2) {
                if (y - 1 >= 0 && !visited[x][y - 1][1]) {
                    visited[x][y - 1][1] = true;
                    q.push({ 1,{x,y - 1} });
                }
            }
            else if (dir == 3) {
                if (y + 1 < M && !visited[x][y + 1][0]) {
                    visited[x][y + 1][0] = true;
                    q.push({ 0,{x,y + 1} });
                }
            }
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N >> M;

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            cin >> lab[i][j];

            if (lab[i][j] == 9)
                airConditional.push_back({ i,j });
        }
    }

    memset(visited, false, sizeof(visited));
    memset(cnt, false, sizeof(cnt));
    sit = 0;

    for (auto ac : airConditional)
        if(!cnt[ac.first][ac.second])
            area(ac.first, ac.second);

    cout << sit;

    return 0;

}
