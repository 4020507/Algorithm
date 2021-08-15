class Solution {
public:
    int rows;
    int cols;
    vector<vector<int>> v;
    
    int dfs(vector<vector<int>>& matrix,int r, int c)
    {
        if(v[r][c] > 0)
            return v[r][c];
        
        int res = 1;
        
        if(r + 1 < rows && matrix[r][c] < matrix[r+1][c])
            res = max(res,1 + dfs(matrix,r+1,c));
        if(r -1 >=0 && matrix[r][c] < matrix[r-1][c])
            res = max(res, 1 + dfs(matrix,r-1,c));
        if(c + 1 < cols && matrix[r][c+1] > matrix[r][c])
            res = max(res, 1 + dfs(matrix,r,c+1));
        if(c -1 >= 0 && matrix[r][c] < matrix[r][c-1])
            res = max(res, 1 + dfs(matrix,r,c-1));
        
        v[r][c] = res;
        
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        rows = matrix.size();
        cols = matrix[0].size();
        
        v = vector<vector<int>>(rows,vector<int>(cols,0));
        
        int ans = 0;
        
        for(int i = 0;i<rows;i++)
        {
            for(int j = 0;j<cols;j++)
                ans = max(ans,dfs(matrix,i,j));
        }
        
        return ans;
        
    }
};
