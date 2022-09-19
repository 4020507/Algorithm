#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;

int V;
vector<pair<int, int>> tree[100001];
bool visited[100001];
int maxDist;
int maxNode;
void dfs(int curr, int dist) {

    if (dist > maxDist) {
        maxDist = dist;
        maxNode = curr;
    }

    for (auto t : tree[curr]) {

        if (!visited[t.first]) {
            visited[t.first] = true;
            dfs(t.first, dist + t.second);
        }
    }
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    
    cin >> V;

    int mainTree;
    int connectedTree;
    int dist;

    for (int i = 0; i < V; i++) {
        cin >> mainTree;

        while (1) {
            cin >> connectedTree;

            if (connectedTree == -1) {
                break;
            }

            cin >> dist;

            tree[mainTree].push_back({ connectedTree,dist });
            tree[connectedTree].push_back({ mainTree,dist });
        }
    }

    maxDist = 0;

    memset(visited, false, sizeof(visited));
    visited[1] = true;
    dfs(1, maxDist);

    memset(visited, false, sizeof(visited));
    visited[maxNode] = true;
    dfs(maxNode, 0);

    cout << maxDist;

    return 0;
}
