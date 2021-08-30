#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

int N;
int map[25][25];
bool visited[25][25];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans[630];
void dfs(int a, int b, int mark)
{
    for (int i = 0;i < 4;i++)
    {
        int c = a + dx[i];
        int d = b + dy[i];

        if (c >= 0 && c < N && d >= 0 && d < N)
        {
            if (!visited[c][d] && map[c][d] == 1)
            {
                visited[c][d] = true;
                ans[mark]++;
                dfs(c, d, mark);

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
            int a;
            scanf("%1d", &a);
            map[i][j] = a;
        }
    }

    int mark = 0;
    
    memset(ans, 0, sizeof(ans));
    memset(visited, false, sizeof(visited));
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
        {
            if (map[i][j] == 1 &&!visited[i][j])
            {
                visited[i][j] = true;
                ans[mark]++;
                dfs(i, j, mark++);

            }
        }
    }
    
    sort(ans, ans + mark);
    cout << mark << '\n';
    for (int i = 0;i < mark;i++)
    {
        cout << ans[i] << '\n';
    }

    return 0;
}
