#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


int city[21][21];
int elections[5];
int N;
int diff;
bool first_election(int r, int c, int x, int y, int d1, int d2)
{
    if (r >= 1 && r < x + d1 && 1 <= c && c <= y && !(r >= x && c >= y - r + x))
        return true;
    return false;
}

bool second_election(int r, int c, int x, int y, int d1, int d2)
{
    if (r >= 1 && r <= x + d2 && y < c && c <= N && !(r>=x && c<=y+r-x))
        return true;
    return false;
}

bool third_election(int r, int c, int x, int y, int d1, int d2)
{
    if (x + d1 <= r && r <= N && c >= 1 && c < y - d1 + d2 && !(r<=x+d1+d2 && c>=(y-d1+d2-(x+d1+d2-r))))
        return true;
    return false;
}

bool fourth_election(int r, int c, int x, int y, int d1, int d2)
{
    if (x + d2 < r && r <= N && y - d1 + d2 <= c && c <= N && !(r<=x+d1+d2 && c<=(y-d1+d2+x+d1+d2-r)))
        return true;
    return false;
}

int difference(int x, int y, int d1, int d2)
{
    for (int i = 1;i <= N;i++)
    {
        for (int j = 1;j <= N;j++)
        {
            if (first_election(i, j, x, y, d1, d2))
            {
                elections[0] += city[i][j];
            }
            else if (second_election(i, j, x, y, d1, d2))
                elections[1] += city[i][j];
            else if (third_election(i, j, x, y, d1, d2))
                elections[2] += city[i][j];
            else if (fourth_election(i, j, x, y, d1, d2))
                elections[3] += city[i][j];
            else
                elections[4] += city[i][j];
        }
    }

    sort(elections, elections + 5);

    return elections[4] - elections[0];
}
int main() {

    cin >> N;

    for (int i = 1;i <= N;i++)
        for (int j = 1;j <= N;j++)
            cin >> city[i][j];

    diff = 1e9;

    for (int x = 1;x <= N - 2;x++)
    {
        for (int y = 2;y <= N - 1;y++)
        {
            for (int d1 = 1;y >= 1 + d1 && d1 <= N - x - 1;d1++)
            {
                for (int d2 = 1;d2 <= N - x - d1 && d2 <= N - y;d2++)
                {
                    memset(elections, 0, sizeof(elections));

                    diff = min(diff, difference(x, y, d1, d2));
                }
            }
        }
    }

    cout << diff;
    return 0;
}
