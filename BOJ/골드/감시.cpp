#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M;
int map[8][8];
vector<pair<int,int>> CCTV;
int cnt;
int mark[8][8];
int visited[4][4][4][4][4][4][4][4];
int six;
int ans;
int one(int dir, int num)
{
    if (num >= cnt)
        return 0;
    int temp = 0;
    int x = CCTV[num].first;
    int y = CCTV[num].second;

    if (mark[x][y] == 0)
    {
        mark[x][y] = 1;
        temp++;
    }
    if (dir == 0)
    {
        x--;
        while (x >= 0)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                temp++;
                mark[x][y]++;
            }
            else if (map[x][y] == 6)
                break;
            x--;
        }
    }
    else if (dir == 1)
    {
        y++;
        while (y < M)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                temp++;
                mark[x][y] = 1;
            }
            else if (map[x][y] == 6)
                break;
            y++;
        }
    }
    else if (dir == 2)
    {
        x++;
        while (x < N)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                temp++;
                mark[x][y] = 1;
            }
            else if (map[x][y] == 6)
                break;
            x++;
        }
    }
    else if (dir == 3)
    {
        y--;
        while (y >= 0)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                temp++;
                mark[x][y] = 1;
            }
            else if (map[x][y] == 6)
            {
                break;
            }
            y--;
        }
    }

    return temp;
}

int two(int dir, int num)
{
    if (num >= cnt)
        return 0;
    if (dir >= 2)
        return 0;

    int temp = 0;
    int x = CCTV[num].first;
    int y = CCTV[num].second;

    
    if (mark[x][y] == 0)
    {
        temp++;
        mark[x][y] = 1;
    }

    if (dir == 0)
    {
        int nx = x;
        x--;
        while (x >= 0)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
                break;
            x--;
        }
        x = nx + 1;

        while (x < N)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
                break;
            x++;
        }
    }
    else if (dir == 1)
    {
        int ny = y;
        y++;

        while (y < M)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
                break;
            y++;
        }
        y = ny - 1;

        while (y >= 0)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
            {
                break;
            }
            y--;
        }
    }


    return temp;
}

int three(int dir, int num)
{
    if (num >= cnt)
        return 0;
    int temp = 0;
    int x = CCTV[num].first;
    int y = CCTV[num].second;

    if (mark[x][y] == 0)
    {
        temp++;
        mark[x][y] = 1;
    }

    if (dir == 0)
    {
        int nx = x;
        x--;

        while (x >= 0)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
                break;
            x--;
        }

        x = nx;
        y++;

        while (y < M)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
                break;
            y++;
        }
    }
    else if (dir == 1)
    {
        int ny = y;
        y++;

        while (y < M)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
                break;
            y++;
        }

        y = ny;
        x++;

        while (x < N)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
                break;
            x++;
        }
    }
    else if (dir == 2)
    {
        int nx = x;
        x++;

        while (x < N)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
                break;
            x++;
        }

        x = nx;
        y--;
        while (y >= 0)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
            {
                break;
            }
            y--;
        }
    }
    else if (dir == 3)
    {
        int ny = y;
        y--;
        while (y >= 0)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
            {
                break;
            }
            y--;
        }

        y = ny;
        x--;

        while (x >= 0)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
                break;
            x--;
        }
    }

    return temp;
}

int four(int dir, int num)
{
    if (num >= cnt)
        return 0;
    int x = CCTV[num].first;
    int y = CCTV[num].second;
    int temp = 0;
    if (mark[x][y] == 0)
    {
        temp++;
        mark[x][y] = 1;
    }

    if (dir == 0)
    {
        int nx = x;

        x--;

        while (x >= 0)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
                break;
            x--;
        }

        x = nx;
        int ny = y;

        y--;
        while (y >= 0)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
            {
                break;
            }
            y--;
        }

        y = ny;
        y++;

        while (y < M)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
                break;
            y++;
        }
    }
    else if (dir == 1)
    {
        int nx = x;

        x--;

        while (x >= 0)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
                break;
            x--;
        }

        x = nx;

        int ny = y;
        y++;

        while (y < M)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
                break;
            y++;
        }

        y = ny;

        x++;

        while (x < N)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
                break;
            x++;
        }

    }
    else if (dir == 2)
    {
        int nx = x;
        x++;
        while (x < N)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
                break;
            x++;
        }
        x = nx;
        int ny = y;

        y++;

        while (y < M)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
                break;
            y++;
        }

        y = ny;
        y--;

        while (y >= 0)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
            {
                break;
            }
            y--;
        }
    }
    else if (dir == 3)
    {
        int ny = y;
        y--;

        while (y >= 0)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
            {
                break;
            }
            y--;
        }
        y = ny;

        int nx = x;
        x++;
        while (x < N)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
                break;
            x++;
        }
        x = nx;

        x--;

        while (x >= 0)
        {
            if (map[x][y] < 6 && mark[x][y] == 0)
            {
                mark[x][y] = 1;
                temp++;
            }
            else if (map[x][y] == 6)
                break;
            x--;
        }
    }

    return temp;
}

