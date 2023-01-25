#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {

    if (a.second != b.second) {
        return a.second < b.second;
    }

    return a.first < b.first;
}
int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M, T;
    bool books[1001];
    vector<pair<int, int>> page;
    int i, j, a, b;
    int students;

    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N >> M;

        for (i = 1; i <= N; i++) {
            books[i] = false;
        }

        page.clear();
        students = 0;

        for (i = 0; i < M; i++) {
            cin >> a >> b;

            page.push_back({ a,b });
        }

        sort(page.begin(), page.end(), cmp);

        for (i = 0; i < page.size(); i++) {
            for (j = page[i].first; j <= page[i].second; j++) {
                if (!books[j]) {
                    books[j] = true;
                    students++;
                    break;
                }
            }
        }

        cout << students << '\n';
    }


    return 0;
}
