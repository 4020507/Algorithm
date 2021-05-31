class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> zero;
        int size1 = matrix.size();
        int size2 = matrix[0].size();
        for(int i = 0;i<size1;i++)
        {
            for(int j = 0;j<size2;j++)
            {
                if(matrix[i][j] == 0)
                {
                    zero.push_back(make_pair(i,j));
                }
            }
        }
        int size = zero.size();
        
        for(int i = 0;i<size;i++)
        {
            int a = zero[i].first;
            int b = zero[i].second;
            
            for(int j = 0;j<size2;j++)
                matrix[a][j] = 0;
            for(int k = 0;k<size1;k++)
                matrix[k][b] = 0;
        }
    }
};
