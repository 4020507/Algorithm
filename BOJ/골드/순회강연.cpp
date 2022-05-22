#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

pair<int, int> request[10001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    int i;

    for (i = 0; i < n; i++) {
        cin >> request[i].second >> request[i].first;
    }

    int earns = 0;

    sort(request, request + n);

    priority_queue<int> pq;
    for (i = 0; i < n; i++) {
        pq.push(-request[i].second);
        earns += request[i].second;
        if (pq.size() > request[i].first) {
            earns += pq.top();
            pq.pop();
        }
    }

    cout << earns;

    return 0;

}
