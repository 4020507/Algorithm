#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int board[21][21];
vector<pair<bool, pair<int, int>>> departure;
vector<pair<int, int>> arrival;
int gas;
bool visited[21][21];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool check;
//가장 거리가 가까운 손님 찾기
int nearest(int x, int y)
{
    int diff = 1e9;
    int d_x, d_y;
    int a, b, c, d;
    int num, num_x, num_y;
    num = departure.size();

    for (int i = 0;i < departure.size();i++)
    {
        if (departure[i].first)
            continue;
        d_x = departure[i].second.first;
        d_y = departure[i].second.second;

        queue<pair<int,pair<int,int>>> q;
        q.push({ 0,{d_x,d_y } });
        memset(visited, false, sizeof(visited));
        int dist;
        while (!q.empty())
        {
            a = q.front().second.first;
            b = q.front().second.second;
            dist = q.front().first;

            if (dist > diff)
                break;

            if (a == x && b == y)
            {
                if (dist < diff)
                {
                    diff = dist;
                    num = i;
                    num_x = d_x;
                    num_y = d_y;
                }
                else if (diff == dist)
                {
                    if (d_x < num_x)
                    {
                        num = i;
                        num_x = d_x;
                        num_y = d_y;
                    }
                    else if (d_x == num_x && d_y < num_y)
                    {
                        num = i;
                        num_x = d_x;
                        num_y = d_y;
                    }
                }
                break;
            }
            q.pop();

            for (int i = 0;i < 4;i++)
            {
                c = a + dx[i];
                d = b + dy[i];

                if (c >= 1 && c <= N && d >= 1 && d <= N)
                {
                    if (!visited[c][d] && board[c][d] == 0)
                    {
                        visited[c][d] = true;
                        q.push({ dist + 1,{c,d} });
                    }
                }
            }
        }
    }

    if(diff != 1e9)
        gas -= diff;

    if (num == departure.size())
    {
        for (int i = 0;i < num;i++)
        {
            if (!departure[i].first)
            {
                check = false;
                break;
            }
        }
    }
    return num;
}

//손님을 도착지로 대려다주기
int get_to(int num)
{
    departure[num].first = true;
    int a, b, c, d, dist;
    a = departure[num].second.first;
    b = departure[num].second.second;

    queue<pair<int, pair<int, int>>> q;
    q.push({ 0,{a,b} });
    memset(visited, false, sizeof(visited));

    while (!q.empty())
    {
        dist = q.front().first;
        a = q.front().second.first;
        b = q.front().second.second;

        if (dist > gas)
            return -1;
        if (a == arrival[num].first && b == arrival[num].second)
        {
            gas = gas - dist + dist * 2;
            return gas;
        }

        q.pop();

        for (int i = 0;i < 4;i++)
        {
            c = a + dx[i];
            d = b + dy[i];

            if (c >= 1 && c <= N && d >= 1 && d <= N)
            {
                if (!visited[c][d] && board[c][d] == 0)
                {
                    visited[c][d] = true;
                    q.push({ dist + 1,{c,d} });
                }
            }
        }
    }

    return -1;
}

int main() {
    
    cin >> N >> M >> gas;

    for (int i = 1;i <= N;i++)
        for (int j = 1;j <= N;j++)
            cin >> board[i][j];

    int x, y, nx, ny;
    int d_x, d_y;
    cin >> d_x >> d_y;

    check = true;

    for (int i = 0;i < M;i++)
    {
        cin >> x >> y >> nx >> ny;
        departure.push_back({ false,{x,y} });
        arrival.push_back({ nx,ny });
    }

    int num = 0;

    while (1)
    {
        num = nearest(d_x, d_y);

        if (num == departure.size())
            break;
        gas = get_to(num);
        d_x = arrival[num].first;
        d_y = arrival[num].second;
        if (gas == -1)
            break;
    }

    if (!check)
        gas = -1;

    cout << gas;

    return 0;
}
