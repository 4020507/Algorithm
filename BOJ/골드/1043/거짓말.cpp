#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int parent[51];
int truth[51];
int N, M, T;
vector<int> lines[51];

int findParent(int p) {
    if (parent[p] == p)
        return p;
    else
        return parent[p] = findParent(parent[p]);
}

void Union(int p1, int p2) {

    p1 = findParent(p1);
    p2 = findParent(p2);

    if (p1 != p2) {
        if (p1 < p2) {
            parent[p2] = p1;
        }
        else {
            parent[p1] = p2;
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> truth[i];
    }

    int line;
    int j;
    int num;
    int first;

    for (int i = 0; i < M; i++) {
        cin >> line;

        for (j = 0; j < line; j++) {
            cin >> num;
            lines[i].push_back(num);
            if (j == 0) {
                first = num;
            }
            else {
                Union(first, num);
            }
        }
    }

    bool check;
    int ans = 0;
    int p1, p2;

    for (int i = 0; i < M; i++) {
        check = true;

        for (auto L : lines[i]) {
            for (j = 0; j < T; j++) {
                p1 = findParent(truth[j]);
                p2 = findParent(L);

                if (p1 == p2) {
                    check = false;
                    break;
                }
            }

            if (!check)
                break;
        }

        if (check) {
            ans++;
        }
    }

    cout << ans;

    return 0;

}
