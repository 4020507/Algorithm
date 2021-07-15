#pragma warning(disable:4996)
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

char map[6][6];
int N;
vector<pair<int, int>> teacher;
vector<pair<int, int>> put;

bool find(int x, int y, int direction)
{
    if (direction == 0)//위
    {
        while (x >= 0)
        {
            if (map[x][y] == 'S')
            {
                return true;
            }
            else if (map[x][y] == 'O')
                return false;
            x--;
       }
    }
    else if (direction == 1)//오른쪽
    {
        while (y < N)
        {
            if (map[x][y] == 'S')
                return true;
            else if (map[x][y] == 'O')
                return false;
            y++;
        }
    }
    else if (direction == 2)
    {
        while (x < N)
        {
            if (map[x][y] == 'S')
                return true;
            else if (map[x][y] == 'O')
                return false;
            x++;
        }
    }
    else if (direction == 3)
    {
        while (y >= 0)
        {
            if (map[x][y] == 'S')
                return true;
            else if (map[x][y] == 'O')
                return false;
            y--;
        }
    }

    return false;
}

bool monitor() {
    for (int i = 0;i < teacher.size();i++)
    {
        int x = teacher[i].first;
        int y = teacher[i].second;

        for (int i = 0;i < 4;i++)
        {
            if (find(x, y, i))
            {
                return true;
            }
        }
    }

    return false;
}
int main(void) {

    cin >> N;

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++) {
            cin >> map[i][j];
            if (map[i][j] == 'X')
                put.push_back(make_pair(i, j));
            else if (map[i][j] == 'T')
                teacher.push_back(make_pair(i, j)); 
        }
    }

    bool possible = false;

    vector<bool> p(put.size());
    fill(p.end() - 3, p.end(),true);

    do
    {
        for (int i = 0;i < put.size();i++)
        {
            if (p[i])
            {
                map[put[i].first][put[i].second] = 'O';
            }
        }

        if (!monitor())
        {
            possible = true;
            break;
        }

        for (int i = 0;i < put.size();i++)
        {
            if (p[i])
            {
                map[put[i].first][put[i].second] = 'X';
            }
        }
    } while (next_permutation(p.begin(), p.end()));


    if (!possible)
    {
        cout << "NO" << endl;
    }
    else
        cout << "YES" << endl;

    return 0;
    
}
