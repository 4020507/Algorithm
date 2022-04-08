#pragma warning(disable:4996)
#include <iostream>
#include <string.h>

using namespace std;

#define MAX 500
#define INF 1e9

int degree[MAX + 1];
int students[MAX + 1][MAX + 1];
int main(void)
{
    std::ios::sync_with_stdio(false);

    
    int N, M;
    
    cin >> N >> M;
    int a, b;

    for (int i = 1;i <= N;i++)
        fill(students[i], students[i] + N+1, INF);

    for (int i = 1;i <= N;i++)
        students[i][i] = 0;

    for (int i = 0;i < M;i++)
    {
        cin >> a >> b;
        students[a][b] = 1;
    }

    for (int k = 1;k <= N;k++)
    {
        for (int i = 1;i <= N;i++)
        {
            for (int j = 1;j <= N;j++)
            {
                students[i][j] = min(students[i][j], students[i][k] + students[k][j]);
            }
        }
    }

    bool check;
    int ans = 0;
    for (int i = 1;i <= N;i++)
    {
        check = true;
        for (int j = 1;j <= N;j++)
        {
            if (students[i][j] == INF && students[j][i] == INF)
            {
                check = false;
                break;
            }
        }

        if (check)
            ans++;
    }

    cout << ans;
    return 0;

}
