#include <iostream>
#include <vector>

using namespace std;

int room[51][51];
vector<pair<int, pair<int,int>>> dust;
int R, C, T;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> machine;

void sparse()
{
    int nx, ny;
    dust.clear();
    for (int i = 0;i < R;i++)
    {
        for (int j = 0;j < C;j++)
        {
            if (room[i][j] > 0)
            {
                int cnt = 0;

                for (int k = 0;k < 4;k++)
                {
                    nx = i + dx[k];
                    ny = j + dy[k];

                    if (nx >= 0 && nx < R && ny >= 0 && ny < C && room[nx][ny] != -1)
                    {
                        dust.push_back({ room[i][j] / 5,{nx,ny} });
                        cnt++;
                    }
                }
                room[i][j] = room[i][j] - room[i][j] / 5 * cnt;
            }
        }
    }

    for (auto d : dust)
    {
        if (room[d.second.first][d.second.second] != -1)
        {
            room[d.second.first][d.second.second] += d.first;
        }
    }
}

void move()
{
    //반시계 방향
    int x = machine[0].first;
    int y = machine[0].second + 1;
    int temp = -1;
    int temp2 = -1;
    //오른쪽
    if (y < C)
    {
        temp = room[x][y];
        room[x][y] = 0;
        while (y + 1< C)
        {
            temp2 = room[x][y + 1];
            room[x][y + 1] = temp;
            temp = temp2;
            y++;
        }
    }

    if (temp != -1)
    {
        temp2 = room[x - 1][y];
        room[x - 1][y] = temp;
        temp = temp2;
    }
    x--;

    //위
    while (x - 1 >= 0)
    {
        temp2 = room[x - 1][y];
        room[x - 1][y] = temp;
        temp = temp2;
        x--;
    }

    //왼
    y--;
    while (y >= machine[0].second)
    {
        temp2 = room[x][y];
        room[x][y] = temp;
        temp = temp2;
        y--;
    }
    y++;
    x++;
    //아래
    while (x + 1 <= machine[0].first)
    {
        temp2 = room[x][y];
        room[x][y] = temp;
        temp = temp2;
        x++;
    }


    //시계 방향
    x = machine[1].first;
    y = machine[1].second + 1;
    temp = -1;

    //오른
    if (y < C)
    {
        temp = room[x][y];
        room[x][y] = 0;
        while (y + 1 < C)
        {
            temp2 = room[x][y + 1];
            room[x][y + 1] = temp;
            temp = temp2;
            y++;
        }
    }

    if (temp != -1)
    {
        temp2 = room[x + 1][y];
        room[x+1][y] = temp;
        temp = temp2;
    }

    x++;

    //아래
    while (x + 1 < R)
    {
        temp2 = room[x + 1][y];
        room[x + 1][y] = temp;
        temp = temp2;
        x++;
    }
    y--;
    //왼
    while (y >= machine[1].second)
    {
        temp2 = room[x][y];
        room[x][y] = temp;
        temp = temp2;
        y--;
    }
    y++;

    //위
    x--;
    while (x - 1 > machine[1].first)
    {
        temp2 = room[x][y];
        room[x][y] = temp;
        temp = temp2;
        x--;
    }

    room[x][y] = temp;

}
int main(int argc, const char* argv[]) {

    cin >> R >> C >> T;

    for (int i = 0;i < R;i++)
    {
        for (int j = 0;j < C;j++)
        {
            cin >> room[i][j];

            if (room[i][j] == -1)
                machine.push_back({ i,j });
        }
    }
    
    for (int i = 0;i < T;i++)
    {
        sparse();
        move();
    }
    int ans = 0;

    for (int i = 0;i < R;i++) {
        for (int j = 0;j < C;j++)
            ans += room[i][j];

    }

    cout << ans + 2;
    return 0;
}
