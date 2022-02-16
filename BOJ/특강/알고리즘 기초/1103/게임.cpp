#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int board[50][50];
int N, M;
bool visited[50][50];
int dp[50][50];
int ans;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int dfs(int x, int y)
{
    if (x < 0 || x >= N || y < 0 || y >= M || board[x][y] == 0)
        return 0;
    if (visited[x][y])
    {
        cout << -1;
        exit(0);
    }
    
    int& val = dp[x][y];

    if (val != -1)
        return val;

    if (board[x][y] == 0)
        return 0;

    visited[x][y] = true;
    val = 0;

    int nx, ny;

    for (int i = 0;i < 4;i++)
    {
        nx = board[x][y] * dx[i] + x;
        ny = board[x][y] * dy[i] + y;

        val = max(val, dfs(nx, ny) + 1);
    }

    visited[x][y] = false;

    return val;
}

int main() {
    
    
    cin >> N >> M;
    string s;
    for (int i = 0;i < N;i++)
    {
        cin >> s;
        for (int j = 0;j < M;j++)
        {
            if (s[j] != 'H')
                board[i][j] = s[j] - '0';
            else
                board[i][j] = 0;
        }
    }

    memset(dp, -1, sizeof(dp));
    memset(visited,false,sizeof(visited));

    cout << dfs(0,0);

    return 0;
}
