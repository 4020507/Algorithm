#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int map[13][13];
//0흰색, 1빨강,2파랑
//오,왼,위,아래

int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };

vector <int> v[13][13];
class piece {
public:
    int x;
    int y;
    int dir;
};

int main(int argc, const char* argv[]) {
    
    int N, K;
    piece p[13];

    cin >> N >> K;

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
            cin >> map[i][j];
    }

    for (int i = 1;i <= K;i++)
    {
        cin >> p[i].x >> p[i].y >> p[i].dir;
        
        v[--p[i].x][--p[i].y].push_back(i);

        if (v[p[i].x][p[i].y].size() > 3)
        {
            cout << 1;
            return 0;
        }
    }

    int x, y;
    int t_x, t_y;

    for (int i = 1;i <= 1000;i++)
    {
        for (int j = 1;j <= K;j++)
        {
            x = p[j].x + dx[p[j].dir];
            y = p[j].y + dy[p[j].dir];
            t_x = p[j].x;
            t_y = p[j].y;
            if (x >= 0 && x < N && y >= 0 && y < N)
            {
                if (map[x][y] == 0)
                {
                    bool upper = false;
                    int cnt = 0;;

                    for (int k = 0;k < v[t_x][t_y].size();k++)
                    {
                        int num = v[t_x][t_y][k];
                        if (j == num)
                        {
                            upper = true;
                            p[num].x = x;
                            p[num].y = y;
                            cnt++;
                            v[x][y].push_back(num);
                        }
                        else if (upper)
                        {
                            p[num].x = x;
                            p[num].y = y;
                            v[x][y].push_back(num);
                            cnt++;
                        }
                    }

                    for (int k = 0;k < cnt;k++)
                    {
                        v[t_x][t_y].pop_back();
                    }
                }
                else if (map[x][y] == 1)
                {
                    int cnt = 0;

                    for (int k = v[t_x][t_y].size() - 1;k >= 0;k--)
                    {
                        int num = v[t_x][t_y][k];
                        if (num == j)
                        {
                            p[num].x = x;
                            p[num].y = y;
                            cnt++;
                            v[x][y].push_back(num);
                            break;
                        }
                        else
                        {
                            p[num].x = x;
                            p[num].y = y;
                            cnt++;
                            v[x][y].push_back(num);
                        }
                    }

                    for (int k = 0;k < cnt;k++)
                        v[t_x][t_y].pop_back();
                }
                else if (map[x][y] == 2)
                {
                    if (p[j].dir == 1)
                    {
                        p[j].dir = 2;
                    }
                    else if (p[j].dir == 2)
                    {
                        p[j].dir = 1;
                    }
                    else if (p[j].dir == 3)
                    {
                        p[j].dir = 4;
                    }
                    else
                    {
                        p[j].dir = 3;
                    }

                    x = p[j].x + dx[p[j].dir];
                    y = p[j].y + dy[p[j].dir];
                    t_x = p[j].x;
                    t_y = p[j].y;

                    if (x >= 0 && x < N && y >= 0 && y < N)
                    {
                        if (map[x][y] == 2)
                            continue;

                        if (map[x][y] == 0)
                        {
                            bool upper = false;
                            int cnt = 0;;

                            for (int k = 0;k < v[t_x][t_y].size();k++)
                            {
                                int num = v[t_x][t_y][k];
                                if (j == num)
                                {
                                    upper = true;
                                    p[num].x = x;
                                    p[num].y = y;
                                    cnt++;
                                    v[x][y].push_back(num);
                                }
                                else if (upper)
                                {
                                    p[num].x = x;
                                    p[num].y = y;
                                    v[x][y].push_back(num);
                                    cnt++;
                                }
                            }

                            for (int k = 0;k < cnt;k++)
                            {
                                v[t_x][t_y].pop_back();
                            }
                        }
                        else if (map[x][y] == 1)
                        {
                            int cnt = 0;

                            for (int k = v[t_x][t_y].size() - 1;k >= 0;k--)
                            {
                                int num = v[t_x][t_y][k];
                                if (num == j)
                                {
                                    p[num].x = x;
                                    p[num].y = y;
                                    cnt++;
                                    v[x][y].push_back(num);
                                    break;
                                }
                                else
                                {
                                    p[num].x = x;
                                    p[num].y = y;
                                    cnt++;
                                    v[x][y].push_back(num);
                                }
                            }

                            for (int k = 0;k < cnt;k++)
                                v[t_x][t_y].pop_back();
                        }

                    }
                }
            }
            else
            {
                if (p[j].dir == 1)
                {
                    p[j].dir = 2;
                }
                else if (p[j].dir == 2)
                {
                    p[j].dir = 1;
                }
                else if (p[j].dir == 3)
                {
                    p[j].dir = 4;
                }
                else
                {
                    p[j].dir = 3;
                }

                x = p[j].x + dx[p[j].dir];
                y = p[j].y + dy[p[j].dir];
                t_x = p[j].x;
                t_y = p[j].y;

                if (map[x][y] == 0)
                {
                    bool upper = false;
                    int cnt = 0;;

                    for (int k = 0;k < v[t_x][t_y].size();k++)
                    {
                        int num = v[t_x][t_y][k];
                        if (j == num)
                        {
                            upper = true;
                            p[num].x = x;
                            p[num].y = y;
                            cnt++;
                            v[x][y].push_back(num);
                        }
                        else if (upper)
                        {
                            p[num].x = x;
                            p[num].y = y;
                            v[x][y].push_back(num);
                            cnt++;
                        }
                    }

                    for (int k = 0;k < cnt;k++)
                    {
                        v[t_x][t_y].pop_back();
                    }
                }
                else if (map[x][y] == 1)
                {
                    int cnt = 0;

                    for (int k = v[t_x][t_y].size() - 1;k >= 0;k--)
                    {
                        int num = v[t_x][t_y][k];
                        if (num == j)
                        {
                            p[num].x = x;
                            p[num].y = y;
                            cnt++;
                            v[x][y].push_back(num);
                            break;
                        }
                        else
                        {
                            p[num].x = x;
                            p[num].y = y;
                            cnt++;
                            v[x][y].push_back(num);
                        }
                    }

                    for (int k = 0;k < cnt;k++)
                        v[t_x][t_y].pop_back();
                }
                else if (map[x][y] == 2)
                {
                    if (p[j].dir == 1)
                    {
                        p[j].dir = 2;
                    }
                    else if (p[j].dir == 2)
                    {
                        p[j].dir = 1;
                    }
                    else if (p[j].dir == 3)
                    {
                        p[j].dir = 4;
                    }
                    else
                    {
                        p[j].dir = 3;
                    }

                    x = p[j].x + dx[p[j].dir];
                    y = p[j].y + dy[p[j].dir];
                    t_x = p[j].x;
                    t_y = p[j].y;

                    if (x >= 0 && x < N && y >= 0 && y < N)
                    {
                        if (map[x][y] == 2)
                            continue;

                        if (map[x][y] == 0)
                        {
                            bool upper = false;
                            int cnt = 0;;

                            for (int k = 0;k < v[t_x][t_y].size();k++)
                            {
                                int num = v[t_x][t_y][k];
                                if (j == num)
                                {
                                    upper = true;
                                    p[num].x = x;
                                    p[num].y = y;
                                    cnt++;
                                    v[x][y].push_back(num);
                                }
                                else if (upper)
                                {
                                    p[num].x = x;
                                    p[num].y = y;
                                    v[x][y].push_back(num);
                                    cnt++;
                                }
                            }

                            for (int k = 0;k < cnt;k++)
                            {
                                v[t_x][t_y].pop_back();
                            }
                        }
                        else if (map[x][y] == 1)
                        {
                            int cnt = 0;

                            for (int k = v[t_x][t_y].size() - 1;k >= 0;k--)
                            {
                                int num = v[t_x][t_y][k];
                                if (num == j)
                                {
                                    p[num].x = x;
                                    p[num].y = y;
                                    cnt++;
                                    v[x][y].push_back(num);
                                    break;
                                }
                                else
                                {
                                    p[num].x = x;
                                    p[num].y = y;
                                    cnt++;
                                    v[x][y].push_back(num);
                                }
                            }

                            for (int k = 0;k < cnt;k++)
                                v[t_x][t_y].pop_back();
                        }

                    }
                }
            }

            for (int k = 1;k <= K;k++)
            {
                if (v[p[k].x][p[k].y].size() > 3)
                {
                    cout << i;
                    return 0;
                }
            }
        }
    }

    cout << -1;
    return 0;
}
