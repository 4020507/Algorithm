class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int dx[8] = {-1,-1,-1,1,1,1,0,0};
        int dy[8] = {0,-1,1,0,-1,1,-1,1};
        
        int m = board.size();
        int n = board[0].size();
        int a,b;
        int one,zero;
        int next[25][25];
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                one = 0;
                zero = 0;
                for(int k = 0;k<8;k++)
                {
                    a = i + dx[k];
                    b = j + dy[k];
                    
                    if(a>=0 && a<m && b>=0 && b<n)
                    {
                        if(board[a][b] == 0)
                            zero++;
                        else
                            one++;
                    }
                }
                if(one <= 1 && board[i][j] == 1)
                {
                    next[i][j] = 0;
                }
                else if(one>=4 && board[i][j] == 1)
                {
                    next[i][j] = 0;
                }
                else if((one == 2 || one == 3) && board[i][j] == 1)
                {
                    next[i][j] = 1;
                }
                else if(one == 3 && board[i][j] == 0)
                {
                    next[i][j] = 1;
                }
                else
                {
                    next[i][j] = board[i][j];
                }
            }
        }
        
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++)
                board[i][j] = next[i][j];
    }
};
