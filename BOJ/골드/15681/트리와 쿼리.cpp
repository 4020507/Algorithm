#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
#include<vector>
using namespace std;


int dp[100001];
bool visited[100001];
vector<int>tree[100001];
int N, R, Q;

int dfs(int curr) {
    visited[curr] = true;

    int& res = dp[curr];

    if (res != 0)
        return res;

    int next;
    res = 1;

    for (int i = 0; i < tree[curr].size(); i++) {
        next = tree[curr][i];

        if (!visited[next]) {
            res += dfs(next);
        }
    }

    return res;
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> R >> Q;

    int a, b;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    memset(dp, 0, sizeof(dp));

    dfs(R);

    for (int i = 0; i < Q; i++) {
        cin >> a;

        cout << dp[a] << '\n';
    }

    return 0;
}
