#include<iostream>
#include<string.h>
#define INF 1000000000
using namespace std;

int G;
int P;

int parent[100001];

int findParent(int p) {
    if (parent[p] == p)
        return p;

    return parent[p] = findParent(parent[p]);
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> G >> P;

    int i;
    int plane;

    for (i = 1; i <= G; i++) {
        parent[i] = i;
    }

    int ans = 0;
    for (i = 0; i < P; i++) {
        cin >> plane;

        if (!findParent(plane)) {
            break;
        }

        parent[findParent(plane)] = findParent(findParent(plane) - 1);
        ans++;
    }

    cout << ans;


    return 0;
}
