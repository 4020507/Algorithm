#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
using namespace std;

int n;
int forest[500][500];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int dp[500][500];
int ans;

int makeDP(int x, int y) {

    if (dp[x][y] != -1)
        return dp[x][y];

    dp[x][y] = 1;
    int nx, ny;

    for (int i = 0; i < 4; i++) {

        nx = x + dx[i];
        ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;

        if (forest[x][y] < forest[nx][ny])
            dp[x][y] = max(makeDP(nx, ny) + 1, dp[x][y]);
    }

    return dp[x][y];
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> forest[i][j];
    
    memset(dp, -1, sizeof(dp));
    ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans = max(ans, makeDP(i, j));

    cout << ans;

    return 0;

}
