#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;

int down[100001];
int up[100001];
int main(void)
{
    int N, H;

    cin >> N >> H;

    for (int i = 0;i < N / 2;i++)
        cin >> down[i] >> up[i];

    sort(down, down + N / 2);
    sort(up, up + N / 2);

    int ans = 1e9;
    int cnt = 0;
    for (int i = 1;i <= H;i++)
    {
        auto lb = lower_bound(down, down + N / 2, i) - down;
        auto ub = upper_bound(up, up + N / 2, H - i) - up;
        int val = N - (ub + lb);

        if (ans == val)
            cnt++;
        else if (ans > val)
        {
            ans = val;
            cnt = 1;
        }
    }

    cout << ans << ' ' << cnt;
    return 0;

}
