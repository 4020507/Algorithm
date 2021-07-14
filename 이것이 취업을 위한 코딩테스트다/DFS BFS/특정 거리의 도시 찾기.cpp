#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

vector<int> city[300001];
bool visited[300001];

int main(void) {
    
    int N, M, K, X;

    cin >> N >> M >> K >> X;

    

    for (int i = 0;i < M;i++)
    {
        int a, b;
        cin >> a >> b;

        city[a].push_back(b);
    }

    queue<pair<int, int>> q;

    q.push(make_pair(X, 0));
    memset(visited, false, sizeof(visited));
    visited[X] = true;

    vector<int> ans;
    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;

        q.pop();

        if (b > K)
            break;
        if (b == K)
        {
            ans.push_back(a);
            continue;
        }

        for (int i = 0;i < city[a].size();i++)
        {
            int next = city[a][i];

            if (!visited[next])
            {
                visited[next] = true;
                q.push(make_pair(next, b + 1));
            }
        }
    }

    if (ans.size() == 0)
        cout << -1 << endl;
    else
    {
        for (int i = 0;i < ans.size();i++)
        {
            cout << ans[i] << endl;
        }
    }
    return 0;
    
}
