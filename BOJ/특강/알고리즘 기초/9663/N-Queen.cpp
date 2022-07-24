#pragma warning(disable:4996)
#include <iostream>
#include <math.h>
using namespace std;

int board[15];
int N;
int ans;
bool check(int idx)
{
    for (int i = 0;i < idx;i++)
    {
        if (board[i] == board[idx] || (idx - i == abs(board[idx] - board[i])))
        {
            return false;
        }
    }

    return true;
}

void setting(int n)
{
    if (n == N)
    {
        ans++;
        return;
    }

    for (int i = 0;i < N;i++)
    {
        board[n] = i;

        if (check(n))
        {
            setting(n + 1);
        }
    }
}
int main() {

    cin >> N;

    ans = 0;
    setting(0);

    cout << ans;

    return 0;
}
