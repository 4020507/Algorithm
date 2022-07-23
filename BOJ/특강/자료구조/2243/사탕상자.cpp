#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;

int MAX = 1000001;
long long result;
void update(vector<long long>& tree, int node, int start, int end, int idx, long long diff)
{
    if (end < idx || idx < start)
        return;

    tree[node] += diff;

    if (start != end)
    {
        update(tree, node * 2, start, (start + end) / 2, idx, diff);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
    }
    
}

long long findNum(vector<long long>& tree, int node, int start, int end, int out)
{
    if (start == end && !result)
    {
        cout << start << '\n';
        return start;
    }

    if (result == 0 && out <= tree[node * 2])
    {
        return result = findNum(tree, node * 2, start, (start + end) / 2, out);
    }

    out -= tree[node * 2];
    if(result == 0 && tree[node*2+1] >= out){
        return result = findNum(tree, node * 2 + 1, (start + end) / 2 + 1, end, out);
    }
}
int main(void)
{
    ios_base::sync_with_stdio(0);

    cin.tie(0);
    int N;
    cin >> N;

    int height = ceil(log2(MAX)) + 1;
    height = 1 << height;

    vector<long long> tree(height);

    int a, b, c;
    for (int i = 0;i < N;i++)
    {
        cin >> a;

        if (a == 1)
        {
            cin >> b;
            int index = findNum(tree, 1, 0, MAX- 1, b);
            result = 0;
            update(tree, 1, 0, MAX - 1, index,-1);
        }
        else
        {
            cin >> b >> c;
            update(tree, 1, 0, MAX - 1, b, c);
        }

    }
    return 0;

}
