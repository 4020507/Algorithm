#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
        int N;
        cin>>N;

        int stones[3000];

        for(int i = 0;i<N;i++)
        {
                cin>>stones[i];
        }
        int dp[3000];

        for(int i = 0;i<N;i++)
        {
                dp[i] = 1;
                for(int j = 0;j<i;j++)
                {
                         if(stones[j]<stones[i])
                        {
                                 dp[i] = max(dp[j]+1,dp[i]);
                        }  
                }
        }
      sort(dp,dp+N);

       cout<<dp[N-1];

        return 0;
}
