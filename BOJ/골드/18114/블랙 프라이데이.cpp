#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int N, C;
int num[5000];
bool checked[100000001];

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(checked, false, sizeof(checked));

    cin >> N >> C;

    int i, j;

    for (i = 0; i < N; i++) {
        cin >> num[i];
        checked[num[i]] = true;
    }

    sort(num, num + N);
    int sum;

    for (i = 0; i < N; i++) {

        if (num[i] == C) {
            cout << 1;
            return 0;
        }

        for (j = i + 1; j < N; j++) {
            sum = num[i] + num[j];

            if (sum == C) {
                cout << 1;
                return 0;
            }

            if (sum < C) {

                if (checked[C - sum] && (C - sum) != num[i] && (C-sum) != num[j]){
                    cout << 1;
                    return 0;
                }
            }
        }
    }

    cout << 0;

    return 0;
}
