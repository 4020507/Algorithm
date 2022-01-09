#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

#define MAX 2147483648

int main(void)
{
    std::ios::sync_with_stdio(false);

    int K, N;
    cin >> K >> N;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    vector<long long> v;
    map<long long, bool> m;
    long long num;

    for (int i = 0;i < K;i++)
    {
        cin >> num;
        v.push_back(num);
    }

    long long multi;
    long long maxi = 0;
    pq.push(1);
    for (int i = 0;i < N;i++)
    {
        num = pq.top();
        pq.pop();

        for (auto n : v)
        {
            multi = n * num;

            if (pq.size() > N && multi > maxi)
            {
                continue;
            }
            if (!m[multi])
            {
                pq.push(multi);
                m[multi] = true;
                if (maxi < multi)
                    maxi = multi;
            }
            
        }
    }

    cout << pq.top();
    return 0;

}
