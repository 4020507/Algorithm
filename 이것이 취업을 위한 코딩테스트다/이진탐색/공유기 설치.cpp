#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
using namespace std;

int wifi[200000];
int main(void) {

    int N, C;

    cin >> N >> C;

    for (int i = 0;i < N;i++)
        cin >> wifi[i];
    
    sort(wifi, wifi + N);

    int mini = 1;
    int maxi = wifi[N - 1] - wifi[0];
    int ans = 0;
    while (mini <= maxi)
    {
        int mid = (mini + maxi) / 2;

        int value = wifi[0];

        int count = 1;

        for (int i = 1;i < N;i++)
        {
            if (wifi[i] >= value + mid)
            {
                value = wifi[i];
                count++;
            }
        }

        if (count >= C)
        {
            mini = mid + 1;
            ans = mid;
        }
        else
            maxi = mid - 1;
    }

    cout << ans << '\n';

    return 0;
    
}
