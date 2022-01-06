#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

bool isPrime[4000001];
int arr[4000001];
int len;

int main(void)
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;

    int N;
    cin >> N;

    len = 0;
    for (int i = 2;i <= sqrt(N);i++)
    {
        if (isPrime[i])
        {
            int j = 2;
            while (i * j <= N)
            {
                isPrime[i * j] = false;
                j++;
            }
        }
    }

    for (int i = 2;i <= N;i++)
        if (isPrime[i])
            arr[len++] = i;

    int plus_idx = 0;
    int minus_idx = 0;
    int sum = 0;
    int ans = 0;
    while (plus_idx <= len && minus_idx <= plus_idx)
    {
        if (sum < N)
        {
            if (plus_idx == len)
                break;
            sum += arr[plus_idx++];
        }
        else if (sum >= N)
        {
            if (sum == N)
                ans++;
            sum -= arr[minus_idx++];
        }
    }

    cout << ans;

    return 0;

}
