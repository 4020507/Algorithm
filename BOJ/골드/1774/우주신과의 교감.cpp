#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<math.h>
#define INF 1000000000
using namespace std;

vector<pair<double, pair<int,int>>> dist;
pair<double, double>coordinates[1001];
int N, M;
int parent[1001];

int findParent(int p) {
    if (parent[p] == p)
        return p;

    return parent[p] = findParent(parent[p]);
}

void Union(int p1, int p2) {
    p1 = findParent(p1);
    p2 = findParent(p2);

    if (p1 < p2) {
        parent[p2] = p1;
    }
    else {
        parent[p1] = p2;
    }
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> coordinates[i].first >> coordinates[i].second;
        parent[i] = i;
    }

    int a, b;
    double ans = 0;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;

        Union(a, b);
    }

    double calc = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {

                dist.push_back({ sqrt((coordinates[i].first - coordinates[j].first) * (coordinates[i].first - coordinates[j].first) + 
                    (coordinates[i].second - coordinates[j].second) * (coordinates[i].second - coordinates[j].second)),
                    {i,j} });
            
        }
    }

    sort(dist.begin(), dist.end());

    for (auto d : dist) {
        if (findParent(d.second.first) != findParent(d.second.second)) {
            Union(d.second.first, d.second.second);
            calc += d.first;
        }
    }

    cout<<fixed;
    cout.precision(2);
    cout << calc;

    return 0;
}
