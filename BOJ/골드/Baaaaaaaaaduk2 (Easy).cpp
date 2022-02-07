#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int visited[20][20];
int map[20][20];
int ans;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void kill ()
{
    memset(visited, 0, sizeof(visited));
    int res = 0;
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < M;j++)
        {
            
            if (map[i][j] == 2 && visited[i][j] == 0)
            {
                queue<pair<int, int>> q;
                q.push({ i,j });
                visited[i][j] = 1;
                bool points = true;
                int cnt = 0;
                while (!q.empty())
                {
                    int a = q.front().first;
                    int b = q.front().second;
                    cnt++;
                    q.pop();
                    
                    for (int i = 0;i < 4;i++)
                    {
                        int c = a + dx[i];
                        int d = b + dy[i];

                        if (c >= 0 && c < N && d >= 0 && d < M)
                        {
                            if (map[c][d] == 0)
                            {
                                points = false;
                            }
                            else if(map[c][d] == 2 && visited[c][d] == 0)
                            {
                                visited[c][d] = 1;
                                q.push({ c,d });
                            }
                        }
                    }

                }
                if (points)
                    res += cnt;
            }
            
        }
    }

    ans = max(ans, res);

}
int main(int argc, const char* argv[]) {

    cin >> N >> M;

    vector<pair<int, int>> v;
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < M;j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 0)
            {
                v.push_back({ i,j });
            }
        }
    }

    ans = 0;
    

    int size = v.size();

    for (int i = 0;i < size;i++)
    {
        for (int j = 0;j < size;j++)
        {
            if (i == j)
                continue;
            map[v[i].first][v[i].second] = 1;
            map[v[j].first][v[j].second] = 1;

            kill();

            map[v[i].first][v[i].second] = 0;
            map[v[j].first][v[j].second] = 0;
        }
    }

    cout << ans;

    return 0;
}
