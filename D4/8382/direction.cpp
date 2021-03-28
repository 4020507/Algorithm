#include<iostream>
#include <cstring>
using namespace std;

int ans;
void dfs(int a, int b, int c, int d,int count,int prev)
{
    if(a == c && b == d)
    {
        if(ans>count)
            ans = count;
        return;
    }
    
    if(count > ans)
        return;
    
    if(prev == 0)
    {
        if(a<c)
        	dfs(a+1,b,c,d,count+1,1);
        else
        	dfs(a-1,b,c,d,count+1,1);
    }
    else if(prev == 1)
    {
        if(b<d)
        	dfs(a,b+1,c,d,count+1,0);
        else
        	dfs(a,b-1,c,d,count+1,0);
    }
}
int main(void)
{
    int T;
    cin>>T;
    
    int a,b,c,d;

    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>a>>b>>c>>d;
        
        ans = 100 * 100 * 100 * 100;
        dfs(a,b,c,d,0,0);
        dfs(a,b,c,d,0,1);
        
        cout<<"#"<<test_case<<" "<<ans<<endl;
    }
}
