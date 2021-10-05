#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int ans;
vector<vector<int>> up(vector<vector<int>> square)
{
    for (int j = N - 1;j >= 0;j--)
    {
        for (int i = 0;i < N;i++)
        {
            if (square[i][j] == 0)
            {
                for (int k = i + 1;k < N;k++)
                {
                    if (square[k][j] != 0)
                    {
                        square[i][j] = square[k][j];
                        square[k][j] = 0;
                        i--;
                        break;
                    }
                }
                continue;
            }
            
            for (int k = i + 1;k < N;k++)
            {
                if (square[k][j] != 0)
                {
                    if (square[k][j] == square[i][j])
                    {
                        square[i][j] *= 2;
                        square[k][j] = 0;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }

    return square;
}

vector<vector<int>> down(vector<vector<int>> square)
{
    for (int j = N - 1;j >= 0;j--)
    {
        for (int i = N - 1;i >= 0;i--)
        {
            if (square[i][j] == 0)
            {
                for (int k = i - 1;k >= 0;k--)
                {
                    if (square[k][j] != 0)
                    {
                        square[i][j] = square[k][j];
                        square[k][j] = 0;
                        i++;
                        break;
                    }
                }
                continue;
            }
            for (int k = i - 1;k >= 0;k--)
            {
                if (square[k][j] != 0)
                {
                    if (square[k][j] == square[i][j])
                    {
                        square[i][j] *= 2;
                        square[k][j] = 0;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }

    return square;
}

vector<vector<int>> left(vector<vector<int>> square)
{
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
        {
            if (square[i][j] == 0)
            {
                for (int k = j + 1;k < N;k++)
                {
                    if (square[i][k] != 0)
                    {
                        square[i][j] = square[i][k];
                        square[i][k] = 0;
                        j--;
                        break;
                    }
                }
                continue;
            }
            for (int k = j + 1;k < N;k++)
            {
                if (square[i][k] != 0)
                {
                    if (square[i][k] == square[i][j])
                    {
                        square[i][j] *= 2;
                        square[i][k] = 0;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }

    return square;
}

vector<vector<int>> right(vector<vector<int>> square)
{
    for (int i = 0;i < N;i++)
    {
        for (int j = N - 1;j >= 0;j--)
        {
            if (square[i][j] == 0)
            {
                for (int k = j - 1;k >= 0;k--)
                {
                    if (square[i][k] != 0)
                    {
                        square[i][j] = square[i][k];
                        square[i][k] = 0;
                        j++;
                        break;
                    }
                }
                continue;
            }
            for (int k = j - 1;k >= 0;k--)
            {
                if (square[i][k] != 0)
                {
                    if (square[i][k] == square[i][j])
                    {
                        square[i][j] *= 2;
                        square[i][k] = 0;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }

    return square;
}

void mix(vector<vector<int>> square, int count)
{
    if (count == 5)
    {
        for (int i = 0;i < N;i++)
        {
            for (int j = 0;j < N;j++)
            {
                ans = max(ans, square[i][j]);
            }
        }
        return;
    }

    mix(up(square), count + 1);
    mix(down(square), count + 1);
    mix(right(square), count + 1);
    mix(left(square), count + 1);
}

int main(int argc, const char* argv[]) {

    cin >> N;
    vector<vector<int>> square(N);
    ans = 0;
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
        {
            int a;
            cin >> a;
            square[i].push_back(a);
        }
    }

    mix(square,0);

    cout << ans;

    return 0;
}
