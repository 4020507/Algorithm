#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

int bigger[1000];
int smaller[1000];
int arr[1000];

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, i, j;

    cin >> N;

    for (i = 0; i < N; i++) {
        bigger[i] = 1;
        smaller[i] = 1;

        cin >> arr[i];
    }

    for (i = 1; i < N; i++) {
        for (j = i - 1; j >= 0; j--) {
            if (arr[i] > arr[j]) {
                if (bigger[i] < bigger[j] + 1) {
                    bigger[i] = bigger[j] + 1;
                }
            }
        }
    }

    for (i = N - 2; i >= 0; i--) {
        for (j = i + 1; j < N; j++) {
            if (arr[i] > arr[j]) {
                if (smaller[i] < smaller[j] + 1) {
                    smaller[i] = smaller[j] + 1;
                }
            }
        }
    }

    int ans = 0;

    for (i = 0; i < N; i++) {
        ans = max(ans, smaller[i] + bigger[i] - 1);
    }

    cout << ans;

    return 0;
}
