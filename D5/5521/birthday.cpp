#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int main(void)
{
    int T;
    cin>>T;
    
    int N,M;
    bool visited[501];
    int a,b,size,invite,k;
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>N>>M;
        vector<int> v[501];
        invite = -1;
        memset(visited,false,sizeof(visited));
        
        for(int i = 0;i<M;i++)
        {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        queue<pair<int,int>> q;
        q.push(make_pair(1,0));
        visited[1] = true;
        while(!q.empty())
        {
            a = q.front().first;
            b = q.front().second;
            q.pop();
            if(b > 2)
                continue;
            
            size = v[a].size();
            invite++;
            for(int i = 0;i<size;i++)
            {
                k = v[a][i];
                if(!visited[k]){
                    visited[k] = true;
                	q.push(make_pair(k,b+1));
                }
            }
        }
        
        cout<<"#"<<test_case<<" "<<invite<<endl;
    }
}
