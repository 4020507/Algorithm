#include <iostream>

using namespace std;

int main(void)
{
    int T;
    cin>>T;
    int mountain[50000];
    int N;
    int ans;
    int curr,up,down;
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>N;
        for(int i = 0;i<N;i++)
            cin>>mountain[i];

        curr = mountain[0];
        bool check = false;
        up = 0;
        down = 0;
        ans = 0;
        for(int i = 1;i<N;i++)
        {
           if(mountain[i] > curr && down == 0)
           {
               curr = mountain[i];
               up++;
           }
           else if(mountain[i] < curr && up != 0)
           {
               curr = mountain[i];
               down++;
           }
            else if(mountain[i] > curr && down != 0)
            {
                curr = mountain[i-1];
                ans = ans + up * down;
                up = 0;
                down = 0;
                i--;
            }
            else if(mountain[i] < curr && up == 0)
            {
                curr = mountain[i];
                down = 0;
            }
            
        }
        if(up !=0 && down != 0)
            ans = ans + up * down;
        cout<<"#"<<test_case<<" "<<ans<<endl;
    }
}
