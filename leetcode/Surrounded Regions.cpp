class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    int m,n;
    bool visited[200][200];
    
    void bfs(int x,int y,vector<vector<char>>& board)
    {
        queue<pair<int,int>> q;
         memset(visited,false,sizeof(visited));
        q.push({x,y});
        vector<pair<int,int>> v;
        v.push_back({x,y});
        visited[x][y] = true;
        while(!q.empty())
        {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            
            for(int i = 0;i<4;i++)
            {
                int c = a + dx[i];
                int d = b + dy[i];
                
                if(c>=0 && c<m && d>=0 && d<n)
                {
                    if(!visited[c][d])
                    {
                        if(board[c][d] == 'X')
                        {
                            visited[c][d] = true;
                            continue;
                        }
                        if(c==0 || c == m-1 || d == 0 || d == n-1)
                        {
                            return;
                        }
                        
                        visited[c][d] = true;
                        
                        if(board[c][d] == 'O')
                        {
                            q.push({c,d});
                            v.push_back({c,d});
                        }
                        
                    }
                }
            }
        }
        
        for(auto i:v)
        {
            board[i.first][i.second] = 'X';
        }
    }
    void solve(vector<vector<char>>& board) {
        
        m = board.size();
        n = board[0].size();
        
        for(int i = 1;i<m-1;i++)
        {
            for(int j = 1;j<n-1;j++)
            {
                if(board[i][j] == 'O')
                    bfs(i,j,board);
            }
        }
    }
};
