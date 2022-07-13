#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int N;
vector<pair<int,int>> node[10001];
bool visited[10001];
int ans;
int endPoint;

void calcLength(int curr, int len) {
    visited[curr] = true;

    if (ans < len) {
        ans = len;
        endPoint = curr;
    }

    for (auto n : node[curr]) {
        if (!visited[n.first]) {
            calcLength(n.first, len + n.second);
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N;

    int a, b, c;

    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> c;

        node[a].push_back({ b,c });
        node[b].push_back({ a,c });
    }

    memset(visited, false, sizeof(visited));

    ans = 0;
    calcLength(1, 0);

    memset(visited, false, sizeof(visited));
    calcLength(endPoint, 0);

    cout << ans;
    
    return 0;

}
