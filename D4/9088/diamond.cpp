#include<iostream>
#include<algorithm>
using namespace std;

int main(void)
{
    int T;
    cin>>T;
    
    int diamond[10000];
    int K,N,start,count,ans;
    
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>N>>K;
        
        for(int i = 0;i<N;i++)
            cin>>diamond[i];
        sort(diamond,diamond+N);
        
        start = 0;
        ans = 0;
        count = 1;
        for(int i = 1;i<N;i++)
        {
            if(diamond[i] - diamond[start] <= K)
            {
                count++;
                if(count>ans)
                    ans = count;
            }
            else
            {
                while(diamond[i] - diamond[start] > K)
                {
                    start++;
                }
                count = i - start + 1;
            }
        }
        cout<<"#"<<test_case<<" "<<ans<<endl;
    }
}
