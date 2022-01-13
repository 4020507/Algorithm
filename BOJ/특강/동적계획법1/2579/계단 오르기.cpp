#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

#define MAX 302

int dp[MAX];
int arr[MAX];
int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;

    for (int i = 1;i <= N;i++)
        cin >> arr[i];
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
    for (int i = 3;i <= N;i++)
    {
        dp[i] = max(dp[i-2] + arr[i],dp[i-3] + arr[i-1]+arr[i]);
    }

    cout << dp[N];

    return 0;

}
