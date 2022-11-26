#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
using namespace std;

long long arr[5000];

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, i, j, k;
    long long sum;

    cin >> N;

    for (i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    long long temp = 3000000001;
    long long ans[3];

    for (i = 0; i < N - 2; i++) {
        j = i + 1;
        k = N - 1;

        while (j < k) {
            sum = arr[i] + arr[j] + arr[k];

            if (abs(sum) < temp) {
                temp = abs(sum);
                ans[0] = arr[i];
                ans[1] = arr[j];
                ans[2] = arr[k];
            }

            if (sum > 0) {
                k--;
            }
            else {
                j++;
            }
        }
    }

    cout << ans[0] << ' ' << ans[1] << ' '<< ans[2];

    return 0;
}
