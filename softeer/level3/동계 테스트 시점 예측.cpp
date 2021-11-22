#include<iostream>
#include<cstring>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int N,M;
int island[100][100];
int visited[100][100];
int ans;

void dfs(int x, int y)
{
        visited[x][y] = 1;

        for(int i = 0;i<4;i++)
        {
                int a = x + dx[i];
                int b= y + dy[i];

                if(a>=0 && a<N && b>=0 && b<M)
                {
                        if(island[a][b] == 0 && !visited[a][b]) dfs(a,b);
                        else
                                visited[a][b]++;
                }
        }
}
bool finish()
{
        for(int i = 0;i<N;i++)
                for(int j = 0;j<M;j++)
                        if(island[i][j] == 1)
                                return false;
        
        return true;
}
int main(int argc, char** argv)
{
        

        cin>>N>>M;
        memset(visited,0,sizeof(visited));
        int ans = 0;
        for(int i = 0;i<N;i++)
        {
                for(int j = 0;j<M;j++)
                {
                        cin>>island[i][j];
                }
        }
        
        while(!finish())
        {
                memset(visited,0,sizeof(visited));
                dfs(0,0);
                for(int i = 0;i<N;i++)
                {
                        for(int j = 0;j<M;j++)
                        {
                                if(island[i][j] == 1 && visited[i][j]>1)
                                {
                                        island[i][j] = 0;
                                }
                        }
                }
                ans++;
        }

        cout<<ans;
 return 0;
}
