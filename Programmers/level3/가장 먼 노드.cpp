#include <string>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

vector<int> graph[20001];
int dist[20001];

void measure(int start)
{
    priority_queue<pair<int,int>> pq;
    
    pq.push({0,start});
    
    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int d = pq.top().second;
        pq.pop();
        
        for(auto i:graph[d])
        {
            int node = i;
            
            if(dist[node] > 1 + cost)
            {
                dist[node] = 1 + cost;
                pq.push({-(1+cost),node});
            }
        }
    }
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i = 1;i<=n;i++)
        dist[i] = 1e9;
    
    for(auto e:edge)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    dist[1] = 0;
    
    measure(1);
    int count = 0;
    for(int i = 1;i<=n;i++)
    {
        if(dist[i] != 1e9)
        {
            if(answer < dist[i])
            {
                count = 1;
                answer = dist[i];
            }
            else if(answer == dist[i])
                count++;
        }
    }
        
    return count;
}
