#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

char lake[50][50];
int flood[50][50];
int R, C;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visited[50][50];

int main() {

    cin >> R >> C;
    pair<int, int> start;
    pair<int, int> arrive;
    queue<pair<int, pair<int,int>>> q;
    memset(flood, 0, sizeof(flood));

    for (int i = 0;i < R;i++)
    {
        for (int j = 0;j < C;j++)
        {
            cin >> lake[i][j];

            if (lake[i][j] == 'S')
            {
                start.first = i;
                start.second = j;
                lake[i][j] = '.';
            }
            else if (lake[i][j] == 'D')
            {
                arrive.first = i;
                arrive.second = j;
            }
            else if (lake[i][j] == '*')
            {
                q.push({ 0,{i,j} });
            }
        }
    }

    int time, x, y, nx, ny;
    while (!q.empty())
    {
        time = q.front().first;
        x = q.front().second.first;
        y = q.front().second.second;
        q.pop();

        for (int i = 0;i < 4;i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < R && ny >= 0 && ny < C)
            {
                if (flood[nx][ny] == 0 && lake[nx][ny] == '.')
                {
                    q.push({ time + 1,{nx,ny} });
                    flood[nx][ny] = time + 1;
                }
            }
        }
    }

    q.push({ 0,{start.first,start.second} });
    memset(visited, false, sizeof(visited));
    visited[start.first][start.second] = true;
    while (!q.empty())
    {
        time = q.front().first;
        x = q.front().second.first;
        y = q.front().second.second;

        if (x == arrive.first && y == arrive.second)
        {
            cout << time;
            return 0;
        }

        q.pop();
        
        for (int i = 0;i < 4;i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < R && ny >= 0 && ny < C)
            {
                if (lake[nx][ny] != 'X' && lake[nx][ny] != '*' && !visited[nx][ny])
                {
                    if (time + 1 < flood[nx][ny] || lake[nx][ny] == 'D')
                    {
                        q.push({ time + 1,{nx,ny} });
                        visited[nx][ny] = true;
                    }
                    else if (flood[nx][ny] == 0 && lake[nx][ny] == '.')
                    {
                        q.push({ time + 1,{nx,ny} });
                        visited[nx][ny] = true;
                    }
                }
            }
        }
    }

    cout << "KAKTUS";

    return 0;
}
