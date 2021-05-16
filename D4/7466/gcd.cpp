#include <iostream>

using namespace std;

long long N,K;

int main(void)
{
    int T;
    cin>>T;
    
   	long long result = 1;
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>N>>K;
        result = 1;
        if(N < K)
        {
            for(long long i = N; i>1;i--)
            {
                if(K%i == 0)
                {
                    result *= i;
                    K /= i;
                }
            }
        }
        else
        {
            result = K;
        }
        cout<<"#"<<test_case<<" "<<result<<endl;
    }
}
