#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
bool worst[21][21];
int N,M,ans;
bool visited[21];
vector<int>v;
void dfs(int idx)
{
    int size;
    bool check;
	ans++;
    for(int i = idx;i<=N;i++)
    {
        if(visited[i])
            continue;
        size = v.size();
        check = true;
        for(int j = 0;j<size;j++)
        {
            if(worst[i][v[j]])
            {
                check = false;
                break;
            }
        }
        if(!check)
            continue;
        v.push_back(i);
        visited[i] = true;
        dfs(i);
        v.pop_back();
        visited[i] = false;
    }
}
int main(void)
{
    int T;
    cin>>T;
    
    int a,b;
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>N>>M;
        memset(worst,0,sizeof(worst));
        memset(visited,0,sizeof(visited));
        v.clear();
        for(int i = 0;i<M;i++)
        {
            cin>>a>>b;
            worst[a][b] = true;
            worst[b][a] = true;
        }
        ans = 0;
       	dfs(1);
        cout<<"#"<<test_case<<" "<<ans<<endl;
    }
}
