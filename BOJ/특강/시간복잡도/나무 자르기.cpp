#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[1000000];
int ans;
int main() {
    cin >> N >> M;
    int sum = 0;
    for (int i = 0;i < N;i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr + N);
    int mid = sum / N;
    unsigned long long cnt;
    int ans = 0;
    int left = 0;
    int right = arr[N - 1];
    while (left <= right)
    {
        mid = (left + right) / 2;
        cnt = 0;

        for (int i = N-1;i >= 0;i--)
        {
            if (arr[i] - mid > 0)
                cnt += arr[i] - mid;
            else
                break;
        }

        if (cnt >= M)
        {
            ans = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    cout << ans;

    return 0;
}
