#include<iostream>
#include<string.h>
using namespace std;

int N, M;
char graph[101][101];
bool visited[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int W;
int B;
int temp;
void dfs(int x,int y,char c)
{
    for (int i = 0;i < 4;i++)
    {
        int a = dx[i] + x;
        int b = dy[i] + y;

        if (a >= 0 && a < N && b >= 0 && b < M)
        {
            if (!visited[a][b] && graph[a][b] == c)
            {
                visited[a][b] = true;
                temp++;
                dfs(a, b, c);
            }
        }
    }
}

int main(int argc, char** argv)
{
    cin >> M >> N;
    memset(visited, false, sizeof(visited));

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < M;j++)
        {
            cin >> graph[i][j];
        }
    }
    
    W = 0;
    B = 0;
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < M;j++)
        {
            if (!visited[i][j])
            {
                temp = 1;
                visited[i][j] = true;
                dfs(i, j, graph[i][j]);
                if (graph[i][j] == 'W')
                {
                    W += temp * temp;
                }
                else
                    B += temp * temp;
            }
        }
    }

    cout << W << ' ' << B;

    return 0;
}
