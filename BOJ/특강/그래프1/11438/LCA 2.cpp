#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 100001

vector<int> graph[MAX+1];
int depth[MAX + 1];
int ancestor[MAX + 1][20];
int max_level;

void setTree(int curr, int parent)
{
    depth[curr] = depth[parent] + 1;
    ancestor[curr][0] = parent;

    max_level = (int) floor(log2(MAX));
    int p;
    for (int i = 1;i <= max_level;i++)
    {
        p = ancestor[curr][i - 1];
        ancestor[curr][i] = ancestor[p][i - 1];
    }

    for (int i = 0;i < graph[curr].size();i++)
    {
        if (graph[curr][i] != parent)
            setTree(graph[curr][i], curr);
    }
}
int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N;

    int a, b;
    for (int i = 0;i < N - 1;i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    depth[0] = -1;

    setTree(1, 0);

    cin >> M;

    int lca;
    for (int i = 0;i < M;i++)
    {
        cin >> a >> b;

        if (depth[a] != depth[b])
        {
            if (depth[a] > depth[b])
                swap(a, b);

            for (int i = max_level;i >= 0;i--)
            {
                if (depth[a] <= depth[ancestor[b][i]])
                    b = ancestor[b][i];
            }
        }
        lca = a;

        if (a != b)
        {
            for (int i = max_level;i >= 0;i--)
            {
                if (ancestor[a][i] != ancestor[b][i])
                {
                    a = ancestor[a][i];
                    b = ancestor[b][i];
                }
                lca = ancestor[a][i];
            }
        }

        cout << lca << '\n';
    }
    return 0;

}
