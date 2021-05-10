#include <iostream>
#include <cstring>
using namespace std;

bool visited[20][20][16][4];
char map[20][20];
char c;
int R,C;
int letter;
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};
int arrow;
bool possible;
void dfs(int x, int y)
{
    if(possible)
        return;
    if(visited[x][y][letter][arrow])
        return;

    visited[x][y][letter][arrow] = true;
    int a,b;

    if(map[x][y] == '?')
    {
        for(int i = 0;i<4;i++)
        {
            a = x + dx[i];
            b = y + dy[i];
            
            if(a == -1)
            	a = R-1;
            else if(a == R)
                a = 0;
            if(b == -1)
                b = C-1;
            else if(b == C)
                b = 0;
            arrow = i;
            dfs(a,b);
        }
    }
    else
    {
        if(map[x][y] == '<')
        {
            arrow = 0;
        }
        else if(map[x][y] == '>')
        {
            arrow = 1;
        }
        else if(map[x][y] == '^')
        {
            arrow = 2;
        }
        else if(map[x][y] == 'v')
        {
            arrow = 3;
        }
        else if(map[x][y] == '_')
        {
            letter == 0 ? arrow = 1 : arrow = 0;
        }
        else if(map[x][y] == '|')
        {
            letter == 0 ? arrow = 3 : arrow = 2;
        }
        else if(map[x][y] == '@')
        {
            possible = true;
            return;
        }
        else if(map[x][y] >= '0' && map[x][y] <= '9')
        {
            letter = map[x][y] - '0';
        }
        else if(map[x][y] == '+')
        {
            letter == 15 ?letter =  0: letter = letter + 1;
        }
        else if(map[x][y] == '-')
        {
            letter == 0 ? letter = 15: letter = letter - 1;
        }
        
        a = x + dx[arrow];
        b = y + dy[arrow];
        
        if(a == -1)
            a = R-1;
        else if(a == R)
            a = 0;
        if(b == -1)
            b = C-1;
        else if(b == C)
            b = 0;

        dfs(a,b);
    }

}
int main(void)
{
    int T;
    cin>>T;
    
    for(int test_case = 1;test_case<=T; test_case++)
    {
        cin>>R>>C;
        
        for(int i = 0;i<R;i++)
            for(int j = 0;j<C;j++)
                cin>>map[i][j];
        
        letter = 0;
        memset(visited,false,sizeof(visited));

        arrow = 1;
        possible = false;
        dfs(0,0);
        
        cout<<"#"<<test_case<<" ";
        if(!possible)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
}
