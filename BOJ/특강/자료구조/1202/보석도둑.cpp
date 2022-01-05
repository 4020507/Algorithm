#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(void)
{
    pair<int, int> jewel[300001];
    int bag[300001];
    
    int N, K;

    cin >> N >> K;

    for (int i = 0;i < N;i++)
    {
        cin >> jewel[i].first >> jewel[i].second;
    }

    for (int j = 0;j < K;j++)
    {
        cin >> bag[j];
    }

    sort(jewel, jewel + N);
    sort(bag, bag + K);

    priority_queue<int> pq;
    int idx = 0;
    long long result = 0;
    for (int i = 0;i < K;i++)
    {
        while (idx < N && jewel[idx].first <= bag[i])
            pq.push(jewel[idx++].second);

        if (!pq.empty())
        {
            result += pq.top();
            pq.pop();
        }
    }

    cout << result;

    return 0;

}

