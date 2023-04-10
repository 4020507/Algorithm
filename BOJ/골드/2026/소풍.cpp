#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

bool friends[901][901];
int friendCnt[901];
bool checked[901];
int K, N;
bool found;

bool alsoFriend(int f) {
    for (int i = 1; i <= N; i++) {
        if (checked[i] && !friends[i][f]) {
            return false;
        }
    }

    return true;
}
void dfs(int cur, int cnt) {

    if (found) {
        return;
    }

    if (cnt == K) {
        found = true;

        for (int i = 1; i <= N; i++) {
            if (checked[i]) {
                cout << i << '\n';
            }
        }
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!friends[i][cur]) {
            continue;
        }
        if (!alsoFriend(i)) {
            continue;
        }
        checked[i] = true;
        dfs(i, cnt + 1);
        checked[i] = false;
    }
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int F;

    cin >> K >> N >> F;

    memset(friends, false, sizeof(friends));

    int a, b;

    for (int i = 1; i <= N; i++) {
        friendCnt[i] = 1;
        checked[i] = false;
    }
    for (int i = 0; i < F; i++) {
        cin >> a >> b;

        friends[a][b] = friends[b][a] = true;
        friendCnt[a]++;
        friendCnt[b]++;
    }

    found = false;
    for (int i = 1; i <= N; i++) {

        if (found) {
            break;
        }

        if (friendCnt[i] < K) {
            continue;
        }

        checked[i] = true;
        dfs(i, 1);
        checked[i] = false;
    }

    if (!found) {
        cout << -1;
    }
    return 0;
}
