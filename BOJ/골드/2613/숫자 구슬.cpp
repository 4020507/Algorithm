#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
int marble[300];

bool check(int mid) {
    int cnt = 0;

    int i;
    int sum = 0;

    for (i = 0; i < N; i++) {
        sum += marble[i];

        if (sum > mid) {
            cnt++;
            sum = marble[i];
        }
    }

    cnt++;

    if (cnt > M) {
        return false;
    }

    return true;
}

void printAns(int mid) {
    int i;
    int sum = 0;
    int cnt = 0;

    cout << mid << '\n';

    for (i = 0; i < N; i++) {
        sum += marble[i];
        cnt++;

        if (sum > mid) {
            cout << cnt - 1 << ' ';
            cnt = 1;
            sum = marble[i];
            M--;
        }

        if (N - i == M) {
            break;
        }
    }

    for (i = M; i > 0; i--) {
        cout << cnt << ' ';
        cnt = 1;
    }
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    
    int i;
    int left, right, mid;

    cin >> N >> M;

    left = 0;
    right = 0;
    for (i = 0; i < N; i++) {
        cin >> marble[i];

        left = max(left, marble[i]);
        right += marble[i];
    }

    while (left <= right) {
        mid = (left + right) / 2;

        if (check(mid)) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    printAns(left);

    return 0;
}
