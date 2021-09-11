#include<iostream>

using namespace std;
int num[100000];
int N;

int check(int idx)
{
    if(num[idx] < num[idx+1])
        return 0;
    if(num[idx] > num[idx+1])
        return 1;
    return 2;
}
int main(void)
{
    int T;
    cin>>T;
    int increase;
    int ans;
    for(int test_case = 1;test_case<=T; test_case++)
    {
        cin>>N;
        ans = 1;
        for(int i = 0;i<N;i++)
        {
            cin>>num[i];
        }
        increase = check(0);
        
        for(int i = 1;i<N-1;i++)
        {
            if(increase == 2)
                increase = check(i);
            else if(num[i]<num[i+1])
            {
                if(increase != 0)
                {
                    ans++;
                    i++;
                    increase = check(i);
                }
            }
            else if(num[i]>num[i+1])
            {
                if(increase != 1)
                {
                    ans++;
                    i++;
                    increase = check(i);
                }
            }
        }
        
        cout<<"#"<<test_case<<" "<<ans<<endl;
    }
}
