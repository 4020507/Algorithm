#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
char board[10][10];
pair<int, int> blue;
pair<int, int> red;
int check;
int ans;

void up()
{
    if (blue.first < red.first)
    {
        while (1)
        {
            if (board[blue.first - 1][blue.second] == '#')
                break;
            if (board[blue.first - 1][blue.second] == 'O')
            {
                blue.first--;
                check = -1;
                return;
            }
            blue.first--;
        }

        if (check == -1)
            return;
        while (1)
        {
            if (board[red.first - 1][red.second] == '#' || (red.first - 1 == blue.first && red.second == blue.second)) {
                break;
            }
            if (board[red.first - 1][red.second] == 'O')
            {
                red.first--;
                check = 1;
                return;
            }
            red.first--;
        }
    }
    else
    {
        while (1)
        {
            if (board[red.first - 1][red.second] == '#')
                break;
            if (board[red.first - 1][red.second] == 'O')
            {
                red.first--;
                check = 1;
                break;
            }
            red.first--;
        }

        while (1)
        {
            if (board[blue.first - 1][blue.second] == '#' || (blue.first - 1 == red.first && blue.second == red.second))
            {
                if (board[red.first][red.second] == 'O' && (blue.first - 1 == red.first && blue.second == red.second))
                {
                    check = -1;
                    blue.first--;
                }
                break;
            }
            if (board[blue.first - 1][blue.second] == 'O')
            {
                check = -1;
                break;
            }
            blue.first--;
        }
    }
}

void down()
{
    if (red.first > blue.first)
    {
        while (1)
        {
            if (board[red.first + 1][red.second] == '#')
                break;
            if (board[red.first + 1][red.second] == 'O')
            {
                red.first++;
                check = 1;
                break;
            }
            red.first++;
        }

        while (1)
        {
            if (board[blue.first + 1][blue.second] == '#' || (red.first == blue.first + 1 && red.second == blue.second))
            {
                if (board[red.first][red.second] == 'O' && (red.first == blue.first + 1 && red.second == blue.second))
                {
                    blue.first++;
                    check = -1;
                }
                break;
            }
            if (board[blue.first + 1][blue.second] == 'O')
            {
                check = -1;
                return;
            }
            blue.first++;
        }
    }
    else
    {
        while (1)
        {
            if (board[blue.first + 1][blue.second] == '#')
                break;
            if (board[blue.first + 1][blue.second] == 'O')
            {
                blue.first++;
                check = -1;
                return;
            }
            blue.first++;
        }

        while (1)
        {
            if (board[red.first + 1][red.second] == '#' || (blue.first == red.first + 1 && blue.second == red.second))
                break;
            if (board[red.first + 1][red.second] == 'O')
            {
                red.first++;
                check = 1;
                return;
            }
            red.first++;
        }
    }
}

void left()
{
    if (blue.second < red.second)
    {
        while (1)
        {
            if (board[blue.first][blue.second - 1] == '#')
                break;
            if (board[blue.first][blue.second - 1] == 'O')
            {
                blue.second--;
                check = -1;
                break;
            }
            blue.second--;
        }

        if (check == -1)
            return;
        while (1)
        {
            if (board[red.first][red.second - 1] == '#' || (red.first == blue.first && red.second - 1 == blue.second))
                break;
            if (board[red.first][red.second - 1] == 'O')
            {
                red.second--;
                check = 1;
                return;
            }
            red.second--;
        }
    }
    else
    {
        while (1)
        {
            if (board[red.first][red.second - 1] == '#')
                break;
            if (board[red.first][red.second - 1] == 'O')
            {
                red.second--;
                check = 1;
                break;
            }
            red.second--;
        }

        while (1)
        {
            if (board[blue.first][blue.second - 1] == '#' || (blue.first == red.first && blue.second - 1 == red.second))
            {
                if (board[red.first][red.second] == 'O' && (blue.first == red.first && blue.second - 1 == red.second))
                {
                    blue.second--;
                    check = -1;
                }
                break;
            }
            if (board[blue.first][blue.second - 1] == 'O')
            {
                blue.second--;
                check = -1;
                return;
            }
            blue.second--;
        }
    }
}

void right()
{
    if (red.second > blue.second)
    {
        while (1)
        {
            if (board[red.first][red.second + 1] == '#')
                break;
            if (board[red.first][red.second + 1] == 'O')
            {
                red.second++;
                check = 1;
                break;
            }
            red.second++;
        }

        while (1)
        {
            if (board[blue.first][blue.second + 1] == '#' || (blue.first == red.first && blue.second + 1 == red.second))
            {
                if (board[red.first][red.second] == 'O' && (blue.first == red.first && blue.second + 1 == red.second))
                {
                    blue.second++;
                    check = -1;
                }
                break;
            }
            if (board[blue.first][blue.second + 1] == 'O')
            {
                check = -1;
                return;
            }
            blue.second++;
        }
    }
    else
    {
        while (1)
        {
            if (board[blue.first][blue.second + 1] == '#')
                break;
            if (board[blue.first][blue.second + 1] == 'O')
            {
                blue.second++;
                check = -1;
                return;
            }
            blue.second++;
        }

        while (1)
        {
            if (board[red.first][red.second + 1] == '#' || (red.first == blue.first && red.second + 1 == blue.second))
                break;
            if (board[red.first][red.second + 1] == 'O')
            {
                red.second++;
                check = 1;
                return;
            }
            red.second++;
        }
    }
}

void sol(int cnt)
{
    if (cnt > 10 || cnt >= ans)
    {
        return;
    }

    int r_x = red.first;
    int r_y = red.second;
    int b_x = blue.first;
    int b_y = blue.second;

    left();
    if (check == -1)
    {
        check = 0;
        red.first = r_x;
        red.second = r_y;
        blue.first = b_x;
        blue.second = b_y;
    }
    else if (check == 1)
    {
        ans = min(ans, cnt);
        check = 0;
        return;
    }
    sol(cnt + 1);
    red.first = r_x;
    red.second = r_y;
    blue.first = b_x;
    blue.second = b_y;

    right();
    if (check == -1)
    {
        check = 0;
        red.first = r_x;
        red.second = r_y;
        blue.first = b_x;
        blue.second = b_y;
    }
    else if (check == 1)
    {
        ans = min(ans, cnt);
        check = 0;
        return;
    }
    sol(cnt + 1);
    red.first = r_x;
    red.second = r_y;
    blue.first = b_x;
    blue.second = b_y;

    up();
    if (check == -1)
    {
        check = 0;
        red.first = r_x;
        red.second = r_y;
        blue.first = b_x;
        blue.second = b_y;
    }
    else if (check == 1)
    {
        ans = min(ans, cnt);
        check = 0;
        return;
    }
    sol(cnt + 1);
    red.first = r_x;
    red.second = r_y;
    blue.first = b_x;
    blue.second = b_y;

    down();
    if (check == -1)
    {
        check = 0;
        red.first = r_x;
        red.second = r_y;
        blue.first = b_x;
        blue.second = b_y;
    }
    else if (check == 1)
    {
        ans = min(ans, cnt);
        check = 0;
        return;
    }
    sol(cnt + 1);

}
int main(int argc, const char* argv[]) {

    cin >> N >> M;

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < M;j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 'R')
            {
                red.first = i;
                red.second = j;
            }
            else if (board[i][j] == 'B')
            {
                blue.first = i;
                blue.second = j;
            }
        }
    }

    check = 0;
    ans = 11;
    
    sol(1);

    if (ans == 11)
        cout << -1;
    else
        cout << ans;
    return 0;
}
