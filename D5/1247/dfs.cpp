#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

int home[1][2];
int company[1][2];
int customer[20][2];
bool visited[20];
int dist;
int N;

void dfs(int curr,int temp,int x,int y)
{
    if(curr == N)
    {
        temp += abs(x - home[0][0]) + abs(y-home[0][1]);
        if(dist > temp)
            dist = temp;
        return;
    }
    
    for(int i = 0;i<N;i++)
    {
        if(!visited[i])
        {
            int d = abs(x-customer[i][0]) + abs(y-customer[i][1]);
            visited[i] = true;
            dfs(curr+1,temp+d,customer[i][0],customer[i][1]);
            visited[i] = false;
        }
    }
}
int main(void)
{
    int T;
    cin>>T;
    
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>N;
        memset(visited,false,sizeof(visited));
        dist = 2500;
        cin>>company[0][0]>>company[0][1];
        cin>>home[0][0]>>home[0][1];
        
        for(int i = 0;i<N;i++)
            cin>>customer[i][0]>>customer[i][1];
        
        dfs(0,0,company[0][0],company[0][1]);
        
        cout<<"#"<<test_case<<" "<<dist<<endl;
    }
    return 0;
}
