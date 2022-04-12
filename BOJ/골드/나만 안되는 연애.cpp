#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 1001

int parent[MAX];
int N, M;
vector<pair<int,pair<int,int>>> route;

int manOrWoman[MAX];

int findParent(int p) {
    if (parent[p] == p)
        return p;

    return parent[p] = findParent(parent[p]);
}

void Union(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if (a < b) {
        parent[b] = a;
    }
    else
        parent[a] = b;
}
int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 1;i <= N;i++)
        parent[i] = i;

    char sex;

    for (int i = 1;i <= N;i++) {
        cin >> sex;

        if (sex == 'M')
            manOrWoman[i] = 1;
        else
            manOrWoman[i] = 2;
    }

    int start, end, cost;
    for (int i = 0;i < M;i++) {
        cin >> start >> end >> cost;
        route.push_back({ cost,{start,end} });
    }
    sort(route.begin(), route.end());

    int p1, p2;
    int total = 0;
    int connected = 0;

    for (int i = 0;i < M;i++) {
        start = route[i].second.first;
        end = route[i].second.second;
        cost = route[i].first;

        if (manOrWoman[start] != manOrWoman[end]) {
            p1 = findParent(start);
            p2 = findParent(end);

            if (p1 != p2) {
                Union(p1, p2);
                total += cost;
                connected++;
            }
        }
    }

    if (connected == N - 1)
        cout << total;
    else
        cout << -1;

    return 0;

}
