#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;


int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);    

    int N, i, a, b;

    cin >> N;

    vector<pair<int, int>> station;

    for (i = 0; i < N; i++) {
        cin >> a >> b;

        station.push_back({ a,b });
    }

    cin >> a >> b;

    station.push_back({ a,0 });
    sort(station.begin(), station.end());

    priority_queue<int> pq;
    int ans = 0;

    for (i = 0; i <= N; i++) {

        while (!pq.empty() && b < station[i].first) {
            b += pq.top();
            pq.pop();
            ans++;
        }

        if (b < station[i].first) {
            ans = -1;
            break;
        }

        pq.push(station[i].second);
    }

    cout << ans;

    return 0;
}
