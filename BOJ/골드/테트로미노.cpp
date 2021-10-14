#include <iostream>
#include <string.h>

using namespace std;

int N, M;
int map[500][500];
bool visited[500][500];
int ans;

void find_ans(int x, int y)
{
    if (x < 0 || y < 0)
        return;
    if (x >= N || y >= M)
        return;

    if (visited[x][y])
        return;

    visited[x][y] = true;
    //가로
    if (y + 3 < M)
    {
        ans = max(ans, map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x][y + 3]);
    }

    //세로
    if (x + 3 < N)
    {
        ans = max(ans, map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 3][y]);
    }

    //정사각형
    if (x + 1 < N && y + 1 < M)
    {
        ans = max(ans, map[x][y] + map[x + 1][y] + map[x][y + 1] + map[x + 1][y + 1]);
    }

    //1
    if (x - 2 >= 0 && y + 1 < M)
    {
        ans = max(ans, map[x][y] + map[x - 1][y] + map[x - 2][y] + map[x][y + 1]);
    }

    //2
    if (y + 2 < M && x + 1 < N)
    {
        ans = max(ans, map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y]);
    }

    //3
    if (x + 2 < N && y - 1 >= 0)
    {
        ans = max(ans, map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x][y - 1]);
    }

    //4
    if (x - 1 >= 0 && y - 2 >= 0)
    {
        ans = max(ans, map[x][y] + map[x][y-1] + map[x][y-2] + map[x - 1][y]);
    }

    //mirror1
    if (x - 2 >= 0 && y - 1 >= 0)
    {
        ans = max(ans, map[x][y] + map[x - 1][y] + map[x - 2][y] + map[x][y - 1]);
    }

    //2
    if (x - 1 >= 0 && y + 2 < M)
    {
        ans = max(ans, map[x][y] + map[x-1][y] + map[x][y + 1] + map[x][y + 2]);
    }

    //3
    if (x + 2 < N && y + 1 < M)
    {
        ans = max(ans, map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x][y + 1]);
    }
    //4
    if (x + 1 < N && y - 2 >= 0)
    {
        ans = max(ans, map[x][y] + map[x + 1][y] + map[x][y - 1] + map[x][y - 2]);
    }

    //1
    if (x + 2 < N && y + 1 < M)
    {
        ans = max(ans, map[x][y] + map[x + 1][y] + map[x + 1][y + 1] + map[x + 2][y + 1]);
    }

    //2
    if (x + 1 < N && y - 2 >= 0)
    {
        ans = max(ans, map[x][y] + map[x][y - 1] + map[x + 1][y - 1] + map[x + 1][y - 2]);
    }

    //3
    if (x - 2 >= 0 && y - 1 >= 0)
    {
        ans = max(ans, map[x][y] + map[x - 1][y] + map[x - 1][y - 1] + map[x - 2][y - 1]);
    }

    //4
    if (x - 1 >= 0 && y + 2 < M)
    {
        ans = max(ans, map[x][y] + map[x][y + 1] + map[x - 1][y + 1] + map[x - 1][y + 2]);
    }

    //1
    if (x + 2 < N && y + 1 < M)
    {
        ans = max(ans, map[x][y+1] + map[x + 1][y] + map[x + 1][y + 1] + map[x + 2][y]);
    }

    //2
    if (x + 1 < N && y - 2 >= 0)
    {
        ans = max(ans, map[x + 1][y] + map[x + 1][y - 1] + map[x][y - 1] + map[x][y - 2]);
    }

    //3
    if (x - 2 >= 0 && y - 1 >= 0)
    {
        ans = max(ans, map[x][y - 1] + map[x - 1][y - 1] + map[x - 1][y] + map[x - 2][y]);
    }

    //4
    if (x - 1 >= 0 && y + 2 < M)
    {
        ans = max(ans, map[x][y + 1] + map[x][y + 2] + map[x - 1][y] + map[x - 1][y + 1]);
    }

    //1
    if (x + 1 < N && y + 2 < M)
    {
        ans = max(ans, map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y + 1]);
    }

    //2
    if (x + 2 < N && y - 1 >= 0)
    {
        ans = max(ans, map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y - 1]);
    }

    //3
    if (x - 1 >= 0 && y - 2 >= 0)
    {
        ans = max(ans, map[x][y] + map[x][y - 1] + map[x][y - 2] + map[x - 1][y - 1]);
    }

    //4
    if (x - 2 >= 0 && y + 1 < M)
    {
        ans = max(ans, map[x][y] + map[x - 1][y] + map[x - 2][y] + map[x - 1][y + 1]);
    }

    find_ans(x + 1, y);
    find_ans(x, y + 1);
    
}
int main(int argc, const char* argv[]) {
    cin >> N >> M;

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < M;j++)
            cin >> map[i][j];
    }
    ans = 0;
    memset(visited, false, sizeof(visited));

    find_ans(0, 0);

    cout << ans;
    return 0;
}
