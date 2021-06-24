class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    bool ans = false;
    bool visited[6][6];
    int col, row;
    bool exist(vector<vector<char>>& board, string word) {
        col = board.size();
        row = board[0].size();
        
        for(int i = 0;i<col;i++)
        {
            for(int j = 0;j<row;j++)
            {
                memset(visited,false,sizeof(visited));
                visited[i][j] = true;
                string add = "";
                add += board[i][j];
                dfs(board,word,add,i,j);
                
                if(ans)
                    break;
            }
            if(ans)
                break;
        }
        
        return ans;
    }
    
    void dfs(vector<vector<char>>& board,string word,string add, int a,int b)
    {
        if(ans)
            return;
        if(word.length() == add.length())
        {
            if(word == add)
                ans = true;
            return;
        }
        
        for(int i = 0;i<4;i++)
        {
            int c = a + dx[i];
            int d = b + dy[i];
            
            if(c>=0 && c<col && d >= 0 && d< row && !visited[c][d])
            {
                add += board[c][d];
                
                if(add == word.substr(0,add.length()))
                {
                    visited[c][d] = true;
                    dfs(board,word,add,c,d);
                    visited[c][d] = false;
                }
                
                add.pop_back();
            }
        }
    }
};
