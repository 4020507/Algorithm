#include <iostream>
#include <cstring>

using namespace std;

int height[20];
int N;
int H;
int ans;
void dfs(int curr,int temp)
{
    if(curr == N || temp>=H)
    {
        if(temp>=H)
            if(temp<ans)
                ans = temp;
        return;
    }
    dfs(curr+1,temp + height[curr]);
    dfs(curr+1,temp);
}
int main(void)
{
    int T;
    cin>>T;
    
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>N>>H;
        
        for(int i = 0;i<N;i++)
            cin>>height[i];
        ans = H * 20;
        dfs(0,0);

        cout<<"#"<<test_case<<" "<<ans - H<<endl;
    }
}
