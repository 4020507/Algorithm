#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <math.h>

#define INF 1000000000

using namespace std;

long long a[1000];
long long b[1000];

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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int N, M;
    cin >> N;

    for (int i = 0;i < N;i++)
        cin >> a[i];
    cin >> M;
    for (int j = 0;j < M;j++)
        cin >> b[j];

    long long ans = 1;
    long long val;
    bool check = false;
    for(int i = 0;i<N;i++)
        for (int j = 0;j < M;j++)
        {
            if (a[i] > b[j])
                val = gcd(a[i], b[j]);
            else
                val = gcd(b[j], a[i]);

            ans *= val;
            a[i] /= val;
            b[j] /= val;

            if (ans >= INF) {
                ans %= INF;
                check = true;
            }
        }

    if (check)
        printf("%09lld", ans);
    else
        cout << ans;
    return 0;

}
