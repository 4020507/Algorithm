#include<iostream>
#include<string.h>

#pragma warning(disable:4996)
using namespace std;

int N;
int map[100][100];
long long dp[100][100];

int main(int argc, char** argv)
{
    cin >> N;

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
            cin >> map[i][j];
    }
    dp[0][0] = 1;

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
        {
            if (i == N - 1 && j == N - 1)
            {
                cout << dp[N - 1][N - 1];
            }

            if (dp[i][j] == 0)
                continue;
            
            if (i + map[i][j] < N)
                dp[i + map[i][j]][j] += dp[i][j];
            if (j + map[i][j] < N)
                dp[i][j + map[i][j]] += dp[i][j];
        }
    }

    return 0;
}
