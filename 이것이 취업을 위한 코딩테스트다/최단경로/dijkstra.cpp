#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<queue>
#define INF 1e9

using namespace std;

int N, M, start;

vector<pair<int, int>> graph[10001];
int table[10001];

//음수 cost가 존재하는 경우 사용 불가
void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;

    pq.push(make_pair(0,start));
    table[start] = 0;
    
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if (table[node] < cost)
            continue;

        for (int i = 0;i < graph[node].size();i++)
        {
            int distance = graph[node][i].second + cost;
            if (distance < table[graph[node][i].first])
            {
                table[graph[node][i].first] = distance;
                pq.push(make_pair(-distance, graph[node][i].first));
            }
        }
    }
}
int main(void) {
    
    //노드 수, 간선 수, 시작 노드
    cin >> N >> M >> start;

    for (int i = 0;i < M;i++)
    {
        int a, b, c;

        //a -> b 까지 가는데 c만큼의 비용이 필요
        cin >> a >> b >> c;

        graph[a].push_back(make_pair(b, c));
    }

    fill(table, table + 10001, INF);

    dijkstra(start);

    for (int i = 1;i <= N;i++)
    {
        if (table[i] == INF)
        {
            cout << INF << endl;
        }
        else
        {
            cout << table[i] << endl;
        }
    }
}
