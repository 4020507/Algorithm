#include <iostream>
#include <map>
#include <queue>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int board[101];
    map<int, int>m;
    int N, M, i;

    cin >> N >> M;

    int a, b;

    for (i = 0; i < N + M; i++) {
        cin >> a >> b;

        m[a] = b;
    }

    for (i = 2; i <= 100; i++) {
        board[i] = 1e9;
    }

    board[1] = 0;
    queue<pair<int, int>> q;
    q.push({ 1,0 });

    int num, cnt;
    int roll;

    while (!q.empty()) {
        num = q.front().first;
        cnt = q.front().second;

        q.pop();

        if (num == 100) {
            cout << cnt;
            break;
        }

        for (i = 1; i <= 6; i++) {
            roll = num + i;

            if (roll > 100) {
                break;
            }

            if (m[roll] != 0) {
                roll = m[roll];
            }

            if (board[roll] > cnt + 1) {
                board[roll] = cnt + 1;
                q.push({ roll,cnt + 1 });
            }
        }
    }

    return 0;
}
