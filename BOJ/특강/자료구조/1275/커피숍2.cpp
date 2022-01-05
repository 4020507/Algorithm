#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
long long arr[100000];

long long init(vector<long long>& tree, int node, int start, int end)
{
    if (start == end)
        return tree[node] = arr[start];

    return tree[node] = init(tree, node * 2, start, (start + end) / 2) + init(tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

long long sum(vector<long long>& tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && right >= end)
        return tree[node];

    return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector<long long>& tree, int node, int start, int end, int index, long long diff)
{
    if (start > index || end < index)
        return;

    tree[node] += diff;

    if (start != end)
    {
        update(tree, node * 2, start, (start + end) / 2, index, diff);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    int height = ceil(log2(N)) + 1;
    height = (1 << height);

    vector<long long> tree(height);

    for (int i = 0;i < N;i++)
        cin >> arr[i];
    int x, y, a, b;

    init(tree, 1, 0, N - 1);

    for (int i = 0;i < Q;i++)
    {
        cin >> x >> y >> a >> b;

        if (x > y)
        {
            swap(x, y);
        }
        cout << sum(tree, 1, 0, N - 1, x - 1, y - 1) << '\n';
        long long diff = b - arr[a - 1];
        arr[a - 1] = b;
        update(tree, 1, 0, N - 1, a - 1, diff);
    }
    return 0;

}

