#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int T;
    cin>>T;
    
    int jump[10000];
    int N;
    int pick;
    int first,second;
    int out1,out2;
    int maxi;
    int curr;
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>N;
        
        for(int i = 0;i<N;i++)
            cin>>jump[i];
        
        sort(jump,jump+N);
        pick = jump[N-1];
        first = jump[N-2];
        second = jump[N-3];
        if(pick - first > pick - second)
            maxi = pick - first;
        else
            maxi = pick - second;
        
        curr = 4;
        
        if(N%2 == 1)
        {
            while(curr<N)
            {
                out1 = jump[N-curr];
                curr++;
                out2 = jump[N-curr];
                if(first - out1 > second - out2)
                {
                    if(maxi<first-out1)
                        maxi = first - out1;
                }
                else
                {
                    if(maxi<second-out2)
                        maxi = second - out2;
                }
                curr++;
                first = out1;
                second = out2;
            }
        }
        else
        {
            while(curr<N-1)
            {
                out1 = jump[N-curr];
                curr++;
                out2 = jump[N-curr];
                if(first - out1 > second - out2)
                {
                    if(maxi<first-out1)
                        maxi = first - out1;
                }
                else
                {
                    if(maxi<second-out2)
                        maxi = second - out2;
                }
                curr++;
                first = out1;
                second = out2;
            }
            pick = jump[N-curr];
            
            if(first - pick > second - pick)
            {
                if(maxi < first - pick)
                    maxi = first - pick;
            }
            else
            {
                if(maxi < second - pick)
                    maxi = second - pick;
            }
        }
        cout<<"#"<<test_case<<" "<<maxi<<endl;
    }
    
}
