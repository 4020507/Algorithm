#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define INF 1e9

using namespace std;

int v, e;
int indegree[100001];
vector<int> graph[100001];

void topology()
{
    vector<int> result;
    queue<int> q;

    for (int i = 1;i <= v;i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        result.push_back(curr);

        for (int i = 0;i < graph[curr].size();i++)
        {
            int node = graph[curr][i];
            indegree[node]--;

            if (indegree[node] == 0)
            {
                q.push(node);
            }
        }
    }

    for (int i = 0;i < result.size();i++)
        cout << result[i] << endl;
}
int main(void) {
    
    cin >> v >> e;
    memset(indegree, 0, sizeof(indegree));

    for (int i = 0;i < e;i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    topology();
    
    return 0;
    
}
