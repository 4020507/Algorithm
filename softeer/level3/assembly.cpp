#include<iostream>
#include<algorithm>
using namespace std;


int main(int argc, char** argv)
{ 
        int N;
        int work[1000][2];
        int move[1000][2];
        int A,B;

       cin>>N;

        for(int i = 0;i<N-1;i++)
        {
                cin>>work[i][0]>>work[i][1]>>move[i][0]>>move[i][1];
        }
        cin>>work[N-1][0]>>work[N-1][1];

        int dp[1000][2];

        dp[0][0] = work[0][0];
        dp[0][1] = work[0][1];

        for(int i = 1;i<N;i++)
        {
                dp[i][0] = min(dp[i-1][0],dp[i-1][1] + move[i-1][1]) + work[i][0];
                dp[i][1] = min(dp[i-1][1],dp[i-1][0] + move[i-1][0]) + work[i][1];
        }
        cout<<min(dp[N-1][0],dp[N-1][1])<<endl;
        return 0;
}
