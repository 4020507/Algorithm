#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int indegree[1001];
vector<int> singers[1001];

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;

    cin >> N >> M;

    int i, j, cnt;
    int a, b;

    for (i = 0; i < M; i++) {
        cin >> cnt;

        if (cnt == 0) {
            continue;
        }

        cin >> a;
        if (cnt == 1) {
            continue;
        }

        for (j = 1; j < cnt; j++) {
            cin >> b;

            singers[a].push_back(b);
            indegree[b]++;
            a = b;
        }
    }

    queue<int> q;

    for (i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;

    while (!q.empty()) {
        a = q.front();
        q.pop();

        ans.push_back(a);

        for (i = 0; i < singers[a].size(); i++) {
            indegree[singers[a][i]]--;

            if (indegree[singers[a][i]] == 0) {
                q.push(singers[a][i]);
            }
        }
    }

    if (ans.size() == N) {
        for (i = 0; i < ans.size(); i++) {
            cout << ans[i] << '\n';
        }
    }
    else {
        cout << 0;
;    }

    return 0;
}
