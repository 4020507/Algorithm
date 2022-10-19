#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
using namespace std;


int N;
vector<int> parts[1000001];
int parent[1000001];
int partsCnt[1000001];

int findParent(int p) {
    if (parent[p] == p) {
        return p;
    }

    return parent[p] = findParent(parent[p]);
}

void Union(int p1, int p2) {

    p1 = findParent(p1);
    p2 = findParent(p2);

    if (p1 > p2) {
        partsCnt[p2] += partsCnt[p1];
        parent[p1] = p2;
    }
    else {
        partsCnt[p1] += partsCnt[p2];
        parent[p2] = p1;
    }
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;

    cin >> N;

    char order;
    int a, b, i;

    for (i = 1; i <= 1000000; i++) {
        parent[i] = i;
        partsCnt[i] = 1;
    }

    for (int i = 0; i < N; i++) {
        cin >> order;

        if (order == 'I') {
            cin >> a >> b;

            a = findParent(a);
            b = findParent(b);

            if (a != b) {
                Union(a, b);
            }
        }
        else {
            cin >> a;

            cout << partsCnt[findParent(a)] << '\n';
        }
    }
    return 0;
}
