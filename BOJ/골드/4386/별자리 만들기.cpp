#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

vector<pair<double, double>> stars;
vector < pair<double,pair<int, int>>> dist;
int n;
int parent[100];

int findParent(int p) {
    if (p == parent[p]) {
        return p;
    }

    return parent[p] = findParent(parent[p]);
}

void Union(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if (a < b) {
        parent[b] = a;
    }
    else {
        parent[a] = b;
    }
}

double distance(double x1, double y1, double x2, double y2) {

    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    double x, y;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        stars.push_back({ x,y });
    }

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    double diff;

    for (int i = 0; i < n; i++) {

        x = stars[i].first;
        y = stars[i].second;

        for (int j = i + 1; j < n; j++) {

            diff = distance(x, y, stars[j].first, stars[j].second);

            dist.push_back({ diff,{i,j} });
        }
    }

    sort(dist.begin(), dist.end());

    double ans = 0;
    int index1, index2;

    for (auto d : dist) {
        diff = d.first;
        index1 = d.second.first;
        index2 = d.second.second;

        if (findParent(index1) != findParent(index2)) {
            Union(index1, index2);
            ans += diff;
        }
    }

    cout << fixed;
    cout.precision(2);

    cout << ans;

    return 0;
}
