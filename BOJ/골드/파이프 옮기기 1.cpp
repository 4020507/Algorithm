#include<iostream>
#include<string.h>
using namespace std;

int N;
int board[16][16];

int ans;

void dfs(int x,int y, int dir)
{
    
    if (x == N - 1 && y == N - 1)
    {
        ans++;
        return;
    }
    if (dir == 0)//가로
    {
        if (x + 1 <= N - 1)
        {
            if (board[y][x + 1] == 0)
            {
                dfs(x + 1, y, 0);
            }
        }
        
        if (x + 1 <= N - 1 && y + 1 <= N - 1)
        {
            if (board[y][x + 1] == 0 && board[y + 1][x] == 0 && board[y + 1][x + 1] == 0)
            {
                dfs(x + 1, y + 1, 2);
            }
        }
        
    }
    else if (dir == 1)//세로
    {
        if (y + 1 <= N - 1)
        {
            if (board[y + 1][x] == 0)
            {
                dfs(x, y + 1, 1);
            }
        }
        
        if (y + 1 <= N - 1 && x + 1 <= N - 1)
        {
            if (board[y][x + 1] == 0 && board[y + 1][x] == 0 && board[y + 1][x + 1] == 0)
            {
                dfs(x + 1, y + 1, 2);
            }
        }
        
    }
    else if (dir == 2)
    {
        if (x + 1 <= N - 1)
        {
            if (board[y][x + 1] == 0)
            {
                dfs(x + 1, y, 0);
            }
        }
        if (y + 1 <= N - 1)
        {
            if (board[y + 1][x] == 0)
            {
                dfs(x, y + 1, 1);
            }
        }
        if (y + 1 <= N - 1 && x + 1 <= N - 1)
        {
            if (board[y][x + 1] == 0 && board[y + 1][x] == 0 && board[y + 1][x + 1] == 0)
            {
                dfs(x + 1, y + 1, 2);
            }
        }
    }
    
    
}
int main(int argc, char** argv)
{
    cin >> N;

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
        {
            cin >> board[i][j];
        }
    }

    ans = 0;
    dfs(1,0,0);

    cout << ans << endl;
    return 0;
}
