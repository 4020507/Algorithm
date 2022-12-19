#include <string>
#include <vector>
#include <string.h>
using namespace std;
bool visited[101];
vector<int> tree[101];
int nodeCnt[101];

void dfs(int p, int curr){
    for(int i = 0;i<tree[curr].size();i++){
        if(!visited[tree[curr][i]]){
            visited[tree[curr][i]] = true;
            nodeCnt[p]++;
            dfs(p,tree[curr][i]);
            visited[tree[curr][i]] = false;
        }
    }
}
int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    int i;
    
    memset(visited,false,sizeof(visited));
    
    for(i = 0;i<wires.size();i++){
        tree[wires[i][0]].push_back(wires[i][1]);
        tree[wires[i][1]].push_back(wires[i][0]);
    }
    
    for(i = 0;i<wires.size();i++){
        visited[wires[i][0]] = true;
        visited[wires[i][1]] = true;
        
        nodeCnt[wires[i][0]] = 1;
        nodeCnt[wires[i][1]] = 1;
        
        dfs(wires[i][0],wires[i][0]);
        dfs(wires[i][1],wires[i][1]);
        
        visited[wires[i][0]] = false;
        visited[wires[i][1]] = false;
        
        answer = min(answer,abs(nodeCnt[wires[i][0]] - nodeCnt[wires[i][1]]));
    }
    
    return answer;
}
