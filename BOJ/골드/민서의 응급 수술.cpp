#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int parent[100001];
int N, M;

int findParent(int p) {
    if (parent[p] == p)
        return p;
    return parent[p] = findParent(parent[p]);
}
void Union(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N >> M;

    for (int i = 1;i <= N;i++)
        parent[i] = i;
    int u, v;
    int p1, p2;
    int cnt = 0;
    for (int i = 0;i < M;i++) {
        cin >> u >> v;

        p1 = findParent(u);
        p2 = findParent(v);

        if (p1 != p2)
            Union(p1, p2);
        else
            cnt++;
    }

    
    for (int i = 2;i <= N;i++) {
        p2 = findParent(i);

        if (1 != p2) {
            Union(1, i);
            cnt++;
        }
    }

    cout << cnt;

    return 0;

}
