#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int cost[25][25][4];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int calCost(int dir, int i){
    if((dir == 0 || dir == 1) && (i == 0 || i == 1)){
        return 100;
    }
    else if((dir == 2 || dir == 3) && (i == 2 || i == 3)){
        return 100;
    }
    
    return 600;
}
int solution(vector<vector<int>> board) {
    int i,j;
    int size = board.size();
    
    for(i = 0;i<size;i++){
        for(j = 0;j<size;j++){
            cost[i][j][0] = 1e9;
            cost[i][j][1] = 1e9;
            cost[i][j][2] = 1e9;
            cost[i][j][3] = 1e9;
        }
    }
    
    cost[0][0][1] = 0;
    cost[0][0][2] = 0;
    queue<pair<int,pair<int,int>>> q;
    q.push({1,{0,0}});
    q.push({2,{0,0}});
    
    int dir,x,y;
    int sum,nx,ny;
    
    while(!q.empty()){
        dir = q.front().first;
        x = q.front().second.first;
        y = q.front().second.second;
        
        q.pop();
        
        for(i = 0;i<4;i++){
            nx = x + dx[i];
            ny = y + dy[i];
            
            if(nx >= 0 && nx < size && ny>=0 && ny<size && board[nx][ny] == 0){
                sum = cost[x][y][dir] + calCost(dir,i);
                if(cost[nx][ny][i] >= sum){
                    cost[nx][ny][i] = sum;
                    q.push({i,{nx,ny}});
                }
            }
        }
    }
    
    return min(cost[size-1][size-1][0],min(cost[size-1][size-1][1],min(cost[size-1][size-1][2],cost[size-1][size-1][3])));
}
