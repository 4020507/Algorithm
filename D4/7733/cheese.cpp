#include <iostream>
#include <cstring>

using namespace std;

int map[100][100];
bool visited[100][100];
int N;
int ans;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(int col,int row)
{    
    for(int i = 0;i<4;i++)
    {
        int a = col + dx[i];
        int b = row + dy[i];
        
        if(a>=0 && a<N && b>=0 && b<N && !visited[a][b])
        {
            visited[a][b] = true;
            dfs(a,b);
        }
    }
}
int main(void)
{
    int T;
    cin>>T;
    int count;
    int maxi;
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>N;
        maxi = 0;
        for(int i = 0;i<N;i++)
            for(int j = 0;j<N;j++){
                cin>>map[i][j];
                if(maxi < map[i][j])
                    maxi = map[i][j];
            }
        ans = 1;
        
        for(int k = 1;k<maxi;k++)
        {
            count = 0;
            memset(visited,false,sizeof(visited));
            for(int i = 0;i<N;i++)
            {
                for(int j = 0;j<N;j++)
                {
                    if(map[i][j] <= k)
                        visited[i][j] = true;
                }
            }
            
            for(int i = 0;i<N;i++)
            {
                for(int j = 0;j<N;j++)
                {
                    if(!visited[i][j]){
                        visited[i][j] = true;
                        dfs(i,j);
                        count++;
                    }
                }
            }
            
            if(ans<count)
                ans = count;
        }
        
        cout<<"#"<<test_case<<" "<<ans<<endl;
    }
}
