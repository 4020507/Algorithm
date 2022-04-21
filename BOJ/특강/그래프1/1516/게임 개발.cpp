#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

#define MAX 500
#define INF 1e9

int indegree[MAX + 1];
vector<int> building[MAX + 1];
int taken[MAX + 1];
int total[MAX + 1];
int N;

void topology()
{
    queue<int> q;

    for (int i = 1;i <= N;i++)
    {
        if (indegree[i] == 0) {
            q.push(i);
            total[i] = taken[i];
        }
    }

    int a, b;
    while (!q.empty())
    {
        a = q.front();
        q.pop();

        for (int i = 0;i < building[a].size();i++)
        {
            b = building[a][i];

            indegree[b]--;

            if (indegree[b] == 0) {
;               q.push(b);
            }
            total[b] = max(total[b], total[a] + taken[b]);
        }
    }

}
int main(void)
{
    std::ios::sync_with_stdio(false);

    cin >> N;
    int t, need;
    for (int i = 1;i <= N;i++)
    {
        cin >> t;
        need = 0;
        taken[i] = t;
        while (1)
        {
            cin >> need;

            if (need == -1)
                break;
            else {
                building[need].push_back(i);
                indegree[i]++;
            }
        }
    }

    topology();

    for (int i = 1;i <= N;i++)
        cout << total[i] << endl;

    return 0;

}
