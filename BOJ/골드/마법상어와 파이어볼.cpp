#pragma warning(disable:4996)
#include <iostream>
#include <vector>
using namespace std;

class fireball
{
public:
    int r;
    int c;
    int m;
    int s;
    int d;
    fireball(int r, int c, int m, int s, int d)
    {
        this->r = r;
        this->c = c;
        this->m = m;
        this->s = s;
        this->d = d;
    }
};

int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
int N, M, K;
vector<fireball> field[52][52];
vector<fireball> fb;

void clear()
{
    for (int i = 1;i <= N;i++)
        for (int j = 1;j <= N;j++)
            field[i][j].clear();
}

void move()
{
    int x, y;
    for (int i = 0;i < fb.size();i++)
    {
        x = fb[i].r + dx[fb[i].d] * fb[i].s;
        y = fb[i].c + dy[fb[i].d] * fb[i].s;

        while (x > N)
            x -= N;
        while (x < 1)
            x += N;
        while (y > N)
            y -= N;
        while (y < 1)
            y += N;

        field[x][y].push_back({ x,y,fb[i].m,fb[i].s,fb[i].d });

    }
}

void seperate()
{
    vector<fireball> t;
    int m, s;
    int isSame;
    int size;
    for (int i = 1;i <= N;i++)
    {
        for (int j = 1;j <= N;j++)
        {
            if (field[i][j].size() == 1)
            {
                t.push_back(field[i][j][0]);
            }
            else if (field[i][j].size() > 1)
            {
                m = 0;
                s = 0;
                size = field[i][j].size();

                if (field[i][j][0].d % 2 == 1)
                    isSame = 0;
                else
                    isSame = 1;

                for (int k = 0;k < size;k++)
                {
                    m += field[i][j][k].m;
                    s += field[i][j][k].s;

                    if (isSame == -1)
                        continue;
                    if (field[i][j][k].d % 2 == 1 && isSame == 0)
                        continue;
                    else if(field[i][j][k].d%2==1 && isSame == 1)
                        isSame = -1;
                    else if (field[i][j][k].d % 2 == 0 && isSame == 1)
                        continue;
                    else if(field[i][j][k].d % 2 == 0 && isSame == 0)
                        isSame = -1;
                }

                m /= 5;
                s /= size;

                if (m == 0)
                    continue;
                if (isSame == -1)
                {
                    t.push_back({ i,j,m,s,1 });
                    t.push_back({ i,j,m,s,3 });
                    t.push_back({ i,j,m,s,5 });
                    t.push_back({ i,j,m,s,7 });
                }
                else
                {
                    t.push_back({ i,j,m,s,0 });
                    t.push_back({ i,j,m,s,2 });
                    t.push_back({ i,j,m,s,4 });
                    t.push_back({ i,j,m,s,6 });
                }
            }
        }
    }

    fb = t;
}
int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> N >> M >> K;

    int r, c, m, s, d;

    for (int i = 0;i < M;i++)
    {
        cin >> r >> c >> m >> s >> d;

        fb.push_back({ r,c,m,s,d });
    }
    
    for (int i = 0;i < K;i++)
    {
        clear();
        move();
        seperate();
    }

    int ans = 0;

    for (auto f : fb)
    {
        ans += f.m;
    }

    cout << ans;
    return 0;

}
