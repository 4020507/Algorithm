#include<vector>
#include<string.h>
#include<queue>
using namespace std;

int bfs(vector<vector<int>>& maps,int n, int m){
    queue<pair<pair<int,int>,int>> q;
    bool visited[100][100];
    int x,y,nx,ny,dist;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    memset(visited,false,sizeof(visited));
    q.push({{0,0},1});
    visited[0][0] = true;
    
    int i;
    
    while(!q.empty()){
        x = q.front().first.first;
        y = q.front().first.second;
        dist = q.front().second;
        q.pop();
        
        if(x == n && y == m){
            return dist;
        }
        
        for(i = 0;i<4;i++){
            nx = x + dx[i];
            ny = y + dy[i];
            
            if(nx >= 0 && nx <= n && ny>= 0 && ny <= m){
                if(!visited[nx][ny] && maps[nx][ny] == 1){
                    visited[nx][ny] = true;
                    q.push({{nx,ny},dist+1});
                }
            }
        }
    }
    
    
    return -1;
}

int solution(vector<vector<int> > maps)
{
    return bfs(maps,maps.size()-1,maps[0].size()-1);
}
