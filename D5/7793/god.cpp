#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<string>
 
using namespace std;
 
int N, M, Answer;
char MAP[50][50];
int Devil_MAP[50][50];
bool Visit[50][50];
vector<pair<int, int>> Devil;
pair<int, int> Start, End;
 
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
 
void Make_Devil_MAP()
{
    queue<pair<int, int>> Q;
    for(int i = 0 ; i < Devil.size(); i++)
    { 
        int x = Devil[i].first;
        int y = Devil[i].second;
        Q.push(make_pair(x, y));
        Devil_MAP[x][y] = 0;        
    }
 
    while (Q.empty() == 0)
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (MAP[nx][ny] == 'X') continue;
                if (MAP[nx][ny] == 'D') continue;
 
                if (Devil_MAP[nx][ny] > Devil_MAP[x][y] + 1)
                {
                    Devil_MAP[nx][ny] = Devil_MAP[x][y] + 1;
                    Q.push(make_pair(nx, ny));
                }
            }
        }
    }
}
 
int Move()
{
    queue<pair<pair<int, int>, int>> Q;
    Q.push(make_pair(make_pair(Start.first, Start.second), 0));
    Visit[Start.first][Start.second] = true;
 
    while (Q.empty() == 0)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Cnt = Q.front().second;
        Q.pop();
 
        if (x == End.first && y == End.second) return Cnt;
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (MAP[nx][ny] == 'X') continue;
                if (Visit[nx][ny] == true) continue;
 
                if (Devil_MAP[nx][ny] > Cnt + 1)
                {
                    Visit[nx][ny] = true;
                    Q.push(make_pair(make_pair(nx, ny), Cnt + 1));
                }
            }
        }
    }
    return -1;
}
 
int main(void)
{
    int Tc; cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
       memset(Visit, false, sizeof(Visit));
        Devil.clear();
        for (int i = 0; i < 50; i++)
        {
            for(int j = 0 ; j < 50; j++)
            { 
                Devil_MAP[i][j] = 500;
            }
        }
        
         cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 'S')
            {
                Start.first = i;
                Start.second = j;
            }
            else if (MAP[i][j] == 'D')
            {
                End.first = i;
                End.second = j;
            }
            else if (MAP[i][j] == '*') Devil.push_back(make_pair(i, j));
        }
    }

        Make_Devil_MAP();
   		 Answer = Move();
 
        cout << "#" << T << " ";
        if (Answer == -1) cout << "GAME OVER" << endl;
        else cout << Answer << endl;
    }
 
    return 0;
}
