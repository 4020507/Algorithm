#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

int R, C, K;
int temperature[21][21];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
bool visited[21][21];
vector<pair<int, pair<int,int>>> heater;
vector<pair<int, int>> space;

//1 오른쪽, 2 왼쪽 3 위 4 아래 방향으로 벽이 존재
bool wall[21][21][5];

void spread(int x, int y, int num)
{
    queue<pair<int, pair<int,int>>> q;
    q.push({ 5,{x,y } });
    memset(visited, false, sizeof(visited));
    visited[x][y] = true;
    int wind;
    while (!q.empty())
    {
        x = q.front().second.first;
        y = q.front().second.second;
        wind = q.front().first;
        q.pop();

        temperature[x][y] += wind;
        
        if (wind == 1)
            continue;

        if (num == 1)
        {
            if (y + 1 <= C)
            {
                if (!visited[x][y + 1])
                {
                    if (!wall[x][y][1])
                    {
                        visited[x][y + 1] = true;
                        q.push({ wind - 1,{x,y + 1} });
                    }
                }

                if (x - 1 >= 1)
                {
                    if (!visited[x - 1][y + 1])
                    {
                        if (!wall[x][y][3] && !wall[x - 1][y][1])
                        {
                            visited[x - 1][y + 1] = true;
                            q.push({ wind - 1,{x - 1,y + 1} });
                        }
                    }
                }

                if (x + 1 <= R)
                {
                    if (!visited[x + 1][y + 1])
                    {
                        if (!wall[x][y][4] && !wall[x + 1][y][1])
                        {
                            visited[x + 1][y + 1] = true;
                            q.push({ wind - 1,{x + 1,y + 1} });
                        }
                    }
                }
            }
        }
        else if (num == 2)
        {
            if (y - 1 >= 1)
            {
                if (!visited[x][y - 1] && !wall[x][y][2])
                {
                    visited[x][y - 1] = true;
                    q.push({ wind - 1,{x,y - 1} });
                }

                if (x - 1 >= 1)
                {
                    if (!visited[x - 1][y - 1] && !wall[x][y][3] && !wall[x - 1][y][2])
                    {
                        visited[x - 1][y - 1] = true;
                        q.push({ wind - 1,{x - 1,y - 1} });
                    }
                }

                if (x + 1 <= R)
                {
                    if (!visited[x + 1][y - 1] && !wall[x][y][4] && !wall[x + 1][y][2])
                    {
                        visited[x + 1][y - 1] = true;
                        q.push({ wind - 1,{x + 1,y - 1} });
                    }
                }
            }
        }
        else if (num == 3)
        {
            if (x - 1 >= 1)
            {
                if (!visited[x - 1][y] && !wall[x][y][3])
                {
                    q.push({ wind - 1,{x - 1,y} });
                    visited[x - 1][y] = true;
                }

                if (y - 1 >= 1)
                {
                    if (!visited[x - 1][y - 1] && !wall[x][y][2] && !wall[x][y - 1][3])
                    {
                        q.push({ wind - 1,{x - 1,y - 1} });
                        visited[x - 1][y - 1] = true;
                    }
                }

                if (y + 1 <= C)
                {
                    if (!visited[x - 1][y + 1] && !wall[x][y][1] && !wall[x][y + 1][3])
                    {
                        q.push({ wind - 1,{x - 1,y + 1} });
                        visited[x - 1][y + 1] = true;
                    }
                }
            }
        }
        else if (num == 4)
        {
            if (x + 1 <= R)
            {
                if (!visited[x + 1][y] && !wall[x][y][4])
                {
                    q.push({ wind - 1,{x + 1,y} });
                    visited[x + 1][y] = true;
                }

                if (y - 1 >= 1)
                {
                    if (!visited[x + 1][y - 1] && !wall[x][y][2] && !wall[x][y - 1][4])
                    {
                        q.push({ wind - 1,{x + 1,y - 1} });
                        visited[x + 1][y - 1] = true;
                    }
                }

                if (y + 1 <= C)
                {
                    if (!visited[x + 1][y + 1] && !wall[x][y][1] && !wall[x][y + 1][4])
                    {
                        q.push({ wind - 1,{x + 1,y + 1} });
                        visited[x + 1][y + 1] = true;
                    }
                }
            }
        }
    }
}

void wind()
{
    for (auto h : heater)
    {
        if (h.first == 1)
            spread(h.second.first, h.second.second + 1, h.first);
        else if (h.first == 2)
            spread(h.second.first, h.second.second - 1, h.first);
        else if (h.first == 3)
            spread(h.second.first - 1, h.second.second, h.first);
        else
            spread(h.second.first + 1, h.second.second, h.first);
    }
}

void control()
{
    int x, y;
    int calc;
    int temp[21][21];
    memset(temp, 0, sizeof(temp));
    for (int i = 1;i <= R;i++)
    {
        for (int j = 1;j <= C;j++)
        {
            for (int k = 0;k < 4;k++)
            {
                x = i + dx[k];
                y = j + dy[k];

                if (x >= 1 && x <= R && y >= 1 && y <= C)
                {
                    if (wall[i][j][k+1])
                        continue;

                    if (temperature[i][j] > temperature[x][y])
                    {
                        calc = (temperature[i][j] - temperature[x][y]) / 4;
                        temp[i][j] -= calc;
                    }
                    else if (temperature[i][j] < temperature[x][y])
                    {
                        calc = (temperature[x][y] - temperature[i][j]) / 4;
                        temp[i][j] += calc;
                    }
                }
            }
            temp[i][j] += temperature[i][j];

            if(temp[i][j] < 0)
                temp[i][j] = 0;
        }
    }

    for (int i = 1;i <= R;i++)
        for (int j = 1;j <= C;j++)
            temperature[i][j] = temp[i][j];
}

void outside()
{
    for (int i = 1;i <= R;i++)
    {
        if (temperature[i][1] > 0)
            temperature[i][1]--;
        if (temperature[i][C] > 0)
            temperature[i][C]--;
    }

    for (int j = 2;j <= C - 1;j++)
    {
        if (temperature[1][j] > 0)
            temperature[1][j]--;
        if (temperature[R][j] > 0)
            temperature[R][j]--;
    }
}

bool isExceed()
{
    for (auto s : space)
    {
        if (temperature[s.first][s.second] < K)
            return false;
    }

    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> R >> C >> K;

    int num;

    for (int i = 1;i <= R;i++)
    {
        for (int j = 1;j <= C;j++)
        {
            cin >> num;

            if (num > 0 && num < 5)
                heater.push_back({ num,{i,j} });
            else if (num == 5)
                space.push_back({ i,j });
        }
    }

    int W;
    int x, y;
    memset(wall, false, sizeof(wall));
    cin >> W;
    for (int i = 0;i < W;i++)
    {
        cin >> x >> y >> num;

        if (num == 0)
        {
            wall[x][y][3] = true;
            wall[x - 1][y][4] = true;
        }
        else
        {
            wall[x][y][1] = true;
            wall[x][y + 1][2] = true;
        }
    }

    int chocolate = 0;

    for (chocolate = 0;chocolate <= 100;)
    {
        wind();
        control();
        outside();
        chocolate++;
        if (isExceed())
            break;
    }

    cout << chocolate;
    return 0;
}
