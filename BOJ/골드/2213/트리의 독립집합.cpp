#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int dp[10001][2];
vector<int>tree[10001];
int N;
int cost[10001];
vector<int> path;
bool visited[10001];

void getAns(int curr) {

    visited[curr] = true;

    dp[curr][0] = 0;
    dp[curr][1] = cost[curr];

    for (auto t : tree[curr]) {

        if (!visited[t]) {
            getAns(t);

            dp[curr][1] += dp[t][0];
            dp[curr][0] += max(dp[t][0], dp[t][1]);
        }
    }
}

void findPath(int curr, int prev) {
    if (dp[curr][1] > dp[curr][0] && !visited[prev]) {
        path.push_back(curr);
        visited[curr] = true;
    }

    for (auto t : tree[curr]) {

        if (t != prev) {
            findPath(t, curr);
        }
    }
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    int a, b;
    
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
    }

    for (int i = 1; i < N; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    memset(dp, -1, sizeof(dp));
    memset(visited, false, sizeof(visited));
    getAns(1);
    memset(visited, false, sizeof(visited));
    findPath(1, 0);
    cout << max(dp[1][0], dp[1][1]) << '\n';

    sort(path.begin(), path.end());

    for (auto p : path) {
        cout << p << ' ';
    }
    return 0;
}
