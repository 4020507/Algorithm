#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int N;
vector<int> problems[32001];
int degree[32001];


int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int M;

    cin >> N >> M;

    int a, b, i;

    for (i = 0; i < M; i++) {
        cin >> a >> b;

        degree[b]++;
        problems[a].push_back(b);
    }

    for (i = 1; i <= N; i++) {
        sort(problems[i].begin(), problems[i].end());
    }

    priority_queue<int>pq;

    for (i = 1; i <= N; i++) {

        if (degree[i] == 0) {
            pq.push(-i);
        }
    }

    int p;

    while (!pq.empty()) {
        p = -pq.top();
        pq.pop();

        cout << p << ' ';

        for (i = 0; i < problems[p].size(); i++) {
            degree[problems[p][i]]--;

            if (degree[problems[p][i]] == 0) {
                pq.push(-problems[p][i]);
            }
        }
    }
    return 0;
}
