#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;

long long N, M;
long long test[100000];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> test[i];

    sort(test, test + N);

    
    long long left = 1;
    long long right = test[N - 1] * M;
    long long ans = right;
    long long mid;
    long long sum = 0;
    while (left <= right) {
        mid = (left + right) / 2;

        sum = 0;

        for (int i = 0; i < N; i++)
            sum += mid / test[i];

        if (sum < M) {
            left = mid + 1;
        }
        else {
            ans = mid;
            right = mid - 1;
        }
    }

    cout << ans;

    return 0;

}