int five(int num)
{
    if (num >= cnt)
        return 0;
    int x = CCTV[num].first;
    int y = CCTV[num].second;
    int temp = 0;

    if (mark[x][y] == 0)
    {
        mark[x][y] = 1;
        temp++;
    }

    int nx = x;
    int ny = y;

    x++;
    while (x < N)
    {
        if (map[x][y] < 6 && mark[x][y] == 0)
        {
            mark[x][y] = 1;
            temp++;
        }
        else if (map[x][y] == 6)
            break;
        x++;
    }
    x = nx;

    x--;
    while (x >= 0)
    {
        if (map[x][y] < 6 && mark[x][y] == 0)
        {
            mark[x][y] = 1;
            temp++;
        }
        else if (map[x][y] == 6)
            break;
        x--;
    }

    x = nx;

    while (y < M)
    {
        if (map[x][y] < 6 && mark[x][y] == 0)
        {
            mark[x][y] = 1;
            temp++;
        }
        else if (map[x][y] == 6)
            break;
        y++;
    }
    y = ny - 1;

    while (y >= 0)
    {
        if (map[x][y] < 6 && mark[x][y] == 0)
        {
            mark[x][y] = 1;
            temp++;
        }
        else if (map[x][y] == 6)
            break;
        y--;
    }

    return temp;
}

int range(int a, int b, int c, int d, int e, int f, int g, int h)
{
    if (visited[a][b][c][d][e][f][g][h] != -1)
        return visited[a][b][c][d][e][f][g][h];
    visited[a][b][c][d][e][f][g][h] = 0;
    
    if (a > 0)
        range(a - 1, b, c, d, e, f, g, h);
    if(b > 0)
        range(a, b-1, c, d, e, f, g, h);
    if (c > 0)
        range(a, b, c - 1, d, e, f, g, h);
    if(d > 0)
        range(a, b, c, d - 1, e, f, g, h);
    if(e > 0)
        range(a, b, c, d, e - 1, f, g, h);
    if (f > 0)
        range(a, b, c, d, e, f - 1, g, h);
    if(g > 0)
        range(a, b, c, d, e, f, g - 1, h);
    if(h>0)
        range(a, b, c, d, e, f, g, h - 1);
    
    memset(mark, 0, sizeof(mark));
    int monitor = 0;

    for (int i = 0;i < cnt;i++)
    {
        if (map[CCTV[i].first][CCTV[i].second] == 1)
        {
            if (i == 0)
                monitor += one(a, i);
            else if (i == 1)
                monitor += one(b, i);
            else if (i == 2)
                monitor += one(c, i);
            else if (i == 3)
                monitor += one(d, i);
            else if (i == 4)
                monitor += one(e, i);
            else if (i == 5)
                monitor += one(f, i);
            else if (i == 6)
                monitor += one(g, i);
            else if (i == 7)
                monitor += one(h, i);
        }
        else if (map[CCTV[i].first][CCTV[i].second] == 2)
        {
            if (i == 0)
                monitor += two(a, i);
            else if (i == 1)
                monitor += two(b, i);
            else if (i == 2)
                monitor += two(c, i);
            else if (i == 3)
                monitor += two(d, i);
            else if (i == 4)
                monitor += two(e, i);
            else if (i == 5)
                monitor += two(f, i);
            else if (i == 6)
                monitor += two(g, i);
            else if (i == 7)
                monitor += two(h, i);
        }
        else if (map[CCTV[i].first][CCTV[i].second] == 3)
        {
            if (i == 0)
                monitor += three(a, i);
            else if (i == 1)
                monitor += three(b, i);
            else if (i == 2)
                monitor += three(c, i);
            else if (i == 3)
                monitor += three(d, i);
            else if (i == 4)
                monitor += three(e, i);
            else if (i == 5)
                monitor += three(f, i);
            else if (i == 6)
                monitor += three(g, i);
            else if (i == 7)
                monitor += three(h, i);
        }
        else if (map[CCTV[i].first][CCTV[i].second] == 4)
        {
            if (i == 0)
                monitor += four(a, i);
            else if (i == 1)
                monitor += four(b, i);
            else if (i == 2)
                monitor += four(c, i);
            else if (i == 3)
                monitor += four(d, i);
            else if (i == 4)
                monitor += four(e, i);
            else if (i == 5)
                monitor += four(f, i);
            else if (i == 6)
                monitor += four(g, i);
            else if (i == 7)
                monitor += four(h, i);
        }
        else if (map[CCTV[i].first][CCTV[i].second] == 5)
        {
            monitor += five(i);
        }
    }
    ans = min(ans, N * M - monitor - six);
    return visited[a][b][c][d][e][f][g][h] = monitor;
}


int main(int argc, const char* argv[]) {

    cin >> N >> M;

    six = 0;
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < M;j++)
        {
            cin >> map[i][j];

            if (map[i][j] > 0 && map[i][j] < 6)
            {
                CCTV.push_back({ i,j });
            }
            else if (map[i][j] == 6)
                six++;
        }
    }
    cnt = CCTV.size();

    ans = 1e9;
    memset(visited, -1, sizeof(visited));
    range(3, 3, 3, 3, 3, 3, 3, 3);

    cout << ans;

    return 0;
}
