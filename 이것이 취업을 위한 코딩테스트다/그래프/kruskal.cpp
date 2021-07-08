#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<algorithm>
#define INF 1e9

using namespace std;

int v, e;
vector<pair<int,pair<int,int>>> graph;
int parent[10001];
int result = 0;

int findParent(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b)
{
    if (parent[a] == parent[b])
        return;
    int first = parent[a];
    int second = parent[b];

    parent[a] = first > second ? first : second;
    parent[b] = parent[a];

    return;
}
int main(void) {
    
    cin >> v >> e;

    for (int i = 1;i <= v;i++)
        parent[i] = i;
    for (int i = 0;i < e;i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        graph.push_back({ c,{a,b} });
       
    }

    sort(graph.begin(), graph.end());
    int total = 0;
    for (int i = 0;i < graph.size();i++)
    {
        int cost = graph[i].first;
        int start = graph[i].second.first;
        int arrive = graph[i].second.second;

        if (findParent(start) != findParent(arrive))
        {
            unionParent(start, arrive);
            total += cost;
        }
    }

    cout << total << endl;
    return 0;
    
}
