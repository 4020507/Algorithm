#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector <pair<int,pair<int,int>>> Tour;
int tim[36][36];

bool visited[36];
int N,M;
int airport;
int ans;
vector<int> route;
vector<int> hotel;

void dfs(int start, int day, int sat, int t, int depth,vector<int>& v)
{
    if(start == airport && day == M && depth !=0)
    {
        if(sat>ans){
            ans = sat;
            route = v;
        }
        return;
    }
    bool check = false;
    for(int i = 0;i<Tour.size();i++)
    {
        int next = Tour[i].first;
        int play = Tour[i].second.first;
        int satisfy = Tour[i].second.second;
        int move = tim[start][next];
        
        if(visited[next] == true || start == next)
            continue;
        if(t + move +play > 540)
            continue;
        check = true;
        visited[next] = true;
        v.push_back(next);
        dfs(next,day,sat+satisfy,t + move +play,depth+1,v);
        v.pop_back();
        visited[next] = false;
        
    }
    
    if(!check)
    {
        if(day == M)
        {
            if(t + tim[start][airport] <= 540)
            {
                v.push_back(airport);
                dfs(airport,day,sat,t + tim[start][airport],depth+1,v);
                v.pop_back();
            }
        }
        else{
            for(int i = 0;i<hotel.size();i++)
            {
                int num = hotel[i];
                if(t + tim[start][num] <= 540)
                {
                    v.push_back(num);
                    dfs(num,day + 1,sat,0,depth+1,v);
                    v.pop_back();
                }
            }
        }
        
    }
}
int main(void)
{
    int T;
    cin>>T;
    
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>N>>M;
        
        memset(visited,false,sizeof(visited));
        hotel.clear();
        route.clear();
        Tour.clear();
        ans = 0;
        for(int i = 1;i<=N-1;i++)
        {
            for(int j = i+1;j<=N;j++){
                int t;
                cin>>t;
            	tim[i][j] = t;
                tim[j][i] = t;
            }
        }
        
        for(int i = 1;i<=N;i++)
        {
            char c;
            cin>>c;
            if(c == 'P'){
                int a,b;
                cin>>a>>b;
               Tour.push_back(make_pair(i,make_pair(a,b)));
            }
            else if(c == 'A')
                airport = i;
            else
                hotel.push_back(i);
        }
        
        vector<int> v;
        dfs(airport,1,0,0,0,v);
        
        cout<<"#"<<test_case<<" ";
        cout<<ans<<" ";
        if(ans !=0)
        {
            for(int i = 0;i<route.size();i++)
            {
                cout<<route[i]<<" ";
            }
        }
        cout<<endl;
    }
}
