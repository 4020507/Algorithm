#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
        int N,K;
        int time[100][100];
        int move[100][100][100];
        int dp[100][100];
        cin>>K>>N;

        for(int i = 0;i<N-1;i++)
        {
                for(int j = 0;j<K;j++)
                {
                        cin>>time[i][j];
                }
                for(int j = 0;j<K;j++)
                {
                        for(int l = 0;l<K;l++)
                        {
                                if(l != j)
                                {
                                        cin>>move[i][j][l];
                                }
                        }
                }
        }

        for(int i = 0;i<K;i++)
        {
                cin>>time[N-1][i];
        }

        for(int i = 0;i<K;i++)
        {
                dp[0][i] = time[0][i];
        }

        for(int i = 1;i<N;i++)
        {
                for(int j = 0;j<K;j++)
                {
                        dp[i][j] = 10000 * 10000;
                        for(int l = 0;l<K;l++)
                        {
                                dp[i][j] = min(dp[i][j],dp[i-1][l] + move[i-1][l][j] + time[i][j]);
                        }
                }
        }
        int ans = dp[N-1][0];

        for(int i = 1;i<K;i++)
        {
                ans = min(ans,dp[N-1][i]);
        }

        cout<<ans;
 return 0;
}
