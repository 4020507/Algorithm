class Solution {
public:
    int m,n;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] == '1')
                {
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        
        return ans;
    }
    
    void dfs(int x, int y, vector<vector<char>>& grid)
    {
        int a,b;
        grid[x][y] = 0;
        for(int i = 0;i<4;i++)
        {
            a = x + dx[i];
            b = y + dy[i];
            
            if(a>=0 && a<m && b>=0 && b<n && grid[a][b] == '1')
            {
                dfs(a,b,grid);
            }
        }
    }
};
