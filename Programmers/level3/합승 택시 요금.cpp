#include <string>
#include <vector>
#include <queue>
#include<iostream>
using namespace std;

vector<pair<int,int>> node[201];
int dist[3][201];

void dijkstra(int num, int s, int n){
    int i;
    
    for(i = 1;i<=n;i++){
        dist[num][i] = 1e9;
    }
    
    dist[num][s] = 0;
    
    queue<pair<int,int>> q;
    q.push({0,s});
    int d,curr,next,sum;
    
    while(!q.empty()){
        d = q.front().first;
        curr = q.front().second;
        q.pop();
        
        if(d > dist[num][curr]){
            continue;
        }
        
        for(i = 0;i<node[curr].size();i++){
            next = node[curr][i].first;
            sum = d + node[curr][i].second;
            
            if(dist[num][next] > sum){
                dist[num][next] = sum;
                q.push({sum,next});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 1e9;
    int i;
    
    for(i = 0;i<fares.size();i++){
        node[fares[i][0]].push_back({fares[i][1],fares[i][2]});
        node[fares[i][1]].push_back({fares[i][0],fares[i][2]});
    }
    
    dijkstra(0,s,n);
    dijkstra(1,a,n);
    dijkstra(2,b,n);
    
    for(i = 1;i<=n;i++){
        if(dist[0][i] == 1e9 || dist[1][i] == 1e9 || dist[2][i] == 1e9){
            continue;
        }
        
        answer = min(answer,dist[0][i] + dist[1][i] + dist[2][i]);
    }
    return answer;
}
