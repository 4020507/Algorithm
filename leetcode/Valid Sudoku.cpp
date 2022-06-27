class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int column[9][9] = {0};
        int sub[9][9] = {0};
        int num , k;
        for(int i = 0;i<9;i++)
        {
            for(int j = 0;j<9;j++)
            {
                if(board[i][j] != '.')
                {
                    num = board[i][j] - '0' - 1;
                    k = i/3 * 3 + j/3;
                    if(row[i][num] || column[j][num] || sub[k][num])
                    {
                        return false;
                    }
                    row[i][num] = column[j][num] = sub[k][num] = 1;
                }
            }
        }
        
        return true;
    }
};
