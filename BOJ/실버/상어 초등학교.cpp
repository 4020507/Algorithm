#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int classrooms[20][20];
vector<int> students[401];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int N;
pair<int, int> scoreboard[20][20];

void sit(int num)
{
    memset(scoreboard, 0, sizeof(scoreboard));
    int empty, nx, ny, friends;
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
        {
            if (classrooms[i][j] == 0)
            {
                empty = 0;
                friends = 0;
                for (int k = 0;k < 4;k++)
                {
                    nx = i + dx[k];
                    ny = j + dy[k];

                    if (nx >= 0 && nx < N && ny >= 0 && ny < N)
                    {
                        if (classrooms[nx][ny] == 0)
                            empty++;
                        else if (classrooms[nx][ny] == students[num][0] ||
                            classrooms[nx][ny] == students[num][1] ||
                            classrooms[nx][ny] == students[num][2] ||
                            classrooms[nx][ny] == students[num][3])
                            friends++;
                    }
                }
                scoreboard[i][j].first = empty;
                scoreboard[i][j].second = friends;
            }
        }
    }

    int x, y;
    friends = -1;
    empty = -1;
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
        {
            if (classrooms[i][j] != 0)
                continue;
            if (scoreboard[i][j].second > friends)
            {
                friends = scoreboard[i][j].second;
                empty = scoreboard[i][j].first;
                x = i;
                y = j;
            }
            else if (scoreboard[i][j].second == friends)
            {
                if (scoreboard[i][j].first > empty)
                {
                    x = i;
                    y = j;
                    empty = scoreboard[i][j].first;
                }
            }
        }
    }

    classrooms[x][y] = num;
}

int scores(int cnt)
{
    if (cnt == 0)
        return 0;
    if (cnt == 1)
        return 1;
    if (cnt == 2)
        return 10;
    if (cnt == 3)
        return 100;
    if (cnt == 4)
        return 1000;
}
int satisfy()
{
    int sum = 0;
    int nx, ny, friends, num;
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
        {
            friends = 0;
            num = classrooms[i][j];
            for (int k = 0;k < 4;k++)
            {
                nx = i + dx[k];
                ny = j + dy[k];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N)
                {
                    if (students[num][0] == classrooms[nx][ny] ||
                        students[num][1] == classrooms[nx][ny] ||
                        students[num][2] == classrooms[nx][ny] ||
                        students[num][3] == classrooms[nx][ny])
                        friends++;
                }
            }
            sum += scores(friends);
            
        }
    }

    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> N;

    int a, b, c, d, e;
    vector<int> seq;
    for (int i = 0;i < N * N;i++)
    {
        cin >> a >> b >> c >> d >> e;
        seq.push_back(a);
        students[a].push_back(b);
        students[a].push_back(c);
        students[a].push_back(d);
        students[a].push_back(e);
    }

    for (int i = 0;i < N * N;i++)
    {
        sit(seq[i]);
    }

    cout << satisfy();
    return 0;
}
