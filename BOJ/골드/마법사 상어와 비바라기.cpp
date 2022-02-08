#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
int N, M;
int matrix[51][51];
bool visited[51][51];
int dx[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int dy[9] = { 0,-1,-1,0,1,1,1,0,-1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> N >> M;

    for (int i = 1;i <= N;i++)
        for (int j = 1;j <= N;j++)
            cin >> matrix[i][j];

    int d, s;

    queue<pair<int, int>> q;

    q.push({ N - 1,1 }); q.push({ N - 1,2 }); q.push({ N,1 }); q.push({ N,2 });
    vector<pair<int, int>> clouds;
    int x, y;
    int nx, ny;

    for (int i = 0;i < M;i++)
    {
        cin >> d >> s;

        clouds.clear();
        memset(visited, false, sizeof(visited));
        while (!q.empty())
        {
            x = q.front().first;
            y = q.front().second;
            q.pop();

            for (int i = 0;i < s;i++)
            {
                x += dx[d]; if (x <= 0) x = N; if (x > N) x = 1;
                y += dy[d]; if (y <= 0) y = N; if (y > N) y = 1;
            }

            matrix[x][y]++;
            clouds.push_back({ x,y });
            visited[x][y] = true;
        }

        for (auto c : clouds)
        {
            for (int i = 2;i <= 8;i += 2)
            {
                nx = c.first + dx[i];
                ny = c.second + dy[i];

                if (nx >= 1 && nx <= N && ny >= 1 && ny <= N)
                {
                    if (matrix[nx][ny] >= 1)
                        matrix [c.first][c.second]++;
                }
            }
        }

        for (int i = 1;i <= N;i++)
        {
            for (int j = 1;j <= N;j++)
            {
                if (matrix[i][j] >= 2 && !visited[i][j])
                {
                    q.push({ i,j });
                    matrix[i][j] -= 2;
                }
            }
        }
    }

    int ans = 0;

    for (int i = 1;i <= N;i++)
        for (int j = 1;j <= N;j++)
            ans += matrix[i][j];

    cout << ans;

    return 0;
}
