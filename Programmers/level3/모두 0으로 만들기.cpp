#include <string>
#include <vector>
#include <string.h>
using namespace std;

bool visited[300000];
long long answer;
vector<int> connected[300000];
void dfs(vector<long long>& b, int node){
    
    visited[node] = true;
    
    for(int i = 0;i<connected[node].size();i++){
        if(!visited[connected[node][i]]){
            dfs(b, connected[node][i]);
            answer += abs(b[connected[node][i]]);
            b[node] += b[connected[node][i]];
        }
    }
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    answer = 0;
    
    vector<long long> b(a.begin(),a.end());
    memset(visited,false,sizeof(visited));
    
    for(int i = 0;i<edges.size();i++){
        connected[edges[i][0]].push_back(edges[i][1]);
        connected[edges[i][1]].push_back(edges[i][0]);
    }
    
    dfs(b, 0);
    if(b[0] != 0){
        return -1;
    }
    return answer;
}
