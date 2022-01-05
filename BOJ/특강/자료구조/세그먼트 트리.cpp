#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int a[1000001];
long long init(vector<long long>& tree, int node, int start, int end)
{
    if (start == end)
    {
        return tree[node] = a[start];
    }

    return tree[node] = init( tree, node * 2, start, (start + end) / 2) + init(tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

//node가 start~end 구간을 담당하고 있고, left~right 구간을 찾고 싶다
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
    if (index < start || index > end)
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
    int N, M, K;
    cin >> N >> M >> K;
    int size = ceil(log2(N)) + 1;
    size = (1 << size);
    vector<long long> tree(size);
    long long num;
    for (int i = 0;i < N;i++)
    {
        cin >> a[i];
    }

    init(tree, 1, 0, N - 1);

    long long order, b, c;

    for (int i = 0;i < M + K;i++)
    {
        cin >> order >> b >> c;

        //order가 1경우 b번째 값이 c로 변경
        if (order == 1)
        {
            long long diff = c - a[b - 1];
            a[b - 1] = c;
            update(tree, 1, 0, N - 1, b - 1, diff);
        }
        else//b~c구간의 합 구하기
            cout << sum(tree, 1, 0, N - 1, b - 1, c - 1) <<'\n';
    }
    return 0;

}

