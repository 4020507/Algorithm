#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int lab[50][50];

int N, M, space;
vector<pair<int,int>> virus;
int time[50][50];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans;
queue<pair<int, int>> q;
bool visited[10];
void spread()
{
    int max_time = 0;
    int x, y,nx,ny;
    int infected = 0;
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;

        for (int i = 0;i < 4;i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N)
            {
                if (lab[nx][ny] != 1 && time[nx][ny] == -1)
                {
                    time[nx][ny] = time[x][y] + 1;

                    if (lab[nx][ny] == 0)
                    {
                        infected++;
                        max_time = time[nx][ny];
                        
                    }

                    q.push({ nx,ny });
                }
            }
        }

        q.pop();
    }

     if (space == infected)
        ans = min(ans, max_time);
}
void active_virus(int idx, int cnt)
{
    if (cnt == M)
    {
        memset(time, -1, sizeof(time));

        for (int i = 0;i<10;i++)
        {
            if (visited[i]) {
                q.push({ virus[i].first,virus[i].second });
                time[virus[i].first][virus[i].second] = 0;
            }
        }
        spread();
        return;
    }

    for (int i = idx;i < virus.size();i++)
    {
       visited[i] = true;
       active_virus(i + 1, cnt+1);
       visited[i] = false;
    }
}
int main() {
    
    cin >> N >> M;
    space = 0;
    ans = 1e9;

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++) {
            cin >> lab[i][j];

            if (lab[i][j] == 2)
                virus.push_back({ i,j });
            else if (lab[i][j] == 0)
                space++;
        }
    }

    active_virus(0, 0);

    if (ans != 1e9)
        cout << ans;
    else
        cout << -1;
    return 0;
}
