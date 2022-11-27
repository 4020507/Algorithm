#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<deque>
#include<string.h>
using namespace std;

int visited[100001];

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;

    cin >> N >> K;

    visited[N] = 1;
    deque<int> dq;
    dq.push_back(N);
    int x;
    while (!dq.empty()) {

        x = dq.front();
        dq.pop_front();

        if (x == K) {
            cout << visited[x] - 1;
            return 0;
        }

        if (x * 2 <= 100000 && !visited[x*2]) {
            visited[x * 2] = visited[x];
            dq.push_front(x * 2);
        }

        if (x + 1 <= 100000 && !visited[x + 1]) {
            visited[x + 1] = visited[x] + 1;
            dq.push_back(x + 1);
        }

        if (x - 1 >= 0 && !visited[x - 1]) {
            visited[x - 1] = visited[x] + 1;
            dq.push_back(x - 1);
        }
    }

    return 0;
}
