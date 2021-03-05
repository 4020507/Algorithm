#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(void)
{
    int T;
    cin>>T;
    int croak[4];
    string sound;
    bool possible;
    int count = 0;
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>sound;
        memset(croak,0,sizeof(croak));
        possible = true;
        count = 0;
        for(int i = 0;i<sound.length();i++)
        {
            if(sound[i] == 'c')
            {
                croak[0]++;
            }
            else if(sound[i] == 'r')
            {
                croak[0]--;
                if(croak[0] < 0)
                {
                    possible = false;
                    break;
                }
                croak[1]++;
            }
            else if(sound[i] == 'o')
            {
                croak[1]--;
                 if(croak[1] < 0)
                {
                    possible = false;
                    break;
                }
                croak[2]++;
            }
            else if(sound[i] == 'a')
            {
                croak[2]--;
                 if(croak[2] < 0)
                {
                    possible = false;
                    break;
                }
                croak[3]++;
            }
            else if(sound[i] == 'k')
            {
                croak[3]--;
                 if(croak[3] < 0)
                {
                    possible = false;
                    break;
                }
            }
            count = max(count,croak[0]+croak[1]+croak[2]+croak[3]);
        }
        if(croak[0] != 0 || croak[1] != 0 || croak[2] != 0 || croak[3] != 0)
            possible = false;
        cout<<"#"<<test_case<<" ";
       	if(!possible)
            cout<<"-1"<<endl;
        else
            cout<<count<<endl;
    }
    return 0;
}
