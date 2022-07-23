#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;

int arr[100001];
vector<int> maxTree;
vector<int> minTree;

void init(int start, int end, int node) {
    if (start == end) {
        maxTree[node] = arr[start];
        minTree[node] = arr[start];

        return;
    }

    int mid = (start + end) / 2;

    init(start, mid, node * 2);
    init(mid + 1, end, node * 2 + 1);

    maxTree[node] = max(maxTree[node * 2], maxTree[node * 2 + 1]);
    minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);

}

pair<int,int> query(int start, int end, int left, int right, int node) {
    
    if (start > right || end < left)
        return {1e9, 0};

    if (left <= start && end <= right) {
        return { minTree[node],maxTree[node] };
    }

    int mid = (start + end) / 2;

    pair<int, int> p1 = query(start, mid, left, right, node * 2);
    pair<int, int> p2 = query(mid + 1, end, left, right, node * 2 + 1);

    return { min(p1.first,p2.first),max(p1.second,p2.second) };
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int size = ceil(log2(N)) + 1;
    size = (1 << size);

    minTree.resize(size);
    maxTree.resize(size);

    init(0, N - 1, 1);


    int a, b;
    pair<int, int>ans;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;

        ans = query(0, N - 1, a - 1, b - 1, 1);

        cout << ans.first << ' ' << ans.second << '\n';
    }
    return 0;

}2357
