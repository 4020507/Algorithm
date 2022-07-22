#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

int N, M;
bool visited[100001];
vector<pair<int, int>> v[100001];
int ans = 0;
int A, B, C;

bool bfs(int limit) {

    queue<int> q;
    memset(visited, false, sizeof(visited));

    q.push(A);
    visited[A] = true;

    int curr, i, next, w;

    while (!q.empty()) {
        curr = q.front();

        q.pop();

        if (curr == B) 
            return true;
        
        for (i = 0; i < v[curr].size(); i++) {
            next = v[curr][i].first;
            w = v[curr][i].second;

            if (!visited[next] && limit <= w) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    return false;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N >> M;

    int maxCost = 0;

    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;

        v[A].push_back({ B,C });
        v[B].push_back({ A,C });
        maxCost = max(C, maxCost);
    }

    cin >> A >> B;
    

    int low = 0;
    int high = maxCost;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;

        if (bfs(mid)) {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    cout << ans;


    return 0;

}
