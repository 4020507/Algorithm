#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int bytes[101] = { 0, };
int cost[101] = { 0, };
int dp[101][10001] = { 0, };

int main(int argc, const char* argv[]) {

    cin >> N >> M;

    for (int i = 1;i <= N;i++)
        cin >> bytes[i];

    int sum = 0;
    for (int i = 1;i <= N;i++) {
        cin >> cost[i];
        sum += cost[i];
    }

    for (int i = 1;i <= N;i++)
    {
        for (int j = 0;j <= sum;j++)
        {
            if (j - cost[i] >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + bytes[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    for (int i = 0;i <= sum;i++)
    {
        if (dp[N][i] >= M)
        {
            cout << i;
            break;
        }
    }
    return 0;
}
