#include <iostream>
#include <math.h>
using namespace std;
long long save[1000000];

void init()
{
    long long i =2;
    int count = 0;
    while(i<=1000000)
    {
        save[i] = i*i;
        i++;
    }
}
int main(void)
{
    int T;
    cin>>T;
    long long a,count;
    long long temp;

    init();
    for(int test_case = 1;test_case<=T;test_case++)
    {
        cin>>a;
        count = 0;
        
        while(a > 2)
        {
            temp = sqrt(a);
            if(temp * temp == a)
            {
                a = temp;
                count++;
            }
            else
            {
                count += save[temp+1] - a;
                a = save[temp+1];
            }
        }
        cout<<"#"<<test_case<<" "<<count<<endl;
    }
}
