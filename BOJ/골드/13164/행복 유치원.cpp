#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
using namespace std;

int arr[300000];
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    
    
    cin >> N >> K;

    int i;

    for (i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int ans = arr[N - 1] - arr[0];

    for (i = N - 1; i > 0; i--) {
        arr[i] = arr[i] - arr[i - 1];
    }
    
    arr[0] = 0;
    sort(arr, arr + N);

    for (i = N - 1; i > 0 && K > 1; i--, K--) {
        ans -= arr[i];
    }

    cout << ans;


    return 0;
}
