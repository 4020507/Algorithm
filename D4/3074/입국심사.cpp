#include <iostream>
#include <algorithm>
using namespace std;
long long test[100000];
int N,M;
long long ans;
long long t;
int main(void)
{
    int T;
    cin>>T;
    
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>N>>M;
        ans = 0;
        t = 0;
        for(int i = 0;i<N;i++)
        {
            cin>>test[i];
            if(test[i]>t)
                t = test[i];
        }
        
        long long left = 0;
        long long right = t * M;
        long long mid, sum;
        
        while(left <= right)
        {
            sum = 0;
            mid = (left + right) / 2;
            
            for(int i = 0;i<N;i++)
            {
                sum = sum + mid/test[i];
            }
            if(sum < M)
                left = mid + 1;
            else
            {
                ans = mid;
                right = mid - 1;
            }
        }
        
        cout<<"#"<<test_case<<" "<<ans<<endl;
        
    }
}
