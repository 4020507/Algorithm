#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
long long arr[1000001];
long long lgcd[1000001];
long long rgcd[1000001];

long long gcd(long long a, long long b)
{
    long long c;

    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}
int main(void)
{
    int N;
    cin >> N;

    for (int i = 1;i <= N;i++)
        scanf("%lld", &arr[i]);
    for (int i = 1;i <= N;i++)
        lgcd[i] = gcd(arr[i], lgcd[i-1]);
    for (int i = N;i >= 1;i--)
        rgcd[i] = gcd(arr[i], rgcd[i + 1]);

    int K = -1;
    int GCD = 0;
    int res;
    for (int i = 1;i <= N;i++)
    {
        res = gcd(lgcd[i-1], rgcd[i+1]);

        if (res > GCD && arr[i] % res != 0)
        {
            GCD = res;
            K = arr[i];
        }
    }
    
    if (K == -1)
        printf("%d", K);
    else
        printf("%d %d", GCD, K);
    return 0;

}
