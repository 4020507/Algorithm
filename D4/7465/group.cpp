#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N,M;
int ans;
bool visited[101];
void dfs(int curr,vector <int> v[])
{
    for(int i = 0;i<v[curr].size();i++)
    {
        
        if(!visited[v[curr][i]])
        {  
            visited[v[curr][i]] = true;
            dfs(v[curr][i],v);
        }
    }
}
int main(void)
{
    int T;
    cin>>T;
    
    
    int p1,p2;
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>N>>M;
        vector <int> v[101];
        ans = 0;
        for(int i = 0;i<M;i++)
        {
            cin>>p1>>p2;
            v[p1].push_back(p2);
            v[p2].push_back(p1);
        }
        
        memset(visited,false,sizeof(visited));
        for(int i = 1;i<=N;i++)
        {
            if(!visited[i])
            {
                dfs(i,v);
                ans++;
            }
        }
        cout<<"#"<<test_case<<" "<<ans<<endl;
    }
}
