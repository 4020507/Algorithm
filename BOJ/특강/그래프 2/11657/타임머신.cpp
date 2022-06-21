#pragma warning(disable:4996)
#include <iostream>
#include <vector>
using namespace std;

#define MAX 501
#define INF 1e9

int N, M;
vector<pair<int, int>> city[MAX];
long long dist[MAX];

void BellmanFord(int start)
{
    dist[start] = 0;
    int end, cost;

    bool cycle = false;
    for (int i = 1;i <= N;i++)
    {
        for (int j = 1;j <= N;j++)
        {
            for (auto c : city[j])
            {
                end = c.first;
                cost = c.second;

                if (dist[j] != INF &&
                    dist[j] + cost < dist[end]
                    )
                {
                    dist[end] = dist[j] + cost;

                    if (i == N)
                    {
                        cycle = true;
                    }
                }
            }
        }
    }

    if (cycle)
    {
        cout << -1;
        return;
    }

    for (int i = 2;i <= N;i++)
    {
        if (dist[i] == INF)
            cout << "-1" << '\n';
        else
            cout << dist[i] << '\n';
    }
}
int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 2;i <= N;i++)
        dist[i] = INF;

    int a, b, c;

    for (int i = 0;i < M;i++)
    {
        cin >> a >> b >> c;
        city[a].push_back({ b,c });
    }

    BellmanFord(1);
    return 0;

}
