#include <string>
#include <vector>
#include <string.h>
using namespace std;

int ans;
bool visited[8];
void dfs(int cnt, vector<vector<int>>& dungeons, int k){
    
    ans = max(ans,cnt);
    
    for(int i = 0;i<dungeons.size();i++){
        if(k >= dungeons[i][0] && !visited[i]){
            visited[i] = true;
            dfs(cnt+1,dungeons,k-dungeons[i][1]);
            visited[i] = false;
        }
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    
    ans = 0;
    memset(visited,false,sizeof(visited));
    
    dfs(0,dungeons,k);
    
    return ans;
}
