#include <iostream>
#include <cstring>
using namespace std;
char map[20][20];
bool visited[26];
int ans;
int R,C;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(int i, int j, int temp)
{
    if(temp>ans)
        ans = temp;
    
   for(int k = 0;k<4;k++)
   {
       int a = i + dx[k];
       int b = j + dy[k];
       
       if(a>=0 && a < R && b >= 0 && b<C && !visited[map[a][b]-'A'])
       {
           visited[map[a][b]-'A'] = true;
           dfs(a,b,temp+1);
           visited[map[a][b]-'A'] = false;
       }
   }
}
int main(void)
{
    int T;
    cin>>T;
    
    
    
    for(int test_case = 1; test_case<=T;test_case++)
    {
        cin>>R>>C;
        memset(visited,false,sizeof(visited));
        ans = 0;
        for(int i = 0;i<R;i++)
            for(int j = 0;j<C;j++)
                cin>>map[i][j];
        visited[map[0][0] - 'A'] = true;
        dfs(0,0,1);
        
        cout<<"#"<<test_case<<" "<<ans<<endl;
    }
    return 0;
}
