#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int club[20][20];
int temp[20][20];
int visited[20][20];
int N, M;
int group_num;
int score;

vector<pair<int, int>> biggest;
int rainbows;
int r, c;

void turn()
{
    for (int i = 0;i < N;i++)
    {
        int idx = 0;
        for (int j = 0;j < N;j++)
        {
            temp[i][j] = club[idx][N - 1 - i];
            idx++;
        }
    }

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
            club[i][j] = temp[i][j];
    }
}
void gravity()
{
    for (int i = 1;i < N;i++)
    {
        for (int j = 0;j < N;j++)
        {
            if (club[i][j] == -2)
            {
                for (int k = i;k >= 1;k--)
                {
                    if (club[k][j] == -1)
                    {
                        club[k + 1][j] = -2;
                        break;
                    }
                    
                    if(club[k-1][j] != -1)
                        club[k][j] = club[k - 1][j];
                    else
                    {
                        club[k][j] = -2;
                        break;
                    }

                    if (k == 1 && club[k-1][j] != -1)
                    {
                        club[k - 1][j] = -2;
                    }
                }
            }
        }
    }
}
void remove_group()
{
    score += biggest.size() * biggest.size();

    for (auto b : biggest)
    {
        club[b.first][b.second] = -2;
    }

    biggest.clear();
}
int make_group(int x, int y, int num)
{
    visited[x][y] = num;
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;

    v.push_back({ x,y });
    q.push({ x,y });
    visited[x][y] = num;

    int a, b, na, nb;
    int cnt = 1;
    int colors = 0;
    int tr = x, tc = y;
    
    while (!q.empty())
    {
        a = q.front().first;
        b = q.front().second;

        if (club[a][b] == club[x][y])
        {
            if (tr > a)
            {
                tr = a;
                tc = b;
            }
            else if (tr == a)
            {
                if (tc > b)
                {
                    tc = b;
                }
            }
        }
        
        q.pop();

        for (int i = 0;i < 4;i++)
        {
            na = a + dx[i];
            nb = b + dy[i];

            if (na >= 0 && na < N && nb >= 0 && nb < N)
            {
                if ((club[na][nb] == 0 && visited[na][nb] != num) || (club[na][nb] == club[x][y] && visited[na][nb] == -1))
                {
                    q.push({ na,nb });
                    v.push_back({ na,nb });
                    visited[na][nb] = num;
                    if (club[na][nb] == club[x][y])
                        cnt++;
                    else if (club[na][nb] == 0)
                    {
                        colors++;
                    }
                }
            }
        }
    }

    if (cnt + colors < 2)
        return num;

    if (cnt + colors > biggest.size())
    {
        biggest = v;
        r = tr;
        c = tc;
        rainbows = colors;
    }
    else if (cnt + colors == biggest.size())
    {
        if (colors > rainbows)
        {
            biggest = v;
            rainbows = colors;
            r = tr;
            c = tc;
        }
        else if (colors == rainbows)
        {
            if (tr > r)
            {
                r = tr;
                c = tc;
                biggest = v;
            }
            else if (tr == r)
            {
                if (tc > c)
                {
                    c = tc;
                    biggest = v;
                }
            }
        }
    }
    return (num + 1);
}

//block이 존재하는지?
bool check()
{
    memset(visited, -1, sizeof(visited));
    group_num = 1;
    rainbows = -1;
    r = -1;
    c = -1;

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
        {
            if (visited[i][j] == -1 && club[i][j] > 0) {
                group_num = make_group(i, j, group_num);
            }
        }
    }

    if (group_num == 1)
        return false;

    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> N >> M;

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
            cin >> club[i][j];
    }

    score = 0;
    while (check())
    {
        remove_group();
        gravity();
        turn();
        gravity();
    }

    cout << score;

    return 0;
}
