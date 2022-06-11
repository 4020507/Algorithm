#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

unsigned long long maxDistance;
vector<pair<int,int>> v[100001];
bool visited[10001];

void dfs(int curr, unsigned long long sum) {
    visited[curr] = true;
    maxDistance = maxDistance < sum ? sum : maxDistance;

    for (auto a : v[curr]) {
        if (!visited[a.first]) {
            dfs(a.first, sum + a.second);
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int a, b, c;
    int lastCity = 0;
    while (cin >> a >> b >> c) {
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });

        lastCity = lastCity < a ? a : lastCity;
        lastCity = lastCity < b ? b : lastCity;
    }
    maxDistance = 0;

    for (int i = 1; i <= lastCity; i++) {
        memset(visited, false, sizeof(visited));
        dfs(i, 0);
    }

    cout << maxDistance;

    return 0;

}
