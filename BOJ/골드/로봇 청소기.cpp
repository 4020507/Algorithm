#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

int N, M;
int r, c;
int dir;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int ans;
int room[50][50];

void clean()
{
    while (true)
    {
        if (room[r][c] == 0)
        {
            room[r][c] = -1;
            ans++;
        }
        int origin = dir;
        dir = (++dir) % 4;

        int nr = r + dx[dir];
        int nc = c + dy[dir];

        if (nr >= 0 && nr < N && nc >= 0 && nc < M && room[nr][nc] == 0)
        {
            r = nr;
            c = nc;
            continue;
        }
        else
        {
            int cnt = 0;
            int none = 0;
            while (cnt < 4)
            {
                if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                    none++;
                else if (room[nr][nc] == 1 || room[nr][nc] == -1)
                    none++;
                else
                    break;
                cnt++;
                dir = (++dir) % 4;
                nr = r + dx[dir];
                nc = c + dy[dir];

            }

            if (none == 4)
            {
                dir = origin;
                r -= dx[dir];
                c -= dy[dir];

                if (r < 0 || r >= N || c < 0 || c >= M || room[r][c] == 1)
                    break;
                continue;
            }
            else
            {
                r = nr;
                c = nc;
                continue;
            }
        }
    }
}
int main(void)
{
    cin >> N >> M;
    cin >> r >> c >> dir;

    if (dir == 1)
        dir = 3;
    else if (dir == 3)
        dir = 1;

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < M;j++)
            cin >> room[i][j];
    }

    clean();

    cout << ans;

    return 0;
    
}
