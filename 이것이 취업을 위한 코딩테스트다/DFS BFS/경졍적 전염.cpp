#pragma warning(disable:4996)
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int map[200][200];
int N, K;
int S, X, Y;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

struct virus
{
    int second;
    int x;
    int y;
    int num;

    virus(int second, int x, int y, int num)
    {
        this->second = second;
        this->x = x;
        this->y = y;
        this->num = num;
    }

};

bool cmp(virus a,virus b)
{
    return a.num < b.num;
}
int main(void) {
    
    cin >> N >> K;

    vector <virus> v;
    for (int i = 0;i < N;i++)
    {
        for (int j = 0; j < N;j++)
        {
            cin >> map[i][j];

            if (map[i][j] > 0)
            {
                v.push_back((virus(0, i, j, map[i][j])));
            }
        }
    }
    sort(v.begin(), v.end(), cmp);

    queue<virus> q;

    for (auto i : v)
    {
        q.push(i);
    }

    cin >> S >> X >> Y;

    while (!q.empty())
    {
        virus a = q.front();
        q.pop();

        if (a.second == S)
        {
            cout << map[X - 1][Y - 1] << endl;
            break;
        }

        for (int i = 0;i < 4;i++)
        {
            int c = a.x + dx[i];
            int d = a.y + dy[i];

            if (c >= 0 && c < N && d >= 0 && d < N)
            {
                if (map[c][d] == 0)
                {
                    map[c][d] = a.num;
                    q.push(virus(a.second + 1, c, d, a.num));
                }

            }
        }
    }

    return 0;
    
}
