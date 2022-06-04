#include<iostream>
#include<queue>
using namespace std;

int N;
long long dp[10000001];
int main(int argc, char** argv)
{
    cin >> N;
    queue<long long> q;
    for (int i = 1;i <= 9;i++)
    {
        q.push(i);
        dp[i] = i;
    }
    
    if (0 <= N && N <= 10)
    {
        cout << N;
        return 0;
    }
    int idx = 10;
    while (idx <= N && !q.empty())
    {
        long long num = q.front();
        q.pop();
        int end = num % 10;

        for (int i = 0;i < end;i++)
        {
            q.push(num * 10 + i);
            dp[idx++] = num * 10 + i;
        }
    }

    if (idx >= N && dp[N] != 0)
        cout << dp[N];
    else
        cout << -1;

    return 0;
}
