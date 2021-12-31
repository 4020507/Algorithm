#include <iostream>
#include <string.h>
using namespace std;

int board[10][10];
bool removed_blocks[10][10];
int green, blue;
void insert_block(int num, int x, int y)
{
    int i;
    bool check = false;
    if (num == 1)
    {
        //파란색
        for (i = y;i < 10;i++)
        {
            if (board[x][i] == 1)
            {
                board[x][i-1] = 1;
                check = true;
                break;
            }
        }
        if (!check)
            board[x][9] = 1;
        check = false;
        //초록색
        for (i = x;i < 10;i++)
        {
            if (board[i][y] == 1)
            {
                board[i-1][y] = 1;
                check = true;
                break;
            }
        }

        if (!check)
            board[9][y] = 1;
    }
    else if (num == 2)
    {
        for (i = y;i < 10;i++)
        {
            if (board[x][i] == 1)
            {
                board[x][i-1] = 1;
                board[x][i - 2] = 1;
                check = true;
                break;
            }
        }

        if (!check)
        {
            board[x][9] = 1;
            board[x][8] = 1;
        }
        check = false;
        for (i = x;i < 10;i++)
        {
            if (board[i][y] == 1 || board[i][y + 1] == 1)
            {
                board[i-1][y] = 1;
                board[i-1][y + 1] = 1;
                check = true;
                break;
            }
        }

        if (!check)
        {
            board[9][y] = 1;
            board[9][y + 1] = 1;
        }
    }
    else if (num == 3)
    {
        for (i = y;i < 10;i++)
        {
            if (board[x][i] == 1 || board[x+1][i] == 1)
            {
                board[x][i-1] = 1;
                board[x+1][i-1] = 1;
                check = true;
                break;
            }
        }

        if (!check)
        {
            board[x][9] = 1;
            board[x + 1][9] = 1;
        }
        check = false;
        for (i = x;i < 10;i++)
        {
            if (board[i][y] == 1)
            {
                board[i-1][y] = 1;
                board[i-2][y] = 1;
                check = true;
                break;
            }
        }
        if (!check)
        {
            board[9][y] = 1;
            board[8][y] = 1;
            
        }
    }
}

int IsRemove()
{
    memset(removed_blocks, false, sizeof(removed_blocks));
    int check = 0;

    //열
    for (int i = 6;i < 10;i++)
    {
        if (board[0][i] == 1 && board[1][i] == 1 && board[2][i] == 1 && board[3][i] == 1)
        {
            removed_blocks[0][i] = true;
            removed_blocks[1][i] = true;
            removed_blocks[2][i] = true;
            removed_blocks[3][i] = true;
            check++;
        }
    }


    for (int i = 6;i < 10;i++)
    {
        if (board[i][0] == 1 && board[i][1] == 1 && board[i][2] == 1 && board[i][3] == 1)
        {
            removed_blocks[i][0] = true;
            removed_blocks[i][1] = true;
            removed_blocks[i][2] = true;
            removed_blocks[i][3] = true;
            check++;
        }
    }

    return check;
}

void arrangeBlocks()
{
    int cnt = 0;

    //진한 색 처리
    for (int i = 9;i >4;i--)
    {
        if (removed_blocks[0][i])
        {
            for (int x = 0;x < 4;x++)
            {
                for (int y = i;y>4;y--)
                {
                    removed_blocks[x][y] = removed_blocks[x][y - 1];
                    board[x][y] = board[x][y - 1];
                }
            }
            i++;
        }
    }

    for (int i = 9;i > 4;i--)
    {
        if (removed_blocks[i][0])
        {
            for (int x = i;x > 4;x--)
            {
                for (int y = 0;y < 4;y++)
                {
                    removed_blocks[x][y] = removed_blocks[x-1][y];
                    board[x][y] = board[x-1][y];
                }
            }
            i++;
        }
    }

    for (int j = 4;j < 6;j++)
    {
        for (int i = 0;i < 4;i++)
        {
            if (board[i][j] == 1)
            {
                blue++;
                break;
            }
        }
    }

    for (int i = 4;i < 6;i++)
    {
        for (int j = 0;j < 4;j++)
        {
            if (board[i][j] == 1)
            {
                green++;
                break;
            }
        }
    }

    if (blue > 0)
    {
        //연한 색 정리
        for (int i = 0;i < 4;i++)
        {
            for (int j = 9;j >= 6;j--)
            {
                board[i][j] = board[i][j - blue];
            }
        }

        for (int i = 0;i < 4;i++)
        {
            for (int j = 4;j < 6;j++)
            {
                board[i][j] = 0;
            }
        }
    }
    
    if (green > 0)
    {
        for (int i = 9;i >= 6;i--)
        {
            for (int j = 0;j < 4;j++)
            {
                board[i][j] = board[i-green][j];
            }
        }

        for (int i = 4;i < 6;i++)
        {
            for (int j = 0;j < 4;j++)
            {
                board[i][j] = 0;
            }
        }
    }
    
}

int main() {
    int N;
    cin >> N;

    int num;//1 -> (x,y), 2->(x,y)(x,y+1), 3->(x,y)(x+1,y)
    int x, y;
    int cnt = 0;
    int removed = 0;

    memset(board, 0, sizeof(board));

    for (int t = 0;t < N;t++)
    {
        cin >> num >> x >> y;

        insert_block(num,x,y);
        green = 0;
        blue = 0;
        removed += IsRemove();
        arrangeBlocks();
    }
    
    for (int i = 0;i < 4;i++)
    {
        for (int j = 6;j < 10;j++)
        {
            if (board[i][j] == 1)
                cnt++;
        }
    }

    for (int i = 6;i < 10;i++)
    {
        for (int j = 0;j < 4;j++)
        {
            if (board[i][j] == 1)
                cnt++;
        }
    }

    cout << removed << '\n' << cnt;

    return 0;
}
