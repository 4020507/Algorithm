#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000

int parent[MAX + 1];

int findParent(int a)
{
    if (parent[a] == a)
        return a;
    return parent[a] = findParent(parent[a]);
}

void Union(int a, int b)
{
    a = findParent(a);
    b = findParent(b);

    if (a > b)
        parent[b] = a;
    else
        parent[a] = b;
}
int main(void)
{
    std::ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    
    for (int i = 1;i <= N;i++)
        parent[i] = i;

    int a, b, cost;
    vector<pair<int, pair<int, int>>> computers;
    for (int i = 0;i < M;i++)
    {
        cin >> a >> b >> cost;

        computers.push_back({ cost,{a,b} });
    }

    sort(computers.begin(), computers.end());

    int total = 0;

    for (int i = 0;i < M;i++)
    {
        cost = computers[i].first;
        a = computers[i].second.first;
        b = computers[i].second.second;

        if (findParent(a) != findParent(b))
        {
            total += cost;
            Union(a, b);
        }
    }

    cout << total;

    return 0;

}
