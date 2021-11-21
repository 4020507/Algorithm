#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
int N, M;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;

int ans;

void calc(vector<int> order)
{
    int shortest;
    vector<pair<int, int>> v;
    for (int i = 0;i < order.size();i++)
    {
        if (order[i] == 0)
            continue;
        shortest = 1e9;
        for (int j = 0;j < home.size();j++)
        {
            v.push_back({ j,abs(chicken[i].first - home[j].first) + abs(chicken[i].second - home[j].second) });
        }
    }
    int sum = 0;
    int idx = -1;
    sort(v.begin(), v.end());

    for (auto a : v)
    {
        if (idx != a.first)
        {
            idx = a.first;
            sum += a.second;
        }
    }
    ans = min(ans, sum);
}
int main(void)
{
    cin >> N >> M;
    int a;

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
        {
            cin >> a;

            if (a == 1)
            {
                home.push_back({ i,j });
            }
            else if (a == 2)
            {
                chicken.push_back({ i,j });
            }
        }
    }

    vector<int> order;

    for (int i = M;i < chicken.size();i++)
        order.push_back(0);
    for (int i = 0;i < M;i++)
        order.push_back(1);
    
    ans = 1e9;

    do
    {
        calc(order);
    } while (next_permutation(order.begin(), order.end()));

    cout << ans;
    return 0;
    
}
