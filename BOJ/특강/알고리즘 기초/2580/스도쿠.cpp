#include <iostream>
#include <vector>

using namespace std;

int map[9][9];
vector<pair<int, int>> zeroes;
int cnt;
bool ans;
bool check(int x, int y)
{
    int nx = x / 3;
    int ny = y / 3;

    for (int i = 0;i < 9;i++)
    {
        if (map[x][i] == map[x][y] && i != y)
            return false;
        if (map[i][y] == map[x][y] && i != x)
            return false;
    }

    for (int i = nx * 3;i < nx * 3 + 3;i++)
    {
        for (int j = ny * 3;j < ny * 3 + 3;j++)
        {
            if (map[i][j] == map[x][y])
                if(i != x && j != y)
                    return false;
        }
    }
    return true;
}
void sudoku(int n)
{

    if (n == zeroes.size())
    {
        for (int i = 0;i < 9;i++)
        {
            for (int j = 0;j < 9;j++)
            {
                cout << map[i][j] << ' ';
            }
            cout << '\n';
        }
        ans = true;
        return;
    }

    for (int i = 1;i <= 9;i++)
    {
        map[zeroes[n].first][zeroes[n].second] = i;
        if (check(zeroes[n].first, zeroes[n].second))
            sudoku(n + 1);
        if (ans)
            return;
    }

    map[zeroes[n].first][zeroes[n].second] = 0;
}
int main(int argc, const char* argv[]) {

    for (int i = 0;i < 9;i++) {
        for (int j = 0;j < 9;j++) {
            cin >> map[i][j];

            if (map[i][j] == 0)
                zeroes.push_back({ i,j });
        }
    }

    ans = false;
    sudoku(0);
    return 0;
}
