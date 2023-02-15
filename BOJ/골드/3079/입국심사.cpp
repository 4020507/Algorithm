#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long N, M;
unsigned long long test[100000];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> test[i];

    sort(test, test + N);

    
    unsigned long long left = 1;
    unsigned long long right = test[N - 1] * M;
    unsigned long long ans = right;
    unsigned long long mid;
    unsigned long long sum = 0;
    while (left <= right) {
        mid = (left + right) / 2;

        sum = 0;

        for (int i = 0; i < N; i++)
            sum += mid / test[i];

        if (sum < M) {
            left = mid + 1;
        }
        else {
            ans = min(mid,ans);
            right = mid - 1;
        }
    }

    cout << ans;

    return 0;

}
